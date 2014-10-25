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
			<center><h1> Course Information </h1></center>
		<p>
			<center>
				Enter the Course Name to get Info
				<input type="text" name="course" size="20px"><br><p>
				<input id="submit1" type="submit" value="submit" onclick="al()"> 
				 
				<input type="reset" VALUE="clear">
				<input type="hidden" name="identify" VALUE="getCourse">
			</center>
		</p>
		</form> 
		
		<form action="JdbcPostgresqlConnection">
			<center><h1> Change course prerequisite </h1></center>
		<p>
			<center>
				Enter the course id of course: <input type="text" name="course1" size="20px"><br>
				Enter the course id of initial prerequisite: <input type="text" name="prereq" size="20px"><br>
				Enter the course id of final prerequisite: <input type="text" name="prereqFinal" size="20px"><br>
				<input id="submit1" type="submit" value="submit" onclick="al()"> 
				 
				<input type="reset" VALUE="clear">
				<input type="hidden" name="identify" VALUE="changePre">
			</center>
		</p>
		</form>
		
		
	</body>
</html>
