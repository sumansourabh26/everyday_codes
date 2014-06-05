import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class c2 extends JFrame{
	private String detail;
	private JLabel statusbar;
	
	c2(){
		super("title");
		statusbar = new JLabel("this is default");
		add(statusbar,BorderLayout.SOUTH);
		addMouseListener(new handler());
		addMouseMotionListener(new handler());
	}
	private class handler extends MouseAdapter{
		public void mouseClicked(MouseEvent event){
			detail = String.format("you clicked %d",event.getClickCount());
			if(event.isMetaDown())
				detail += "with right mouse key";
			else if(event.isAltDown())
				detail += "either center mouse button";
			else 
				detail += "with left mouse button";			
			statusbar.setText(detail);
		}
	}
}

public class adapter {
	public static void main(String[] args) {
		c2 screen = new c2();
		screen.setSize(400,400);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
