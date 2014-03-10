import java.util.*;

public class LinkedList {
	public static void main(String[] args) {
		String[] things = {"apples","noobs","pwnge","bacon", "goat"};
		List<String> list1 = (List<String>) new LinkedList();
		
		for(String x : things)
			list1.add(x);
		
		String[] things2 = {"sausage","bacon","goal","harrypetter"};
		List<String> list2 = (List<String>) new LinkedList();
		for(String x : things2)
			list2.add(x);
		
		list1.addAll(c);
	}

}
