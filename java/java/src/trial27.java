
import java.awt.FlowLayout;
import javax.swing.JFrame; 
import javax.swing.JLabel;

class class27 extends JFrame{
	JLabel text;
	
	class27(){
		super("its the title");
		JLabel text = new JLabel("suman is cool");
		setLayout(new FlowLayout());
		add(text);
		text.setToolTipText("its hovering");
	}
}

public class trial27 {
	public static void main(String args[]){ 
		class27 screen = new class27();
		screen.setSize(500, 500);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		screen.setVisible(true);	
	}
}
