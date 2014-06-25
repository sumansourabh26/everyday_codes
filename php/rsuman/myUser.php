<?php
	class User{
		var $email;
		var $name;
		var $user_id;
		var $password;
		
		function __construct($email, $password){
			$this->email=$email;
			$this->password=$password;
			mysql_query("INSERT INTO `login_table`(`email_id`, `password`) VALUES ('$email','$password')") or die(mysql_error() . ' error 2');
			$this->user_id = mysql_insert_id();
		}
				
		function addInfo(){
			mysql_query("INSERT INTO `users`(`email`, `name`, `contact`,  `audits_allowed`, `account_type`, `registration_date`,`is_online`, `active`, `verification_code`, `utm_source`, `utm_medium`, `utm_campaign`, `referral`) VALUES ('$email','$name','$contact','$audits_allowed','$account_type','$currentdate','0','0','$verification_code','$utm_source','$utm_medium','$utm_campaign', '$ref')") or die(mysql_error() . ' error 1');
		}
		function incrementAuditsAllowed($i){
			mysql_query("UPDATE `users` SET `audits_allowed`=`audits_allowed`+1 WHERE user_id='$this->user_id'") or die("unable to add credits to referrer: ".mysql_error());
		}
		function getId(){
			return $this->user_id;
		}
		function sendActivationMail(){
			$mail_body = "Hello $name,
			<br /><br />
			Your FREE Trial for Appilant has been created. To get started we are giving one audit for free. Learn
			more about getting more audits <a href='http://{$_SERVER['SERVER_NAME']}$offset#pricing'>here</a>.
			<br /><br />
			To activate your account <a href='http://{$_SERVER['SERVER_NAME']}$offset/my-account/activate-account/?key=$verification_code'> click here </a> else go to http://{$_SERVER['SERVER_NAME']}$offset/my-account/activate-account/?key=$verification_code
			<br /><br />
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
			$msgHeaders .= "From: Appilant <info@wegilant.com>\r\n";
			mail($email, $mail_sub, $mail_body, $msgHeaders);
		}
	}
?>