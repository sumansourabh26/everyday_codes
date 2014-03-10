import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class c4 extends JFrame{
	private JButton lb,cb,rb;
	private FlowLayout layout;
	private Container container;
	
	c4(){
		super("title");
		layout = new FlowLayout();
		container = getContentPane();
		setLayout(layout);
		
		lb = new JButton("left"); add(lb);
		lb.addActionListener(
				new ActionListener(){
					public void actionPerformed(ActionEvent action){
						layout.setAlignment(FlowLayout.LEFT);
						layout.layoutContainer(container);
					}
					
			}	
		);
		cb = new JButton("center"); add(cb);
		rb = new JButton("right"); add(rb);
		rb.addActionListener(
				new ActionListener(){
					public void actionPerformed(ActionEvent action){
						layout.setAlignment(FlowLayout.RIGHT);
						layout.layoutContainer(container);
					}
			}	
		);
		
		cb.addActionListener(
				new ActionListener(){
					public void actionPerformed(ActionEvent action){
						layout.setAlignment(FlowLayout.CENTER);
						layout.layoutContainer(container);
					}
					
			}	
		);
	}
}

public class flow {
	public static void main(String[] args) {
		c4 screen = new c4();
		screen.setSize(400,400);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}

}
