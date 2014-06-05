import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

/**
 * 
 * @author Shobhakant
 *
 */
public class MovieStatistics implements MovieStatAbstract{
	Movie m;
	private BufferedReader bf;
	//private ArrayList<String> distMovieChars;
	private ArrayList<Integer> count;
	//private ArrayList<Integer> gender;
	final private String a = "C:/Users/Shobhakant/Dropbox/code/java/cs296_10/src/scripts/diehard.txt";  
	
	public MovieStatistics(Movie m) {
		this.m = m;		
	}
	
	
	/**countScriptWords()
	 * 
	 * It reads the whole script line by line and adds the count of word in the each line.
	 * @return Count of the Word in the whole script
	 * @throws IOException
	 */
	public int countScriptWords() throws IOException {
		BufferedReader bf = new BufferedReader(new FileReader(m.movieFilename));
		String line = bf.readLine();
		
		int count = 0;
		while (line != null) {
			if (line.length() != 0){
				count = count + (line.trim()).split("\\s+").length;
			}
			line = bf.readLine();
		}
		return count;
	
	}
	
	/**
	 * 
	 * @return Map<String, Integer> which maps name of characters to the frequency of its appearance in script.
	 * @throws IOException
	 */
	Map<String, Integer> countMovieCharacters() throws IOException{
		ArrayList<String> movieChars = new ArrayList<String>();
		ArrayList<String> distMovieChars = new ArrayList<String>();
		count = new ArrayList<Integer>();
		
		char[] badPunctuation = {')' , '(', '.', '-', '?', '!', '"','\'', ':', ',', '0','1', '2','3','4','5','6','7','8','9'};
		
		String[] notcharlist = {"VOICES", "CUT", "AN", "I'M", "SOMEBODY", "THE", "CONTINUOUS", "TRANSLATING", "SURROUNDINGS", "ALL", "CONTINUED", "AND", "AT", "IT", "FL", "MAN", "MO-MEE-MO-MEE-MO", "SUSPICIONS", "JESUS", "FREEZE"};
		
		
		bf = new BufferedReader(new FileReader(a));
		String line = bf.readLine();
		while (line != null){
			line = line.trim();
			if (line.length() > 1)
			{
				String[] splitlist = line.split(" ");
					if (splitlist.length == 1 && splitlist[0] == splitlist[0].toUpperCase()){
						//System.out.println(splitlist[0]);
						String current = splitlist[0];
						if (current.length() > 1){
							char last = current.charAt(current.length() - 1);
							char first = current.charAt(0);
							boolean satisfy = true;
							for (int i = 0; i < badPunctuation.length; i++){
								if (last == badPunctuation[i] || first == badPunctuation[i]){
									satisfy = false;
									break;
								}
							}
							
							for (int i = 0; i < notcharlist.length; i++){
								if (current.startsWith(notcharlist[i])){
									satisfy = false;
									break;
								}
							}
							
							if (satisfy){
								movieChars.add(current);
								
							}
						}
					}
					
			}
			
			line = bf.readLine();
		}
		
		Collections.sort(movieChars);
		
		int index = 0;
		
		while(index < movieChars.size()){
			String currentString = movieChars.get(index);
			while (movieChars.get(index).startsWith(currentString)){
				index = index + 1;
				if (index >= movieChars.size()){
					break;
				}
			}
			distMovieChars.add(currentString);
			count.add(0);
			
		}
		
		
		bf = new BufferedReader(new FileReader(a));
		line = bf.readLine();
		while (line != null){
			line = line.trim();
			String[] spl = line.split(" ");
			
			for (int i = 0; i < distMovieChars.size(); i++){
				//int temp = 0;
				String currentString = distMovieChars.get(i);
				for (int j = 0; j < spl.length; j++){
					if(spl[j].toUpperCase().startsWith(currentString)){
						count.set(i, count.get(i) + 1);
					}
				}
			}
			
			line = bf.readLine();
		}
		
//		gender//
		

		
		Map<String, Integer> countMap =new HashMap<String, Integer>();
		for(int i =0; i < distMovieChars.size(); i++) {
						
			countMap.put(distMovieChars.get(i), count.get(i));
			
		}
		// System.out.println(countMap);
		return countMap;
		
	
		
	}
	
	////////////////////////////////////////for sorting the map//////////////////////
	/**It takes a Map<String, Integer> m, converts it to a linked list, sort the linkedlist and convert it back to map.
	 *  
	 * @param Map<String, Integer> m
	 * @return Map which is sorted by its value.
	 */
	 public Map<String,Integer> sortByComparator(Map<String, Integer> m) {
		 
		List list = new LinkedList(m.entrySet());

		Collections.sort(list, new Comparator() {
				public int compare(Object o1, Object o2) {
					return ((Comparable) (((Map.Entry<String, ArrayList<Integer>>) (o2)).getValue()))
	                                       .compareTo((((Map.Entry<String,ArrayList<Integer>>) (o1)).getValue()));
				}
			}
		);
 
		/** put sorted list into map again
         *LinkedHashMap make sure order in which keys were inserted
         */
		Map sortedMap = new LinkedHashMap();
		for (Iterator it = list.iterator(); it.hasNext();) {
			Map.Entry entry = (Map.Entry) it.next();
			sortedMap.put(entry.getKey(), entry.getValue());
		}
		return sortedMap;
	
	}
	
