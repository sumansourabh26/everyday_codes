import java.awt.FlowLayout; //giv   es default layout
import java.awt.event.ActionListener; //listen to the events or waits for use to do some events
import java.awt.event.ActionEvent; // the events
import javax.swing.JFrame; // basic window feature
import javax.swing.JTextField; //somewhere we can type text
import javax.swing.JPasswordField; // password type text field
import javax.swing.JOptionPane; 

class class26 extends JFrame{
	JTextField field1,field2,field3;
	JPasswordField pwfield;
	class26(){
		super("super means title");
		setLayout(new FlowLayout()); 
		field1= new JTextField("text1",10);
		field2= new JTextField("text2",10);
		field3= new JTextField("text3",10);
		pwfield=new JPasswordField("secret",10);
		add(field1);add(field2);add(field3);add(pwfield);
		
		thehandler handle = new thehandler();
		field1.addActionListener(handle);//field2.addActionListener(handle);
		field3.addActionListener(handle);pwfield.addActionListener(handle);
		
	}
		
	private class thehandler implements ActionListener {
		public void actionPerformed(ActionEvent enter){
			String name[]={"","",""};char[] name1;
			name[0]=field1.getText();
			name[1]=field2.getText();
			name[2]=field3.getText();
			name1 =pwfield.getPassword();
			JOptionPane.showMessageDialog(null, String.format("%s %s %s %s",name[0],name[1],name[2],name1));
		}
	}
}

public class trial26 {
	public static void main(String[] args){
		class26 screen = new class26();
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		screen.setSize(500, 500);
		screen.setVisible(true);
	}
}
