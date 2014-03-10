import java.awt.FlowLayout;
import javax.swing.JFrame; 
import javax.swing.JLabel;

class tuna1 extends JFrame{
	private JLabel item1;
	public tuna1(){
		super("its topic");
		setLayout(new FlowLayout());
		item1 = new JLabel("its a text");
		item1.setToolTipText("its done");
		add(item1);
	}
}

public class trial25 {
	public static void main(String args[]){
		tuna1 object1 = new tuna1();
		object1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		object1.setSize(200,200);
		object1.setVisible(true);
	}
} 
