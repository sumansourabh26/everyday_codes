import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

class jlist_gui2 extends JFrame{
	private JList llist, rlist;
	private JButton moveButton;
	private static String[] food ={"baken", "wings","ham","beef","morebaken"};
	jlist_gui2(){
		super("title");
		setLayout(new FlowLayout());
		llist = new JList(food);
		llist.setVisibleRowCount(4);
		llist.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
		add(new JScrollPane(llist));
		
		moveButton = new JButton("move ==>");add(moveButton);
		rlist = new JList();
		rlist.setVisibleRowCount(4);
		rlist.setFixedCellWidth(100);
		add(new JScrollPane(rlist));
		
		moveButton.addActionListener(
				new ActionListener(){
					public void actionPerformed(ActionEvent event) {
						rlist.add
						
						
					}
				}
		);
	}
	
	
}

public class jlist2 {
	public static void main(String args[]) {
		jlist_gui2 screen = new jlist_gui2();
		screen.setSize(400,400);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
	}
}
