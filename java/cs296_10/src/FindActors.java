import java.io.IOException;
import java.util.ArrayList;
import java.util.Map;
import java.util.Map.Entry;


/**Class to find the Hero and Heroine and villian
 * 
 * @extends MovieStatics
 * 
 * Since the hero and heroine are also a part of statistics. Additionally it uses many functions of MovieStatics. 
 * @author Suman
 *
 */
public class FindActors extends MovieStatistics {

	public FindActors(Movie m) {
		super(m);
	}
	
	/**
	 * prints the hero of script
	 * movieCharsCount =  sortMovieCharacters() and genderCount = determineCharGender() are used by inheritance from MovieStatics
	 * 
	 * The male whose name is most frequent in the script (i.e., the top most male in the map movieCharsCount) is assigned to be the hero.
	 * 
	 * @throws IOException 
	 * 
	 */
	
	public void findHero() throws IOException {
		
		Map<String, Integer> movieCharsCount =  sortMovieCharacters();
		ArrayList<Integer> genderCount = determineCharGender();
		
		String hero = "";
		int index = 0;
		for (Entry<String, Integer> entry : movieCharsCount.entrySet()) {
			if(genderCount.get(index) > 0) {
				hero = entry.getKey();
				break;
			}
			index++;
			
		    //System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
		}		
		
		System.out.println("hero of the movie is:"+hero);
		
	}
	
	/**
	 * prints the heroine of script
	 * movieCharsCount =  sortMovieCharacters() and genderCount = determineCharGender() are used by inheritance from MovieStatics
	 * 
	 * The female whose name is most frequent in the script (i.e., the top most female in the map movieCharsCount) is assigned to be the hero.
	 * 
	 * @throws IOException 
	 * 
	 */
	public void findHeroine() throws IOException {
		Map<String, Integer> movieCharsCount =  sortMovieCharacters();
		ArrayList<Integer> genderCount = determineCharGender();
		
		String heroine = "";
		int index = 0;
		for (Entry<String, Integer> entry : movieCharsCount.entrySet()) {
			if(genderCount.get(index) < 0) {
				heroine = entry.getKey();
				break;
			}
			index++;
			
		    //System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
		}			
		System.out.println("heroine of the movie is:"+heroine);
		
	}
	
	/** prints the villain of script
	 * 
	 */
	public void findVillain() {
		
	}
}
