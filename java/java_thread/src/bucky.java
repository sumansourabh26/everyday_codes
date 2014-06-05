
public class bucky {
	public static void main(String[] args) {
		int i = 4;
		while(i>0){
			Thread t1 = new Thread(new tuna("ritu1"));
			Thread t2 = new Thread(new tuna("ritu2"));
			Thread t3 = new Thread(new tuna("ritu3"));
			Thread t4 = new Thread(new tuna("ritu4"));
			
			t1.start();
			t2.start();
			t3.start();
			t4.start();
			i--;
		}
	}

}
