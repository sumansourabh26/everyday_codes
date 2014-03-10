import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

class ct extends JFrame{
	JTextField t1, t2;
	JLabel ins;
	
	ct(){
		super("text");
		setLayout(new FlowLayout());
		ins = new JLabel("enter text in any one");
		t1 = new JTextField(20);
		t2 = new JTextField(20);
		
		add(t1); add(t2);
		t1.addKeyListener(
			new KeyAdapter(){
				public void keyReleased(KeyEvent e){
					t2.setText(t1.getText());
				}
			}
		);
		t2.addKeyListener(
			new KeyAdapter(){
				public void keyReleased(KeyEvent e){
					t1.setText(t2.getText());
				}
			}
		);
	}
}

public class copy_text{
	public static void main(String args[]) {
		ct screen = new ct();
		screen.setSize(400,400);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		
	}
}
