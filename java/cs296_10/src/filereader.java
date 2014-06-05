import java.io.*;

public class filereader {
	public static void main(String[] args) throws IOException{
		
		Movie m = new Movie();
		System.out.println(m.getMovieTitle());
		
		FindActors ms = new FindActors(m);
		
		System.out.println("the number of words "+ ms.countScriptWords());
		ms.countMovieCharacters();
		ms.printCharCounts();
		ms.printCharCountsWithGender();
		ms.findHero();
		ms.findHeroine();
	
	}
}






