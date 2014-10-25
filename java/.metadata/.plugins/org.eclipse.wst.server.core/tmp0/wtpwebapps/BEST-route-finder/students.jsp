<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>

<form action="JdbcPostgresqlConnection">
	<center><h1> Target Student Information </h1></center>
	<p>
		<center>
			Enter the Student Name
			<input type="text" name="name" size="20px"><br>
			<input type="hidden" name="identify" VALUE="getStudent">
			<input id="submit1" type="submit" value="submit" onclick="al()"> 
			<input type="reset" VALUE="clear">
		</center>
	</p>
</form>


<form action="JdbcPostgresqlConnection">
	<center><h1> enter new student data</h1></center>
	<p>
		<center>
			Enter new student id: <input type="text" name ="id" size="20px"><br>
			Enter new student's name: <input type="text" name="newname" size="20px"><br>
			Enter new student department:<input type="text" name="dept" size="20px"><br>
			Enter new student's total credits: <input type="text" name="tot_credits" size="20px"><br>
			<input type="hidden" name="identify" VALUE="insertStudent">
						
			<input id="submit2" type="submit" value="submit" onclick="al()"> 
			<input type="reset" VALUE="clear">
			
		</center>
	</p>
	

</form>

</body>
</html>
