	import java.io.BufferedInputStream;
	import java.io.DataInputStream;
	import java.io.File;
	import java.io.FileInputStream;
	import java.io.FileNotFoundException;
	import java.io.IOException;
	import java.util.Scanner;
	public class movie {
		String movieFilename;
		
		public movie(String moviepath){
			movieFilename=moviepath;
			}
			
		public static void main(String []args) {
			System.out.println("Enter the name of the file for which you want the details of script ");
			String s;
			Scanner in = new Scanner(System.in);
			s = in.nextLine();
			movie mymovie = new movie(s);
			File file = new File(s);
			FileInputStream fis = null;
			BufferedInputStream bis = null;
			DataInputStream dis = null;
	
	    try {
	      fis = new FileInputStream(file);
	
	      // Here BufferedInputStream is added for fast reading.
	      bis = new BufferedInputStream(fis);
	      dis = new DataInputStream(bis);
	
	      // dis.available() returns 0 if the file does not have more lines.
	      while (dis.available() != 0) {
	
	      // this statement reads the line from the file and print it to
	        // the console.
	        System.out.println(dis.readLine());
	      }
	
	      // dispose all the resources after using them.
	      fis.close();
	      bis.close();
	      dis.close();
	
	    } catch (FileNotFoundException e) {
	      e.printStackTrace();
	    } catch (IOException e) {
	      e.printStackTrace();
	    }
	    }
	}
	
