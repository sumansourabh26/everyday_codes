import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

class class101_icon extends JFrame{
	JButton reg, cus;
	Icon ic1 = new ImageIcon(getClass().getResource("image/1.png"));
	Icon ic2 = new ImageIcon(getClass().getResource("image/2.png"));
	
	class101_icon(){
		super("suman s cool");
		setLayout(new FlowLayout());
		
		reg = new JButton("reg");

		cus = new JButton("cus", ic1);
		cus.setRolloverIcon(ic2);
		add(reg); add(cus);
		handler handle = new handler(); 
	}
	
	private class handler implements ActionListener{
		public void actionPerformed(ActionEvent x){
			
		}
		
	}
	
	
}

public class trial101_icon {
	public static void main(String[] args) {
		class101_icon screen = new class101_icon();
		screen.setSize(500,500);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}