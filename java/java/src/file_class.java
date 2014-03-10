import java.io.*;

public class file_class {
	public static void main(String[] args) {
		
		File x = new File("D:/an.txt");
		
		if(x.exists())
			System.out.print(x.getName()+ " exist");
		else
			System.out.print("dne");
	}
}
