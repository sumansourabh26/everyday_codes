import java.net.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class server extends JFrame{
	
	private JTextField usertext;
	private JTextArea chatwindow;
	private ObjectOutputStream output;
	private ObjectInputStream input;
	private ServerSocket server;
	private Socket connection;
	
	public server() {
		super("instant messege");
		usertext = new JTextField();
		usertext.setEditable(false); //without the connected 
		usertext.addActionListener(
			 new ActionListener() {
				
				public void actionPerformed(ActionEvent event) {
					sendMessage(event.getActionCommand());
					usertext.setText("");
				}
			 }
			 
		);
		add(usertext,BorderLayout.NORTH);
		add(new JScrollPane(chatwindow));
		setSize(300, 150);
		setVisible(true);
	}
	
}
