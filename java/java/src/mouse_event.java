import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

class c1 extends JFrame{
	private JPanel mousepanel;
	private JLabel statusbar;
	
	c1(){
		super("title");
		mousepanel = new JPanel();
		mousepanel.setBackground(Color.BLUE);
		add(mousepanel, BorderLayout.CENTER);
		
		statusbar = new JLabel ("default"); add(statusbar, BorderLayout.SOUTH);
		Handlerclass handler = new Handlerclass();
		mousepanel.addMouseListener(handler);
		mousepanel.addMouseMotionListener(handler);
	}
	private class Handlerclass implements  MouseListener, MouseMotionListener{
		public void mouseClicked(MouseEvent event){
			statusbar.setText(String.format("clicked at %d %d",event.getX(),event.getY()));
		}
		public void mouseReleased(MouseEvent event){
			statusbar.setText(String.format("released at %d %d",event.getX(),event.getY()));
		}
		public void mousePressed(MouseEvent event){
			statusbar.setText(String.format("pressed at %d %d",event.getX(),event.getY()));
		}
		public void mouseEntered(MouseEvent event){
			statusbar.setText(String.format("entered the area at %d %d",event.getX(),event.getY()));
			mousepanel.setBackground(Color.ORANGE);
		}
		public void mouseExited(MouseEvent event){
			statusbar.setText(String.format("exited at %d %d",event.getX(),event.getY()));
			mousepanel.setBackground(Color.RED);
		}
		//this are mouse motion events
		public void mouseDragged(MouseEvent event) {
			statusbar.setText(String.format("dragging at %d %d",event.getX(),event.getY()));
		}
		public void mouseMoved(MouseEvent event) {
			statusbar.setText(String.format("moving at %d %d",event.getX(),event.getY()));
		}
		
	}
	
}

public class mouse_event {
	public static void main(String[] args) {
		c1 screen = new c1();
		screen.setSize(400,400);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}

}