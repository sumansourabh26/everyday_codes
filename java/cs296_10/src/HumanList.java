
public class HumanList {
	public human humlist[] = new human[5];
	int index = 0;
	
	void add(human x) {
		if(index < 5) {
			humlist[index] = x; 
			System.out.println(x+" added to the list");
		}
		
	}

}
