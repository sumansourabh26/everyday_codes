import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class c13 extends JFrame{
	JButton l,r,m;
	Container container;
	FlowLayout lay;	
	
	c13(){
		super("title");
		setLayout(new FlowLayout());
		l = new JButton("left");add(l);
		r = new JButton("right");
		m = new JButton("middle");add(m);add(r);
		lay = new FlowLayout();
		r.addActionListener(new handler());
		l.addActionListener(new handler());
		m.addActionListener(new handler());
	}
		
	private class handler implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			if(event.getSource()==l){
				lay.setAlignment(FlowLayout.LEFT);
				//r.setBorderPainted(BorderLayout.EAST);
			}
			else if(event.getSource()==r){
				lay.setAlignment(FlowLayout.RIGHT);
			}
			else{ 
				lay.setAlignment(FlowLayout.CENTER);
			}
			lay.layoutContainer(container);				
		}
	}
}


class trial3 {
	public static void main(String[] args) {
		c13 frame = new c13();
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500,300);
	}

}
