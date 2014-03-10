import java.io.*;
import java.lang.*;
import java.util.*;

class CreateFile{
	private Formatter x;
	
	 void openFile(){
		try {
			x = new Formatter("D:/an1.txt");
		} 
		catch (FileNotFoundException e) {
			System.out.print("ksfj");
		}
	 }
	 
	 public void adRecords(){
		 x.format("%s%s%s", " 20"," bucky"," roberts");
	 }
	 public void closeFile(){
		 x.close();
	 }
}

public class writing_file {
	public static void main(String[] args) {
		CreateFile g = new CreateFile();
		g.openFile();
		g.adRecords();
		g.closeFile();
		
		
	}
}
