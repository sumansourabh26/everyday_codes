package testings;

public class Class2 extends Class1 {
	int rollnumber;
	public Class2(String s1, String s2, int roll) {
		super(s1, s2);
		rollnumber = roll;
	}
	String returnroll(String randomString) {
		return (String.valueOf(rollnumber)+randomString);
	}

}
