import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

class ccc extends JFrame{
	private JButton b;
	private Color color = Color.WHITE;
	private JPanel panel;
	
	public ccc(){
		super("its title");
		panel = new JPanel();
		panel.setBackground(color);
		add(panel,BorderLayout.CENTER);
		b = new JButton("choose a color");
		add(b,BorderLayout.SOUTH);
		b.addActionListener(
				new ActionListener(){
					public void actionPerformed(ActionEvent event) {
						Color n = JColorChooser.showDialog(null,"choose",Color.RED);
						if(n!= null){
							color = n;
							panel.setBackground(n);
						}
						
					}
				}
		);
		
	}
}


public class color_choose {
	public static void main(String[] args) {
		ccc screen = new ccc();
		screen.setSize(400,400);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
