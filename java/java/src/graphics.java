import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;


class Peach extends JPanel{
	public void paintComponent(Graphics g){ //built-in method, used to build graphics on screen 
		super.paintComponents(g);
		this.setBackground(Color.WHITE);
		
		g.setColor(Color.BLACK);
		g.fillRect(25, 25, 10,10);
		g.setColor(new Color(24,236,19));
		g.fillRect(25, 65, 100, 30);
		g.setColor(Color.RED);
		g.drawString("this is a text", 25, 150);//this.setBackground(Color.RED);
	}
}

public class graphics {
	public static void main(String[] args) {
		JFrame f = new JFrame("title");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Peach p = new Peach();
		f.add(p);
		f.setVisible(true);
		f.setSize(300, 300);
	}
}
