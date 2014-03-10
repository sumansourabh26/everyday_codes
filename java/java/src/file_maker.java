import java.util.*;

public class file_maker {
	public static void main(String[] args) {
		final Formatter x;
		
		try{
			x = new Formatter("D:/an.txt");
			System.out.print("file created");
		}
		catch(Exception e){
			System.out.print("you got a error");
		}

	}

}
