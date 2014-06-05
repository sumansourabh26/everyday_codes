import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Movie {
	
	public String movieFilename; 
	private BufferedReader bf;
	
	Movie() throws IOException{

		InputStreamReader stream = new InputStreamReader(System.in);
		BufferedReader input = new BufferedReader(stream);
		
		System.out.println("Please give the absolute path of the script file");
		
		movieFilename = "C:/Users/Shobhakant/Dropbox/code/java/cs296_10/src/scripts/diehard.txt";		
		
	}
	
	String getMovieTitle() throws IOException{
		
		bf = new BufferedReader(new FileReader(movieFilename));
		String line = bf.readLine();
		
		while (line != null){
			
			if (line.length() != 1){
				return line.trim();
			}
			line = bf.readLine();
		}
		return null;
	}
	
	String getMovieAuthor(){
		return movieFilename;
	}
	
	void printMovieTitle() throws IOException{
		System.out.println(getMovieTitle());
	}
	
	void printMovieAuthor(){
		System.out.println(getMovieAuthor());
	}
	
	/*String[] getMovieWords(){
		bf = new BufferedReader(new FileReader(movieFilename));
		String line = bf.readLine();
		
		while (line != null){
			
			if (line.length() != 1){
				line.split(" ");
			}
			line = bf.readLine();
		}
	}*/
}
