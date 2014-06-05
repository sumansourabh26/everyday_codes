import java.io.*;
import java.lang.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.NEW;

class CreateFile{
	private Formatter x;
	
	 void openFile(){
		try {
			x = new Formatter("an1.txt");
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
//		try
//		{
//		    String filename= "MyFile.txt"
//		    FileWriter fw = new FileWriter(filename,true); //the true will append the new data
//		    fw.write("add a line\n");//appends the string to the file
//		    fw.close();
//		}
//		catch(IOException ioe)
//		{
//		    System.err.println("IOException: " + ioe.getMessage());
//		}
		Date d = new Date();
		int year = d.getYear()+1900;
		
		String string = d.getDate()+" "+d.getMonth()+" "+ year;
		System.out.println(string);
	}
}
