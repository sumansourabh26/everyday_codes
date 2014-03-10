import java.awt.FlowLayout; //gives default layout
import java.awt.event.ActionListener; //listen to the events or waits for use to do some events
import java.awt.event.ActionEvent; // the events
import javax.swing.JFrame; // basic window feature
import javax.swing.JTextField; //somewhere we can type text
import javax.swing.JPasswordField; // password type text field
import javax.swing.JOptionPane; 

class tuna2 extends JFrame{
	private JTextField item1,item2,item3;
	private JPasswordField passworditem1;
	public tuna2(){
		super("super means title");
		setLayout(new FlowLayout()); 
		
		thehandler handler = new thehandler();
		item1 = new JTextField(10); add(item1);item1.addActionListener(handler);
		item2 = new JTextField("enter your text here"); add(item2);item2.addActionListener(handler);
		item3 = new JTextField("uneditable",10);add(item3);item3.setEditable(false);item3.addActionListener(handler);
		passworditem1 = new JPasswordField("rituloveyou26",10);add(passworditem1);passworditem1.addActionListener(handler);
		
	}
	private class thehandler implements ActionListener {
		public void actionPerformed(ActionEvent event){
			String string = "";
			if(event.getSource() == item1) 
				string= String.format("field1 : %s",event.getActionCommand());
			else if (event.getSource() == item2) 
				string= String.format("field2 : %s",event.getActionCommand());
			else if (event.getSource() == item3) 
				string= String.format("field3 : %s",event.getActionCommand());
			else if (event.getSource() == passworditem1) 
				string= String.format("passwordfield 1 : %s",event.getActionCommand() );
			JOptionPane.showMessageDialog(null, string);
		}
	}
}

public class event_handling {
	 public static void main(String args[]){
		 tuna2 object1 = new tuna2();
		 object1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 object1.setSize(400,300);
		 object1.setVisible(true);
	 }
}
