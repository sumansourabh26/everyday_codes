import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class class33 extends JFrame{
	private JLabel item1;
	
	public class33(){
		super("topic");
		setLayout(new FlowLayout());
		
		item1 = new JLabel("this is a sentence");
		item1.setToolTipText("this is done");
		
		add(item1);
	}
}

public class trial33 {
	public static void main(String[] args) {
		class33 screen = new class33();
		screen.setSize(200,200);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
