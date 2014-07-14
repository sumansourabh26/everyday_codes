<?php

	function emailExists($email)
	{
		$result = mysql_query("SELECT *
				FROM login_table
				WHERE
				email_id = '$email'") or die(mysql_error());
	
	
		if (mysql_num_rows($result) > 0)
		{
			
			return true;
		}
		else
		{
			
			return false;
		}
	}
	
	function userIdExists($user_id){
		$result = mysql_query("SELECT *
				FROM `users`
				WHERE
				user_id = '$user_id'") or die(mysql_error());
		
		
		if (mysql_num_rows($result) > 0)
		{
			
			return true;
		}
		else
		{
			
			return false;
		}
	}
	
	function getAuditById($id){
		
		return new Audit(0,0,0,0,0,0, $id);
	}
	
	function getUser($email, $password){
		$login = mysql_query("SELECT * FROM login_table  WHERE `email_id` = '$email' and `password` = '$password'") or die(mysql_error());
		$count = mysql_num_rows($login);
		//$status = mysql_fetch_assoc($login);
		if($count == 0){
			
			return false;
		}
		if($count == 1){
			$user = new User($email, $password);
			return $user;
		}
	}
	
	function getUserById($id){
		$result = mysql_query("SELECT `email` FROM users where `user_id`='$id'") or die("ERROR IN getUserby id ". mysql_error());
		$row = mysql_fetch_assoc($result);
		$email = $row['email'];

		$passResult = mysql_query("SELECT `password` FROM login_table where `email_id`='$email'") or die("ERROR IN getUserby id ". mysql_error());
		$row = mysql_fetch_assoc($passResult);
		$password = $row['password'];
		return getUser($email, $password);
		
	}
	
	function getUserByAuditId($id){
		$result = mysql_query("SELECT `user_id` FROM audit_details where `audit_id`='$id'") or die("ERROR IN getUserByAuditId ". mysql_error());
		$row = mysql_fetch_assoc($result);
		$user_id = $row['user_id'];
		return getUserById($user_id);
	}
	
	function getUserByVerificationCode($varCode){
		$result = mysql_query("SELECT `user_id` FROM `users` WHERE `verification_code` = '$varCode'") or die("error in getUserByVerificationCode result ".mysql_error());
		if(mysql_num_rows($result) != 0){
			$assocArray  = mysql_fetch_assoc($result);
			$id = $assocArray['user_id'];
			return getUserById($id);	
		} else {
			return false;
		}
		
	}
	
	function getUserByEmail($email){
		$result = mysql_query("SELECT `user_id` FROM `users` WHERE `email` = '$email'") or die("error in getUserByEmail result ".mysql_error());
		$assocArray  = mysql_fetch_assoc($result);
		if(mysql_num_rows($result) != 0){
			$id = $assocArray['user_id'];
			return getUserById($id);
		} else {
			return false;
		}
		
	}

	function getEmailByUserId($uid){
		$result = mysql_query("SELECT `email` FROM `users` WHERE `user_id` = '$uid'") or die("error in getEmailByUserId result ".mysql_error());
		$assocArray  = mysql_fetch_assoc($result);
		if(mysql_num_rows($result) != 0){
			$email_id = $assocArray['email'];
			return $email_id;
		} else {
			return false;
		}
		
	}
	function submit_contact_us_request($name, $email, $message, $utm_source, $utm_campaign, $utm_medium){
		 $currentdatetime = getSystemCurrentDateTime();
		$result = mysql_query("INSERT INTO `contact_us_requests`(`name`, `email`, `message`, `utm_source`, `utm_medium`, `utm_campaign`, `request_date_time`) VALUES ('$name','$email','$message','$utm_source','$utm_medium', '$utm_campaign','$currentdatetime')") or die("error in inserting contact us request ".mysql_error());
		
		//$message = preg_replace("/\r\n|\r|\n/",'<br/>',$message);
		//$message = nl2br("$message");
			global $support_email,$log,$sendmail_from;
			$mail_body = "Hello Admin,
			<br /><br />
			Please respond to my request. My details are given below</br></br> 
			Name: $name<br>
			Email: $email<br>
			Message: $message<br>
			Source: $utm_source<br>
			Medium: $utm_medium<br>
			Campaign: $utm_campaign<br>
			<br>
			<br>
			
			-Regards<br>
			$name
			
			";
			$mail_sub = "Contact us request by $name";
			$msgHeaders = 'MIME-Version: 1.0' . "\r\n";
			$msgHeaders .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
			$msgHeaders .= "From: noreply@wegilant.com \r\n"; //it has to be wegilant.com
			$msgHeaders .= "Reply-To: $email \r\n";
			if(mail($support_email, $mail_sub, $mail_body, $msgHeaders)){
				$log->LogInfo("Contact us request submited & email send successfully at $support_email  with $message",__FILE__,__LINE__);
			}else{
				if($result)
				$log->LogFatal("Contact us request submited & but email could not be send successfully at $support_email with $message",__FILE__,__LINE__);
				else
					$log->LogFatal("Contact us request could not be submited & email could not be send at $support_email",__FILE__,__LINE__);
			}
		
		
		return $result;
		
		
		
	}	
?>