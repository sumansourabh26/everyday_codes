import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

class class_jlist extends JFrame{
	private JList list;
	private String[] colorname = {"black", "green", "red", "blue", "white"};
	private Color[] colors = {Color.BLACK, Color.GREEN, Color.RED, Color.BLUE, Color.WHITE};
	
	public class_jlist(){
		super("title");
		setLayout(new FlowLayout());
		
		list = new JList(colorname);
		list.setVisibleRowCount(3);
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		add(new JScrollPane(list));
		
		list.addListSelectionListener(
			new ListSelectionListener(){
				public void valueChanged(ListSelectionEvent e){
					getContentPane().setBackground(colors[list.getSelectedIndex()]);
				}
			}
		);
	}
}

public class jlist {
	public static void main(String[] args) {
		class_jlist screen = new class_jlist();
		screen.setSize(500,500);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}