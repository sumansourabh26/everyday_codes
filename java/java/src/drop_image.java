import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

class drop extends JFrame{
	JComboBox label;
	JLabel picture;
	private String[] filename ={"pink", "green"};
	private Icon[] pics = {new ImageIcon(getClass().getResource("image/1.png")),new ImageIcon(getClass().getResource("image/2.png")) };
	
	public drop(){
		super("title");
		setLayout(new FlowLayout());
		
		label = new JComboBox(filename);
		add(label);
		
/*		label.addActionListener(
			new ActionListener(){
				public void ActionListener(){
					System.out.print("suman");
				}
				public void actionPerformed(ActionEvent e) {
					picture.setIcon(pics[label.getSelectedIndex()]);
					
				}
				
			}
		);*/
		label.addItemListener(
				new ItemListener() {
					public void itemStateChanged(ItemEvent arg0) {
						System.out.print("suman");
						picture.setIcon(pics[label.getSelectedIndex()]);
					}
				}
		);
		picture = new JLabel(pics[0]);
		add(picture);
	}
}
public class drop_image {
	public static void main(String[] args) {
		drop screen = new drop();
		screen.setSize(500,500);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}