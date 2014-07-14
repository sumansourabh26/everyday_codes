<?php
	use Monolog\Handler\error_log;
class Audit{
		var $audit_id;
		/* var $details;
		var $key_info;
		var $bug_info; */
		var $info;		
		var $p1_count;
		var $p2_count;
		var $p3_count;
		function __construct($user_id, $audit_date_time, $app_name, $app_size_in_mb, $app_absolute_location, $audit_status, $isNew){
			
			if($isNew===true){
				mysql_query("INSERT INTO `audit_details`(`user_id`, `audit_date_time`, `app_name`, `app_size_in_mb`,`app_absolute_location`, `audit_status`) 
				VALUES ('$user_id','$audit_date_time','$app_name','$app_size_in_mb','$app_absolute_location','$audit_status')")
							or die("error in constructor of audit_id" . mysql_error());
				$this->audit_id = mysql_insert_id();
				$this->info['audit_id'] = $this->audit_id;
				$this->fetchInfo();
				error_log("new Audit created");
			} 
			else{
				$this->audit_id = $isNew;
				$result = mysql_query("SELECT * FROM audit_details where `audit_id` = '$isNew'");
				$this->info = mysql_fetch_assoc($result);
			}
			$this->p1_count=null;
			$this->p2_count=null;
			$this->p3_count=null;
			$this->total_bugs_count=null;
		}
		
		function addBug($bug_abbrev, $bug_type, $bug_priority, $bug_rank, $bug_class, $bug_method , $bug_field, $bug_short_message, $bug_long_message, $bug_object){
			global $log;
			global $report_generator_log;
			
			$log = isset($log)&&is_object($log)?$log:$report_generator_log;
			
			$json_encoded_bug_object = json_encode($bug_object);
			$json_encoded_bug_object = mysql_real_escape_string($json_encoded_bug_object);
			$insert_bug_info = mysql_query("INSERT INTO `audit_bug_info`(`audit_id`, `bug_abbrev`, `bug_type`, `bug_priority`, `bug_rank`, `bug_class`, `bug_method`, `bug_field`,`bug_short_message`, `bug_long_message`, `bug_object`) 
					VALUES ('$this->audit_id','$bug_abbrev','$bug_type', '$bug_priority', '$bug_rank','$bug_class','$bug_method',' $bug_field','$bug_short_message', '$bug_long_message', '$json_encoded_bug_object')");
					$inserted_bug_id = mysql_insert_id();
					
			//$log->LogDebug("In addBug(), executed INSERT INTO `audit_bug_info`(`audit_id`, `bug_abbrev`, bug_type`, `bug_priority`, `bug_rank`, `bug_class`, `bug_method`, `bug_field`,`bug_short_message`, `bug_long_message`, `bug_object`) VALUES ('$this->audit_id','$bug_abbrev','$bug_type', '$bug_priority', '$bug_rank','$bug_class','$bug_method',' $bug_field','$bug_short_message', '$bug_long_message', '$json_encoded_bug_object')",__FILE__,__LINE__);
			if($insert_bug_info) 
			 {
			 $log->LogDebug("In addBug(), Bug $inserted_bug_id inserted successfully for audit {$audit->$audit_id}",__FILE__,__LINE__);
			  return mysql_insert_id();
			 }
			 else
			 {
			 $log->LogFatal("In addBug(), MYSQL Error ".mysql_error()." Couldnt insert bug for audit {$audit->$audit_id}",__FILE__,__LINE__);
			 
			 return false;
			 }
			 
		}
		
		function addKeyInfo($package, $code_size, $bugsP1, $bugsP2, $bugsP3){
			$package_insert_qyery = mysql_query("INSERT INTO `audit_key_info`(`audit_id`, `package`, `code_size`, `bugsP1`, `bugsP2`, `bugsP3`)
			 						VALUES ('$this->audit_id','$package', '$code_size', '$bugsP1', '$bugsP2', '$bugsP3')")
			 		or die("error in addkeyinfo ".mysql_error());
				
		}
		
		
		function fetchInfo(){
			//$resultFrom_audit_bug_info  =  mysql_query("SELECT * FROM audit_bug_info WHERE `audit_id` = '$this->audit_id'") or die("unable to fetchInfo ".mysql_error());
			$resultFrom_audit_details  =  mysql_query("SELECT * FROM audit_details WHERE `audit_id` = '$this->audit_id'") or die("unable to fetchInfo ".mysql_error());
			//$resultFrom_audit_key_info  =  mysql_query("SELECT * FROM audit_key_info WHERE `audit_id` = '$this->audit_id'") or die("unable to fetchInfo ".mysql_error());
			//$assoc1 = mysql_fetch_assoc($resultFrom_audit_bug_info);
			$assoc2 = mysql_fetch_assoc($resultFrom_audit_details);
			//$assoc3 = mysql_fetch_assoc($resultFrom_audit_key_info);
			//$result = array_merge($assoc1,$assoc2,$assoc3);
			$this->info = $assoc2;
		}
		
		function getBugsCountByCategories(){
			global $log;
			global $report_generator_log;
			
			$log = isset($log)&&is_object($log)?$log:$report_generator_log;
			
			$log->LogDebug("In getBugsCountByCategories()",__FILE__,__LINE__);
			
			$result = mysql_query("select bug_abbrev, count(*) as count, bug_short_message as description from audit_bug_info where audit_id='{$this->audit_id}' group by bug_abbrev") or die("Unable to fetch bug categories ".mysql_error());
			if(mysql_error()) 
			$log->LogFatal("In getBugsCountByCategories() mysql error occured: ".mysql_error(),__FILE__,__LINE__);
			$toReturn = array();
			while ($row = mysql_fetch_array($result)) {
				$desc = mysql_real_escape_string($row['description']);
				$toReturn[$desc] = $row['count'];
			}
			return  $toReturn;
		}
		
		function getBugsByCategoriesChartData(){
			global $log;
			global $report_generator_log;
			
			$log = isset($log)&&is_object($log)?$log:$report_generator_log;
			
			$log->LogDebug("In getBugsByCategoriesChartData()",__FILE__,__LINE__);
			
			
			$json_bugs_by_categories = "[['Bug Category', 'Bug Count']";
			$bugs_by_categories = $this->getBugsCountByCategories();
			$log->LogDebug("In getBugsByCategoriesChartData() - getBugsCountByCategories() function returns ".json_encode($bugs_by_categories),__FILE__,__LINE__);
			foreach($bugs_by_categories as $category_name => $bug_count)
			{
				$json_bugs_by_categories .= ",['$category_name', $bug_count]";
			}
			
			$json_bugs_by_categories .= "]";
			$log->LogDebug("In getBugsByCategoriesChartData() - Generated data for audit id {$this->audit_id} is $json_bugs_by_categories",__FILE__,__LINE__);
			return  $json_bugs_by_categories;
		}
		
		function getTotalBugsCount(){
			$this->p1_count = is_null($this->p1_count)?$this->getP1Count():$this->p1_count;
			
			
			$this->p2_count = is_null($this->p2_count)?$this->getP2Count():$this->p2_count;
			
			
			$this->p3_count = is_null($this->p3_count)?$this->getP3Count():$this->p3_count;
			
			
			return $this->p1_count + $this->p2_count + $this->p3_count;
		}
		
		function getBugsByPriorityChartData(){
			global $log;
			global $report_generator_log;
			
			$log = isset($log)&&is_object($log)?$log:$report_generator_log;

			$data_to_return = "[
          ['Priority', 'Bug Count'],
          ['Priority 1 Bugs', {$this->getP1Count()}],
          ['Priority 2 Bugs', {$this->getP2Count()}],
          ['Priority 3 Bugs', {$this->getP3Count()}]
			]";
			$log->LogDebug("In getBugsByPriorityChartData() - Generated data  for audit id {$this->audit_id} is $data_to_return",__FILE__,__LINE__);
			
			//if all the three counts add upto 0 return false
			if($this->getTotalBugsCount() == 0)
				return false;
			else
				return  $data_to_return;
		}
		
		function getPackageSummaryChartData(){
			global $log;
			global $report_generator_log;
			
			$log = isset($log)&&is_object($log)?$log:$report_generator_log;


			$result = mysql_query("SELECT distinct bug_class FROM `audit_bug_info` WHERE audit_id='$this->audit_id'") or die("Unable to fetch package summary ".mysql_error());
			$json_for_package_summary_chart = "[['Package', 'Priority 1', 'Priority 2', 'Priority 3']";
			
			while ($row = mysql_fetch_array($result)) {
			$buggy_class = mysql_real_escape_string($row['bug_class']);
			$p1_count = $this->getBugsCountByClassAndPriority($buggy_class,1);
			$p2_count = $this->getBugsCountByClassAndPriority($buggy_class,2);
			$p3_count = $this->getBugsCountByClassAndPriority($buggy_class,3);
				$json_for_package_summary_chart .= ",['$buggy_class',$p1_count,$p2_count,$p3_count]";

			}
			$json_for_package_summary_chart .= "]";
			$log->LogDebug("In getPackageSummaryChartData() - Generated data for audit id {$this->audit_id} is $json_for_package_summary_chart",__FILE__,__LINE__);
			if($this->getTotalBugsCount() == 0)
				return false;
			else
				return  $json_for_package_summary_chart;
		}
		
		function getInfo(){
			return $this->info;
		}
		
		function getField($field){
			return $this->info[$field];
		}
		
		function getP1Count(){
			
			$priority1 = mysql_query("SELECT count(*) as p1_count FROM `audit_bug_info` WHERE `audit_id` = '$this->audit_id' and bug_priority=1") or die("Unable to fetch bug P1 from audit_bug_info ".mysql_error());
			$row = mysql_fetch_assoc($priority1);
			if($row['p1_count']){ 
				return $row['p1_count'];
			} 
			else{
				return 0;
			}
		} 
		
		function getP2Count(){
			$priority2 = mysql_query("SELECT count(*) as p2_count FROM `audit_bug_info` WHERE `audit_id` = '$this->audit_id' and bug_priority=2") or die("Unable to fetch bug P2 ".mysql_error());
			$row = mysql_fetch_assoc($priority2);
			if($row['p2_count']){ 
				return $row['p2_count'];
			} 
			else{
				return 0;
			}
		}
		
		function getP3Count(){
			$priority3 = mysql_query("SELECT count(*) as p3_count FROM `audit_bug_info` WHERE `audit_id` = '$this->audit_id' and bug_priority=3") or die("Unable to fetch bug P3 ".mysql_error());
			$row = mysql_fetch_assoc($priority3);
			if($row['p3_count']){ 
				return $row['p3_count'];
			} 
			else{
				return 0;
			}
		}
		
		function getBugsCountByClassAndPriority($buggy_class, $priority){
			
			$priority1 = mysql_query("SELECT count(*) as count FROM `audit_bug_info` WHERE `audit_id` = '$this->audit_id' and bug_class = '$buggy_class' and bug_priority='$priority'") or die("Unable to fetch bug data in getBugsCountByClassAndPriority".mysql_error());
			$row = mysql_fetch_assoc($priority1);
			if($row['count']){ 
				return $row['count'];
			} 
			else{
				return 0;
			}
		} 
		
		
		
		function setField($field,$value){
			$this->info['$field'] = $value;
			return mysql_query("UPDATE `audit_details` SET `$field`='$value' WHERE audit_id='$this->audit_id'") or die(mysql_error('asd'));
				
		}
		

	}
	
?>