//its JRadioBox program that gives italic or bold on clicking in JRadioBox es.

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class class29 extends JFrame{
	private JTextField tf;
	private JCheckBox bold, italic;
	private JLabel text;
	
	
	class29(){
		super("its the heading");
		setLayout(new FlowLayout());
		
		tf = new JTextField("this is a sentance", 20);
		tf.setFont(new Font("Serif",Font.PLAIN,14));
		add(tf);
		
		text = new JLabel("don't kid me...i am serious");
		text.setFont(new Font("Serif",Font.PLAIN,20));add(text);
		bold = new JCheckBox("bold"); add(bold);
		italic = new JCheckBox("italic"); add(italic);

		handler handle = new handler();
		bold.addActionListener(handle);
		italic.addActionListener(handle);
	}
	private class handler implements ActionListener{
		public void actionPerformed(ActionEvent event){
			Icon kidding = new ImageIcon(getClass().getResource("image/k.png"));
			if(bold.isSelected()){
				if(italic.isSelected())
					JOptionPane.showMessageDialog(null, null, "kuch bhi", EXIT_ON_CLOSE, kidding);
				else tf.setFont(new Font("Serif",Font.BOLD,14));
			}
			else {
				if(italic.isSelected())
					tf.setFont(new Font("Serif",Font.ITALIC,14));
				else tf.setFont(new Font("Serif",Font.PLAIN,14));
			}					
		}
	}
}

public class trial29 {
	public static void main(String args[]){
		class29 frame= new class29();
		frame.setSize(280, 400);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
