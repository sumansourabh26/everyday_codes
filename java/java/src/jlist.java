import java.awt.*;
import java.awt.event.*;
import java.util.Vector;

import javax.swing.*;
import javax.swing.event.*;

import com.sun.org.apache.bcel.internal.generic.NEW;

import sun.awt.windows.ThemeReader;

class class_jlist extends JFrame{
	private JList<person> list;
	private Color[] colors = {Color.BLACK, Color.GREEN, Color.RED, Color.BLUE, Color.WHITE};
	
	public class_jlist(){
		super("title");
		setLayout(new FlowLayout());
		DefaultListModel colornamePersons = new DefaultListModel();
		colornamePersons.addElement(new person("kdslgjkgn"));
		colornamePersons.addElement(new person("ssumanasknsd"));
		list = new JList(colornamePersons);
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

class person{
	String name;
	public person(String name) {
		this.name= name;
	}
	@Override
	public String toString() {
		return name+" is chutiya";
	}
	
}

public class jlist {
	public static void main(String[] args) {
		final String msg="Shutdown\nWill happen automatically in "; 
	    final JOptionPane op=new JOptionPane(null, JOptionPane.INFORMATION_MESSAGE);
	    op.showMessageDialog(op, "Waiting for server to confirm chat with you....please don't close this prompt", "WAIT...",JOptionPane.INFORMATION_MESSAGE);
	    final JDialog d=op.createDialog("Shutdown");
	    d.setModal(true);
		class_jlist screen = new class_jlist();
		screen.setSize(500,500);
		screen.setVisible(true);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}

}