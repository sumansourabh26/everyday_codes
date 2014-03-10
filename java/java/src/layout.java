import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.event.*;

class c_layout extends JFrame{
	private JButton lb, cb, rb;
	private FlowLayout layout;
	private Container container;
	
	c_layout(){
		super("the title");
		layout = new FlowLayout();
		container = getContentPane();
		setLayout(layout);
		
		lb = new JButton("left"); add(lb);
		cb = new JButton("center"); add(cb);
		rb = new JButton("right"); add(rb);
		
		Handle hand = new Handle();
		lb.addActionListener(hand);
		cb.addActionListener(hand);
		rb.addActionListener(hand);
	}
		
	private class Handle implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			if(arg0.getSource() == lb){
				layout.setAlignment(FlowLayout.LEFT);
			}
			else if(arg0.getSource() == rb){
				layout.setAlignment(FlowLayout.RIGHT);
			}
			else if(arg0.getSource() == cb){
				layout.setAlignment(FlowLayout.CENTER);
			}
			layout.layoutContainer(container);	
		}	
	}
}

public class layout{
	public static void main(String args[]) {
		c_layout screen = new c_layout();
		screen.setSize(400,400);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		
	}
}