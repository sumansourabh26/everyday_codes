import java.awt.FlowLayout; //gives default layout
import java.awt.event.ActionListener; //listen to the events or waits for use to do some events
import java.awt.event.ActionEvent; // the events
import javax.swing.*;
/*
import javax.swing.JFrame; // basic window feature
import javax.swing.JTextField; //somewhere we can type text
import javax.swing.JPasswordField; // password type text field
import javax.swing.JOptionPane; // open a windows
import javax.swing.JButton; // import the button that we can click
import javax.swing.Icon; //simply puts the icon 
import javax.swing.ImageIcon; //can use the image as icon
import javax.swing.JLabel; //is simply for the text*/

class gui  extends JFrame{
	private JButton reg, custom;
	private JTextField text;
	public gui(){
		super("this is the title");
		setLayout(new FlowLayout());
		
		text = new JTextField("its me",10);add(text);
		reg = new JButton("regular");add(reg);
		Icon a = new ImageIcon(getClass().getResource("image/1.png"));
		Icon b = new ImageIcon(getClass().getResource("image/2.png"));
		custom = new JButton("custom",a);add(custom);
		custom.setRolloverIcon(b );
		HandlerClas handle = new HandlerClas();
		text.addActionListener(handle);
		reg.addActionListener(handle);custom.addActionListener(handle);
	}
	private class HandlerClas implements ActionListener{
		public void actionPerformed(ActionEvent event){
			JOptionPane.showMessageDialog(null,String.format("%s", event.getActionCommand()));
		}
	}
}

public class trial_Gui{
	public static void main(String[] args){
		gui go = new gui();
		go.setSize(200, 200);
		go.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		go.setVisible(true);
	}
}
