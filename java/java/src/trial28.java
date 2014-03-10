import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class class28 extends JFrame{
	JButton b1,b2;
	JTextField field1;
	
	class28(){
		super("its the heading");
		setLayout(new FlowLayout());
		
		handler1 handle = new handler1();
		b1 = new JButton("its simple"); add(b1);b1.addActionListener(handle);
		b2 = new JButton("its not so"); add(b2);b2.addActionListener(handle);
		field1 = new JTextField("type over here",10); add(field1);
		
		Icon i1 = new ImageIcon(getClass().getResource("kidding.png"));
		Icon i2 = new ImageIcon(getClass().getResource("2.png"));
		
		b1.setIcon(i1); b1.setRolloverIcon(i2);
	}
	private class handler1 implements ActionListener{
		public void actionPerformed(ActionEvent event){
			String s="";
			s = field1.getText();
			JOptionPane.showMessageDialog(null, s);
		}
	}
}

public class trial28 {
	public static void main(String args[]){
		class28 frame = new class28();
		frame.setSize(300, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
