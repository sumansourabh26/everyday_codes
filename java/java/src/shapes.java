import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class cs extends JPanel{
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		this.setBackground(Color.RED);
		g.setColor(Color.BLUE);
		g.drawLine(10, 25, 25, 10);
		
		g.setColor(Color.PINK);
		g.drawRect(10, 55, 100,30);
		
		g.setColor(Color.GREEN);
		g.fillOval(10, 85, 100, 30);
		
		g.setColor(Color.MAGENTA);
		g.fill3DRect(100, 160, 100, 50, true);
	}
	
}

public class shapes {
	public static void main(String[] args) {
		JFrame f = new JFrame("title");
		cs frame = new cs();
		f.add(frame);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(500, 500);
		f.setVisible(true);
		
	}

}
