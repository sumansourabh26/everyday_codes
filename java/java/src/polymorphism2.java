abstract class animal{
	
}

class AnimalList{
	private animal[] list= new animal[5];
	private int i = 0;
	public void add (animal a){
		if (i< list.length){
			list[i]=a;
			System.out.println(a+"added at index"+i);
			i++;
		}
	}
}

class dog extends animal{
	public String toString(){
		return String.format("dog", null);
	}
}

class fish extends animal{
	public String toString(){
		return String.format("fish", null);
	}
}

public class polymorphism2 {
	public static void main(String[] args){
		AnimalList alo = new AnimalList();
		dog d = new dog();
		fish f = new fish();
		alo.add(d);
	}
}
