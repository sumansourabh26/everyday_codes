abstract class food{
	abstract void eat();
}

class tuna4 extends food{
	void eat(){
		System.out.println("this tuna is great");
	}
}

class potpie extends food{
	void eat(){
		System.out.println("this potpie is great");
	}
}

class fatty{
	public void digest(food x){
		x.eat();
	}
}

public class polymorphism1 {
	public static void main(String[] args){
		
	}
}
