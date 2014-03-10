
public class more_string {
	public static void main(String[] args) {
		String s = "buckyrobertsbuckyroberts";
		
		System.out.print(fact(4));

	}
	static long fact(long n){
		if(n == 1)
			return 1;
		else
			return(n* fact(n-1));
	}

}
