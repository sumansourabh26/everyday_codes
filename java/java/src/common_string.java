//start with & end with

public class common_string {
	public static void main(String[] args) {
		String[] words = {"funk", "chunk", "furry","baconator"};
		
		//starts with
		for(String word : words){
			if(word.endsWith("unk"))
				System.out.println(word+" starts with fu");
		}
	}

}