<?php
	use JMS\Serializer\Handler\ArrayCollectionHandler;
	use Monolog\Handler\error_log;
	class User{
		var $email;
		var $user_id;
		var $info;

		function __construct($email, $password){
			
			$this->email=$email;
			//$this->password=$password;
			if(!emailExists($email)){
				mysql_query("INSERT INTO `login_table`(`email_id`, `password`) VALUES ('$email','$password')") or die(mysql_error() . ' error 2');
			}
			else {
				$this->fetchInfo();
			}
			
		}			

		function addCredits($credits_added, $credit_add_source, $date_of_add){
			mysql_query("INSERT INTO `credits_added`(`user_id`, `credits_added`, `credit_add_source`, `date_of_add`) VALUES ('$this->user_id','$credits_added','$credit_add_source','$date_of_add')") or die("unable to add credits record in credits_added: ".mysql_error());
			
		}

		
		function addInfo($email,$name,$contact,$audits_allowed,$account_type,$currentdate,$is_online,$active,$verification_code,$utm_source,$utm_medium,$utm_campaign, $ref){
			mysql_query("INSERT INTO `users`(`email`, `name`, `contact`,  `audits_allowed`, `account_type`, `registration_date`,`is_online`, `active`, `verification_code`, `utm_source`, `utm_medium`, `utm_campaign`, `referral`) VALUES ('$email','$name','$contact','$audits_allowed','$account_type','$currentdate','0','0','$verification_code','$utm_source','$utm_medium','$utm_campaign', '$ref')") or die(mysql_error() . ' error 1');
			$this->fetchInfo();
			$this->user_id = mysql_insert_id();
			mysql_query("INSERT INTO `user_preferences`(`user_id`, `timezone`, `date_format`, `time_format`, `date_time_format`) VALUES ('$this->user_id','123','2','1','4')") or die(mysql_error() . ' error 5');
			mysql_query("INSERT INTO `user_plan_map`(`user_id`, `plan_id`, `transaction_date`, `amount`, `for_months`) VALUES ('$this->user_id','0','$currentdate','0','0')") or die(mysql_error() . ' Errro is inserting user_plan_map');
			//$this->verification_code = $verification_code;
			$this->email=$email;
			//error_log("addInfo called");
		}
		
		function addParentByVerificationCode($verify){
			$query = "SELECT * FROM `subuser_verify` WHERE `subuser_email` = '$this->email' and `verification_code` = '$verify'";
			$result = mysql_query($query) or die("unable to verify subuser");
			if(mysql_num_rows($result)==1){
				$row = mysql_fetch_assoc($result);
				$parent_id = $row['parent_id'];
				$parent = getUserById($parent_id);
				if($parent){
					$this->setField('parent_id',$parent->getId());
					$this->setField('is_suspended',0);
					mysql_query("DELETE FROM `subuser_verify` WHERE `subuser_email` = '$this->email'");					
				}
			}
		}
		
		function addPartnerById($partner_id){
			$query="INSERT INTO partners_users(`user_id`,`partner_id`) values($this->user_id,$partner_id)";
			$result=mysql_query($query);
		}

		
		function deleteSubuser($subuser){
			$subuser->setField('is_suspended',0);
			$subuser_email = $subuser->getField('email');
			//error_log("delete subuser called for user Id" .$subuser->getId());
			if($subuser->getField('parent_id')!=0){
				return $subuser->setField('parent_id',0);
			} else {
				return mysql_query("DELETE FROM `subuser_verify` WHERE `subuser_email` = '$subuser_email' and `parent_id` = '$this->user_id'");
			}
		}

		function fetchInfo(){
			$result =  mysql_query("SELECT * FROM login_table A, users B WHERE A.email_id = B.email and A.email_id = '$this->email'") or die("unable to fetchInfo ".mysql_error());
			$this->info = mysql_fetch_assoc($result);
			$this->user_id = $this->info['user_id']; 
			//error_log("fetch info called for user_id $this->user_id");
		}
		
	
		function getAllAudits(){
			$result = mysql_query("SELECT `audit_id` FROM `audit_details` WHERE `user_id` = '$this->user_id' and `audit_status`=1 order by audit_id desc") or die("Unable to fetch all audit ".mysql_error());
			$toReturn = array();
			while($row = mysql_fetch_assoc($result)){
				$audit = getAuditById($row['audit_id']);
				array_push($toReturn, $audit);				
			}
			return $toReturn;
		}
		
		function getAllUniqueAppsCount(){
			$result = mysql_query("SELECT distinct(app_name) FROM `audit_details` WHERE user_id='$this->user_id'") or die("Unable to fetch all unique apps".mysql_error());
			
			return mysql_num_rows($result);
		}
		
		function getTotalPackagesScannedByUser(){
			$result = mysql_query("SELECT * FROM `audit_key_info` WHERE audit_id in (select audit_id from audit_details where user_id='{$this->user_id}')") or die("Unable to fetch all unique packages count".mysql_error());
			
			return mysql_num_rows($result);
		}
		
		function getTotalBugsFoundByUser(){
			$result = mysql_query("SELECT * FROM `audit_bug_info` WHERE audit_id in (select audit_id from audit_details where user_id='{$this->user_id}')") or die("Unable to fetch all unique packages count".mysql_error());
			
			return mysql_num_rows($result);
		}
		
		function getBoughtHistory(){
			$bought = mysql_query("SELECT A.credits_added, DATE_FORMAT(A.date_of_add ,'%a, %D %M %Y') AS formated_date  FROM credits_added A, credits_source B WHERE A.credit_add_source = B.source_id and B.source_id = '3' and A.user_id = '$this->user_id'");
			$toReturn = array();
			while($row = mysql_fetch_assoc($bought)){
				$toReturn[$row['formated_date']] = $row['credits_added'];
			}
			return $toReturn;
		}
		
		function getCurrentPlan(){
			$result = mysql_query("SELECT *
									FROM user_plan_map A, plans B
									WHERE A.plan_id = B.id
									AND A.user_id = '$this->user_id'
									ORDER BY `A`.`transaction_id` DESC
									LIMIT 0 , 1") or die("unable to get Current Plan ".mysql_error());
			if(mysql_num_rows($result)==0)
			 return false;
			$assoc = mysql_fetch_assoc($result);
			return $assoc;
		}
		
		function getCurrentPlanId(){
			$plan_details = $this->getCurrentPlan();
			return $plan_details['plan_id'];
		}
		
		function getCurrentPlanName(){
			$plan_details = $this->getCurrentPlan();
			return $plan_details['package_name'];
		}
		
		function getEarnedHistory(){
			$earned = mysql_query("SELECT A.credits_added, DATE_FORMAT(A.date_of_add ,'%a, %D %M %Y') AS formated_date  FROM credits_added A, credits_source B WHERE A.credit_add_source = B.source_id and B.source_id = '2' and A.user_id = '$this->user_id'");
			$toReturn = array();
			while($row = mysql_fetch_assoc($earned)){
				$toReturn[$row['formated_date']] = $row['credits_added'];
			}
			return $toReturn;
			
		}
		
		function getField($field){
			return $this->info[$field];
		}
		
		function getId(){
			//error_log($this->user_id);
			return $this->user_id;
		}

		function  getInfo(){
			return $this->info;
		}
		
		function getLastAudit(){
			//error_log("last audit for user_id = " . $this->user_id . "called" );
			$result = mysql_query("SELECT `audit_id` FROM `audit_details` WHERE `user_id` = '$this->user_id' ORDER BY `audit_details`.`audit_id` Desc Limit 1") or die("Unable to fetch Last audit ".mysql_error());
			$row = mysql_fetch_array($result);
			if(mysql_num_rows($result)){
				return  getAuditById($row['audit_id']);
			}else{
				return false;
			}
		}
		
		function getLastFinishedAudit(){
			//error_log("last audit for user_id = " . $this->user_id . "called" );
			$result = mysql_query("SELECT `audit_id` FROM `audit_details` WHERE `user_id` = '$this->user_id' and audit_status=1 ORDER BY `audit_details`.`audit_id` Desc Limit 1") or die("Unable to fetch Last audit ".mysql_error());
			$row = mysql_fetch_array($result);
			if(mysql_num_rows($result)){
				return  getAuditById($row['audit_id']);
			}else{
				return false;
			}
		}
		 
		function getPlanExpiryDate(){
			//error_log("last audit for user_id = " . $this->user_id . "called" );
			$current_plan = $this->getCurrentPlan();
			$mo = $current_plan['for_months'];
			$transaction_date = $current_plan['transaction_date'];
			
			$expiry_date = date("Y-m-d H:i:s", strtotime("+$mo months", strtotime($transaction_date)));
			
			return convertSystemToUser($expiry_date);
		}
		
		function getRecentAudits($i){
			$result = mysql_query("SELECT `audit_id` FROM `audit_details` WHERE `user_id` = '$this->user_id' and `audit_status` = 1 ORDER BY `audit_details`.`audit_id` Desc Limit $i") or die("Unable to fetch Recent audits ".mysql_error());
			$toReturn = array();
			while ($row = mysql_fetch_array($result)) {
				$newAudit = getAuditById($row['audit_id']);
				array_push($toReturn, $newAudit);
			}
			return  $toReturn;
		}
		
		function getSubusers(){
			$toreturn = array();
			$result = mysql_query("SELECT `user_id` FROM `users` WHERE `parent_id` = '$this->user_id'") or die("Unable to get subusers ".mysql_error());
			while($row = mysql_fetch_assoc($result)){
				$newSubuser = getUserById($row['user_id']);
				array_push($toreturn, $newSubuser);
			}
			$result = mysql_query("SELECT * FROM  `subuser_verify` WHERE `parent_id` = '$this->user_id'") or die("Unable to get subusers from verification table");
			while($row = mysql_fetch_assoc($result)){
				$newSubuser = getUserByEmail($row['subuser_email']);
				array_push($toreturn, $newSubuser);
			}
			return $toreturn;
		}
		
		function getTotalBoughtCredits(){
			$result = mysql_query("SELECT SUM(credits_added) as credits_bought FROM credits_added WHERE credit_add_source = '3' and  user_id = '$this->user_id'") or die("error in getTotalBoughtCredit() ".mysql_error());
			$row = mysql_fetch_assoc($result);
			$credits_added = $row['credits_bought'];
			if($credits_added){
				return $credits_added;
			}else{
				return 0;
			}
		}
		
		function getTotalEarnedCredits(){
			$result = mysql_query("SELECT SUM(credits_added) as credits_earned FROM credits_added WHERE credit_add_source = '2' and user_id = '$this->user_id'") or die("error in getTotalEarnedCredit() ".mysql_error());
			$row = mysql_fetch_assoc($result);
			$credits_earned =  $row['credits_earned'];
			if($credits_earned){
				return $credits_earned;
			}else{
				return 0;
			}
		}
		
		function getTotalSpentCredits(){
			$result = mysql_query("SELECT `audit_id` FROM `audit_details` WHERE `user_id` = '$this->user_id'");
			$total_credits_spent = mysql_num_rows($result);
			return $total_credits_spent;
		}
		
		function incrementAuditsAllowed($i){
			mysql_query("UPDATE `users` SET `audits_allowed`=`audits_allowed`+$i WHERE user_id='$this->user_id'") or die("unable to add credits to referrer: ".mysql_error());
			//error_log("incrementAuditsAllowed called");
		}
		
		function isEligibleForSubuser(){
			global $log;
			$log->LogDebug("In isEligibleForSubuser",__FILE__,__LINE__);
			$current_plan = $this->getCurrentPlan();
			$log->LogDebug("In isEligibleForSubuser - current_plan of passed user with email id {$this->email} is ".json_encode($current_plan),__FILE__,__LINE__);
			if($this->isSubuser())
			{
				$log->LogDebug("In isEligibleForSubuser - Current user is a subuser. Hence returning false.",__FILE__,__LINE__);
				return false;
			}
			else{
			if($current_plan['plan_id'] == 1){
				$log->LogDebug("In isEligibleForSubuser - Current plan id of the passed user is 1",__FILE__,__LINE__);
				$subusers = $this->getSubusers();
				if(count($subusers) >= $current_plan['subusers_allowed']){
					$log->LogDebug("In isEligibleForSubuser - Current subusers count is equal to or more than allowed in his plan. Hence returning false.",__FILE__,__LINE__);
					return false;
				}else{
					$log->LogDebug("In isEligibleForSubuser - Current subusers count is less than allowed in his plan. Hence returning true.",__FILE__,__LINE__);
					return true;
				}
			} else {
				$log->LogDebug("In isEligibleForSubuser - user is not running with plan id 1. Hence returning false.",__FILE__,__LINE__);
				return false;
			}
			}			
		}
		
		function isEligibleForScan($user_to_check = NULL){
			global $log;
			$log->LogDebug("inside isEligibleForScan",__FILE__,__LINE__);
			if(is_null($user_to_check))
			{
			$user_to_check = $this;
			$log->LogDebug("In isEligibleForScan - NULL passed as user will use this as user",__FILE__,__LINE__);
			}
			
			$current_plan = $user_to_check->getCurrentPlan();
			$log->LogDebug("In isEligibleForScan - current_plan of passed user with email id {$user_to_check->email} is ".json_encode($user_to_check->getCurrentPlan()),__FILE__,__LINE__);
			//if user is a parent then check its plan id & return
			if($user_to_check->getField('parent_id') == 0){
				//he is a parent
				$log->LogDebug("In isEligibleForScan - passed user is a Parent",__FILE__,__LINE__);
				if($current_plan['plan_id'] == 1){
				$log->LogDebug("In isEligibleForScan - passed user Plan id is 1",__FILE__,__LINE__);
					if($user_to_check->getField('is_suspended')){
						$log->LogDebug("In isEligibleForScan - passed user is suspended. Hence returning false.",__FILE__,__LINE__);
						return false;
					} else {
						$log->LogDebug("In isEligibleForScan - passed user is NOT suspended. Hence returning true.",__FILE__,__LINE__);
						return true;
					}
				}
				else{
					$log->LogDebug("In isEligibleForScan - passed user Plan id is not 1",__FILE__,__LINE__);
					//he must be a parent in free trial
					if(count($user_to_check->getAllAudits())>=1)
					{
						$log->LogDebug("In isEligibleForScan - passed user has already performed more than one scan. Hence user is not eligible for scan. returning false",__FILE__,__LINE__);
						//he has already done the free scan hence not allowed
						return false;
					}
					else
					{
						$log->LogDebug("In isEligibleForScan - passed user has not performed any scan. Hence user is eligible for scan. returning true",__FILE__,__LINE__);
						return true;
					
					}
				}
				
				}
				else
				{
					//he is a child 
					//check the parent's eligibility
					$log->LogDebug("In isEligibleForScan - passed user has a parent with parent_id {$user_to_check->getField('parent_id')}. Hence Parent's eligibility will be checked. calling isEligibleForScan for parent.",__FILE__,__LINE__);
					$parent = getUserById($user_to_check->getField('parent_id'));
					//check the eligibility of parent
					return $user_to_check->isEligibleForScan($parent);
				}
			
		}
		
		function isSubuser(){
			return !($this->info['parent_id'] == 0);
		}
		
		function isActiveSubuser(){
			if($this->getField('parent_id') != 0 && $this->getField('active') != 0){
				return true;
			}
			return false;
		}

		function mapAuditId($auditId){
			$uid = $this->getField('user_id');
			$query = "UPDATE `audit_details` SET `user_id`='$uid' WHERE audit_id='$auditId'";

			return mysql_query($query);
		}
		function sendActivationMail(){
			global $offset,$sendmail_from;
			$mail_body = "Hello ". $this->info['name']. ",
			<br /><br />
			Your FREE Trial for Appilant has been created. To get started we are giving one audit for free. Learn
			more about getting more audits <a href='http://" . $_SERVER['SERVER_NAME'] . $offset . "#pricing'>here</a>.
			<br /><br />
			To activate your account <a href='http://" . $_SERVER['SERVER_NAME'] . $offset . "/my-account/activate-account/?key=" . $this->info['verification_code'] . "'> click here </a> else go to http://" . $_SERVER['SERVER_NAME'] . $offset . "/my-account/activate-account/?key=" . $this->info['verification_code'] .
			"<br /><br />
			and set your password to login into Appilant.
			<br /><br />
			Happy code auditing & secure coding!
			<br /><br />
			Regards,<br />
			Toshendra Sharma,<br />
			CEO, Wegilant";
			$mail_sub = "Welcome to Appilant by Wegilant. Activate your Account now!";
			$msgHeaders = 'MIME-Version: 1.0' . "\r\n";
            $msgHeaders .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
			$msgHeaders .= "From: $sendmail_from\r\n";
			if(mail($this->email, $mail_sub, $mail_body, $msgHeaders)){
				//error_log("messagsent");
			}else{
				//error_log("message not sent");
			}

		}
		
		function sendForgotPasswordMail(){
			global $offset, $sendmail_from;
			$key = sha1(rand() . 'oisaydihvyisyfu80934543nvgbdg#h01joAYUSas');
			$query = "INSERT INTO forgetpass (`key`, `email`) VALUES ('$key', '$this->email')";
			mysql_query($query);
		
			// Reset Password link
			$link = 'http://' . $_SERVER['HTTP_HOST'] .$offset. '/my-account/reset-password/?key=' . $key;
			$mail_body = "Dear Appilant User<br/><br/>
			We have just received a password reset request for your email id. Please click on the following link to reset your password.<br/><br/>
			Link: $link<br/>
			<br/>
			If you have not generated this request then please report it immediately to info@wegilant.com.<br/><br/>
			<b>Regards,<br/>
			Team Wegilant
			</b>";
		
			$mail_sub = "Appilant Password Reset";
		$msgHeaders = 'MIME-Version: 1.0' . "\r\n";
				$msgHeaders .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
				$msgHeaders .= "From: $sendmail_from\r\n";
				return mail($this->email, $mail_sub, $mail_body, $msgHeaders);
		}
		
		function sendReferralMail($email_list){
			global $offset, $sendmail_from;
			$msgHeaders = 'MIME-Version: 1.0' . "\r\n";
			$msgHeaders .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
			$msgHeaders .= "From: $sendmail_from\r\n";
			$refererName = $this->info['name'];
			$refererId = $this->info['user_id'];
				
			$mail_body = "Dear Friend,<br /><br />
			You have been referred to us by your friend, {$refererName}.
			<br /><br />
			At Wegilant, we are building Appilant, a cloud-based Android App security auditing tool.
			Your friend {$refererName}, has already tried Appilant and would like to have you take a look
			at it.
			<br /><br />
			Hope you find our tool useful.
			<br /><br />
			<a href='http://{$_SERVER['SERVER_NAME']}$offset/#free_trial/?referral=$refererId' target='_blank'>Click here</a> to signup for Appilant and get started.
			<br /><br />
			Thank you,
			<br />
			Team Appilant @ Wegilant A SINE IIT Bombay Company";
				
			$mail_sub = "You have been referred by {$refererName}";
				
			return mail($email_list, $mail_sub, $mail_body, $msgHeaders);
		}
		
		function sendSubuserConfirmationMail($email){
			global $offset,$sendmail_from;
			$msgHeaders = 'MIME-Version: 1.0' . "\r\n";
			$msgHeaders .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
			$msgHeaders .= "From: $sendmail_from\r\n";
			$parent_name = $this->getField('name');
			$parent_id = $this->getField('user_id');
			$subuser = getUserByEmail($email);
			
			if($subuser->getField('active')){
				//if subuser is already registered & active
				//send him a login link to get confirmation
				$query = "SELECT * FROM `subuser_verify` WHERE `parent_id` = '$this->user_id' and `subuser_email` = '$email'";
				$result = mysql_query($query) or die("unable to fetch result from subuser_verify");
				if(mysql_num_rows($result) >  0){
					$row = mysql_fetch_assoc($result);
					$verification_code = $row['verification_code'];
				}else{
					$verification_code = get_rand_alphanumeric(57);
					mysql_query("INSERT INTO `subuser_verify` (`parent_id`, `subuser_email`, `verification_code`) VALUES ('{$this->getField('user_id')}', '$email', '$verification_code')");
				}

				$subuser_name = $subuser->getField('name');
				$mail_body = "Dear {$subuser_name},<br /><br />
					You have been added as subuser in Appilant by your friend, {$parent_name}.
					<br /><br />
					Your friend {$parent_name}, is having a standard account and like to have you as a subuser under him.
					<br /><br />
					As subuser benefit, you will have unlimited audits of your android app by Appilant. Hope you find our tool useful.
					<br /><br />
					<a href='http://{$_SERVER['SERVER_NAME']}$offset/my-account/login/?verify=$verification_code' target='_blank'>Click here</a> to confirm and get started.
					<br /><br />
					Thank you,
					<br />
					Team Appilant @ Wegilant A SINE IIT Bombay Company";
								
			}	
			else{
				//user has not been registered
				//hence send an account activation link
				$verification_code = $subuser->getField('verification_code');
				$subuser_name = $subuser->getField('name');
				$mail_body = "Dear {$subuser_name},<br /><br />
					You have been invited as subuser by your friend, {$parent_name}.
					<br /><br />
					At Wegilant, we are building Appilant, a cloud-based Android App security auditing tool.
					Your friend {$parent_name}, is having a standard account and like to have you as a subuser under him.
					<br /><br />
					As subuser benefit, you will have unlimited audits of your android app by Appilant. Hope you find our tool useful.
					<br /><br />
					<a href='http://{$_SERVER['SERVER_NAME']}$offset/my-account/activate-account/?key=$verification_code' target='_blank'>Click here</a> to confirm your signup and get started.
					<br /><br />
					Thank you,
					<br />
					Team Appilant @ Wegilant A SINE IIT Bombay Company";
			}
			$mail_sub = "You have been added as subuser by {$parent_name}";
			return mail($email, $mail_sub, $mail_body, $msgHeaders);
		}
		
		function setPassword($newpassword){
			return mysql_query("UPDATE `login_table` SET `password`='$newpassword' WHERE `email_id`='$this->email'") or die("unable to reset password: ".mysql_error());	
		}

		function setField($fieldName, $value){
			$this->info[$fieldName] = $value;
			
			return mysql_query("UPDATE `users` SET `$fieldName`='$value' WHERE user_id='$this->user_id'") or die(mysql_error('asd'));
		}
		
		function setPreference($fieldName, $value){
			//$this->info[$fieldName] = $value;
			//error_log($fieldName . ":" . $value);
			$is_update_successfull = mysql_query("UPDATE `user_preferences` SET `$fieldName`='$value' WHERE user_id='$this->user_id'") or die(mysql_error('setPreference Failed!!!'));
			
			//update session variables as well if update is successful
			if($is_update_successfull){
			if($fieldName == "timezone"){
			$result = mysql_query("select GMT from `timezones` where id='$value'") or die(mysql_error('Unable to get timezone offset in sePrefrence function!!!'));
			$result_assoc = mysql_fetch_assoc($result);
			$offset_string = $result_assoc['GMT'];
			$_SESSION['user_timezone_offset'] = $offset_string;
			$_SESSION['user_timezone_id'] = $value;
			
			}elseif($fieldName == "date_format"){
			$result = mysql_query("select format from `date_formats` where id='$value'") or die(mysql_error('Unable to get date format in sePrefrence function!!!'));
			$result_assoc = mysql_fetch_assoc($result);
			$date_format_string = $result_assoc['format'];
			$_SESSION['user_date_format'] = $date_format_string;
			$_SESSION['user_date_format_id'] = $value;
			
			}elseif($fieldName == "time_format"){
			$result = mysql_query("select format from `time_formats` where id='$value'") or die(mysql_error('Unable to get time format in sePrefrence function!!!'));
			$result_assoc = mysql_fetch_assoc($result);
			$time_format_string = $result_assoc['format'];
			$_SESSION['user_time_format'] = $time_format_string;
			$_SESSION['user_time_format_id'] = $value;
			
			}elseif($fieldName == "date_time_format"){
			$result = mysql_query("select format from `timestamp_formats` where id='$value'") or die(mysql_error('Unable to get timestamp format in sePrefrence function!!!'));
			$result_assoc = mysql_fetch_assoc($result);
			$date_time_format_string = $result_assoc['format'];
			$_SESSION['user_date_time_format'] = $date_time_format_string;
			$_SESSION['user_date_time_format_id'] = $value;
			
			}
			}
			
			return $is_update_successfull;
		}
		
		function getPreference($fieldName){
			//$this->info[$fieldName] = $value;
			
			$preference_result = mysql_query("SELECT B.GMT as offset, B.id as timezone_id, B.UTC as UTC, C.format as date_time_format,C.id as date_time_format_id, D.format as date_format,D.id as date_format_id, E.format as time_format, E.id as time_format_id FROM user_preferences A, timezones B, timestamp_formats C, date_formats D, time_formats E where A.timezone=B.id and A.date_format = D.id and A.time_format=E.id and A.date_time_format=C.id and A.user_id ='$this->user_id'") or die(mysql_error('getPreference Failed!!!'));
			$preference_row = mysql_fetch_assoc($preference_result);
			error_log("Preference returned ".$fieldName . ":" . $preference_row[$fieldName]);
			return $preference_row[$fieldName];
		}
		
		
		function setSubuserField($subuser,$field,$value){
			$subuserId = $subuser->user_id;
			return mysql_query("UPDATE `users` SET `$field`='$value' WHERE user_id='$subuserId'") or die("error in setsubuserField ".mysql_error(''));
		}
		
		function toggleSuspendSubuser($subuser){
			if($subuser->getField('parent_id')!=0)
			{
				return $subuser->setField('is_suspended',!$subuser->getField('is_suspended'));
			}
			return false;
		}
		
		
	}
	
	
?>