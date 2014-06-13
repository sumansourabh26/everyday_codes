import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

class class101 extends JFrame{
	
	JTextField item1, item2, item3;
	JPasswordField pw;
	
	public class101(){
		
		super("101");
		setLayout(new FlowLayout());
		item1 = new JTextField(20);
		item2 = new JTextField("suman");
		item3 = new JTextField("uneditable");
		pw = new JPasswordField("pwd",10);
		
		item3.setEditable(false);
		
		thehandler handle = new thehandler();
		item1.addActionListener(handle);
		item2.addActionListener(handle);
		pw.addActionListener(handle);
		add(item1);add(item2);add(item3);
		add(pw);
	}
	
	private class thehandler implements ActionListener{
		
		public void actionPerformed(ActionEvent event){
			String st;
			if(event.getSource()==item1){
				JOptionPane.showMessageDialog(null, item1.getText());
			}
			else if(event.getSource()==item2){
				JOptionPane.showMessageDialog(null, item2.getText());
			}
			if(event.getSource()==pw){
				JOptionPane.showMessageDialog(null, pw.getName());
			}
		}
		
	}
}
public class trial101 {
	public static void main(String[] args) {
//		class101 screen = new class101();
//		screen.setSize(500,500);
//		screen.setVisible(true);
//		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
	}

}