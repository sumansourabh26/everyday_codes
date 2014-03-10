class animal1{
	public void noise(){
		System.out.println("animal dont make noise");
	}
}

class dog1 extends animal1{
	public void noise(){
		System.out.println("ruff");
	}
}

class fish1 extends animal1{
	public void noise(){
		System.out.println("surp");
	}
}
public class polymorphism3 {
	public static void main(String[] args){
		animal1 list[] = new animal1[4];
		list[0] = new dog1();
		list[1] = new fish1();
		list[2] = new dog1();
		list[3] = new fish1();
		for(int i=0;i<4;i++){
			list[i].noise();
		}
		
	}
}
