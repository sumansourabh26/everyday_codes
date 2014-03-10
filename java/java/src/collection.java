import java.util.*;

//the collections are dynamic...ex set, list.

public class collection {
	public static void main(String[] args) {
		
		String[] things = {"egg","laser","hats","pie"};
		List<String> list = new ArrayList<String>();
		
		//add array items to list
		for(String x : things){
			list.add(x);
		}
		
		String[] morethings = {"laser","hats"};
		List<String> list1 = new ArrayList<String>();
		for(String x : morethings){
			list1.add(x);
		}
		
		for(String x : list){
			System.out.print(x+ " ");
		}
		System.out.println();
		editlist(list, list1);
		for(String x : list){
			System.out.print(x+ " ");
		}
		
	}
	static void editlist(Collection<String> l1, Collection<String> l2){
		Iterator<String> it= l1.iterator();
		
		while(it.hasNext()){
			if(l2.contains(it.next()))
				it.remove();
		}
		
	}
}
