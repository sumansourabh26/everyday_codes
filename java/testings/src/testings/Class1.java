package testings;

public class Class1 {
	String namesString, ageString;
	
	public Class1(String s1, String s2) {
		namesString = s1;
		ageString = s2;
	}
	String returnname(String x) {	
		return (namesString + x)  ;		
	}
	
String returnage(String x) {
		return (ageString + x)  ;		
	}
}