	//////////////////////////////////////////////////////////////////////////////////	
	
	/**sortMovieCharacters() uses the function sortByComparator(Map<String, Integer> m) to sort Map<String, Integer>, and then returns a map of character names with their frequency, sorted by the frequency.
	 *  
	 * 
	 * @return Map<String, Integer> which is sorted by the integer value. 
	 * @throws IOException
	 */
	Map<String, Integer> sortMovieCharacters() throws IOException {
		Map<String, Integer> m = countMovieCharacters();
		return sortByComparator(m);
		
	}
	
	/**
	 * 
	 * @return ArrayList<Integer> which holds the list of integers. The ith integer in the ArrayList -ve if the ith character in sortMovieCharacter() is female, +ve if male and 0 if not determined.  
	 * @throws IOException
	 */
	ArrayList<Integer> determineCharGender() throws IOException {
		
		Map<String, Integer> movieCharsCount =  sortMovieCharacters();
		ArrayList<Integer> movieCharsGender = new ArrayList<Integer>();
		
		int mapSize = movieCharsCount.size();
		
		for (int i=0; i < mapSize; i++) {
			movieCharsGender.add(0);
		}
		
		bf = new BufferedReader(new FileReader(a));
		String line = bf.readLine();
		while (line != null){
			line = line.trim();
			String[] spl = line.split(" ");
			
			
			int index = 0;
			
			for (Entry<String, Integer> entry : movieCharsCount.entrySet()) {
				// Integer valueForEntry = movieCharsGender.get(entry.getKey());
				String keyForEntryString = entry.getKey();
				for (int j = 0; j< spl.length; j++){
					if (spl[j].toUpperCase().startsWith(entry.getKey())){
						
						for (int k = 0; k < spl.length; k++){
							if (spl[k].matches("His") || spl[k].matches("his")){
								
								movieCharsGender.set(index, movieCharsGender.get(index) + 1);
								break;
							}
						}
						for (int k = 0; k < spl.length; k++){
							if (spl[k].matches("Her") || spl[k].matches("her")){
								movieCharsGender.set(index, movieCharsGender.get(index) - 1);
								break;
							}
						}
						
						for (int k = 0; k < spl.length - 1; k++){
							if (spl[k].matches(".")){
								if (spl[k+1].matches("He")){
									movieCharsGender.set(index, movieCharsGender.get(index) + 2);
								}
								
								else if (spl[k+1].matches("She")){
									movieCharsGender.set(index, movieCharsGender.get(index) - 2);
								}

								break;
							}
						}
					}
				}
				index++;
			}
			
			line = bf.readLine();
		}
		return movieCharsGender;
		
		//end of gender
		
	}
	
	/**printCharCounts takes the sorted mapping of characters and their count from the function sortMovieCharacters()
	 * and simply print them.
	 * 
	 * @throws IOException
	 */
	public void printCharCounts() throws IOException {
		Map<String, Integer> movieCharsCount =  sortMovieCharacters();
		System.out.println("//----------PRINTING CHARACTERS WITH THEIR RESPECTIVE COUNTS----------\\\\");
		System.out.println("NAME \t\t\t"+"COUNT \t\t\t");
		
		for (Entry<String, Integer> entry : movieCharsCount.entrySet()) {
			String temp = entry.getKey();
			if(temp.length() < 8) {
				System.out.println(temp + "\t\t\t" + entry.getValue());
			}
			else {
				System.out.println(temp + "\t\t" + entry.getValue());
			}
		}
	}
	
	public void printCharCountsWithGender() throws IOException {
		Map<String, Integer> movieCharsCount =  sortMovieCharacters();
		ArrayList<Integer> genderCount = determineCharGender();
		
		int index  = 0;
		System.out.println("//-----PRINTING CHARACTERS WITH THEIR RESPECTIVE COUNTS AND GENDER------\\\\");
		System.out.println("NAME \t\t\t"+"COUNT \t\t\t"+"GENDER \t \t");
		for (Entry<String, Integer> entry : movieCharsCount.entrySet()) {
			String temp = entry.getKey();
			
			String gen;
			int prob = genderCount.get(index);
			if (prob > 0) {
				gen = "MALE";
			}
			else if (prob < 0) {
				gen = "FEMALE";
			}
			else {
				gen = "UNDEFINED";
			}
			
			if (temp.length() < 8) {
				System.out.println(temp + "\t\t\t" + entry.getValue() + "\t\t\t" + gen);
			}
			else {
				System.out.println(temp + "\t\t" + entry.getValue() + "\t\t\t" + gen);
			}
			index++;
		}
	}


}
