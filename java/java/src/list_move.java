import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.event.*;

class clj extends JFrame{
	JList l1,l2;
	JButton b;
	private String[] names = {"yash", "nitin", "rohit", "manohar","pragya"};
	
	clj(){
		super("mover");
		setLayout(new FlowLayout());
		l1 = new JList(names);
		l1.setVisibleRowCount(4);
		l1.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
		l1.setAutoscrolls(true);
		add(new JScrollPane(l1));
		b = new JButton("move =>");
		add(b);
		l2 = new JList();
		add(new JScrollPane(l2));
		l2.setVisibleRowCount(3);
		l2.setFixedCellWidth(100);
		
		b.addActionListener(
			new ActionListener(){
				public void actionPerformed(ActionEvent e){
					l2.setListData(l1.getSelectedValues());
				}
			}
		);
	}
	
}

public class list_move{
	public static void main(String args[]) {
		clj screen = new clj();
		screen.setSize(400,400);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		
	}
}
