
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.util.*;

import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

import com.sun.org.apache.bcel.internal.generic.NEW;

public class JServer extends Thread{
	ServerSocket myServerSocket;
	Socket mySocket;
	ObjectOutputStream outputStream;
	ObjectInputStream inputStream;
	String ipString;
	JChatSession myChatSession;
	JChatComm mycomm;
	JServer thisServer = this;
	boolean toRun; 
	JFrame chatBox;
	
	JServer(Socket mysocket, ObjectInputStream inputStream, ObjectOutputStream outputStream){
		this.mySocket = mysocket;
		this.inputStream = inputStream;
		this.outputStream = outputStream;
		toRun = true;
	}
	
	public String toString() {
		return mySocket.getInetAddress().getHostName();
	}
	
	public void closeThis() throws IOException {
		outputStream.writeObject(new JPacket("CloseCode35736"));
		inputStream.close();
		outputStream.close();
		chatBox.setVisible(false);
		//chatBox.dispose();
		mySocket.close();
		toRun = false;
		mycomm.writeFile();
	}
	public void run() {
		mycomm = new JChatComm();
		myChatSession = new JChatSession();
		ipString = mySocket.getInetAddress().getHostName();		

		chatBox = new JFrame("Server chat with "+ ipString);
		chatBox.setLayout(new FlowLayout());
		final JTextField messageField = new JTextField("enter your message here");
		final JTextArea logArea = new JTextArea(20,30); 
		
//		final JScrollPane chatboxscroll = new JScrollPane(logArea);
//		chatboxscroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
//		chatboxscroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
//		chatBox.add(chatboxscroll);
		chatBox.add(logArea);
		final String smileys[] = {":)",":(",":'(",":/","O.o","-_-","\\m/" };
		final JComboBox box = new JComboBox(smileys);
		chatBox.add(box);
		logArea.setEditable(false);
		chatBox.add(messageField);
		chatBox.setSize(400, 600);
		chatBox.setVisible(true);
		chatBox.setDefaultLookAndFeelDecorated(true);
		chatBox.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		box.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					messageField.setText( messageField.getText()+" "+ smileys[box.getSelectedIndex()]);
					
				}
			}
		);
		messageField.addActionListener(
			new ActionListener() {
				String outMessage;
				public void actionPerformed(ActionEvent arg0) {
					outMessage = messageField.getText();
					JPacket toSend = new JPacket(outMessage); //
					mycomm.sendMessage(outputStream, toSend);
					//myChatSession.appendLog(toSend, "Me");
					SwingUtilities.invokeLater(
				         new Runnable(){
				            public void run(){
				               logArea.append("Me: "+outMessage +"\n");
				               messageField.setText("enter message");
				            }
				         }
				      );
				}
			}
		);
		
		chatBox.addWindowListener( new WindowAdapter()
		{
		    public void windowClosing(WindowEvent e) {
		    	try {
					closeThis();
					activeServerList a = new activeServerList();
					a.remove(thisServer);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
		    }
		});

//			outputStream = new ObjectOutputStream(mySocket.getOutputStream());
//			inputStream = new ObjectInputStream(mySocket.getInputStream());
		
		//JPacket temp = mycomm.receiveMessage(inputStream, ipString)
		
		while(true) {
			final JPacket inpacket = mycomm.receiveMessage(inputStream, ipString);
			System.out.println(inpacket.messageString);
			if(inpacket.messageString.equals("CloseCode35736")) {
				try {
					inputStream.close();
					System.out.println(" trying to close server on client close request");
					outputStream.close();
					chatBox.setVisible(false);
					//chatBox.dispose();
					mySocket.close();
					mycomm.writeFile();
					break;
				} catch (IOException e) {
					System.out.println(" trying to close server on client close request");
					e.printStackTrace();
				}
			}
			else {
				SwingUtilities.invokeLater(
				         new Runnable(){
				            public void run(){
				               logArea.append(ipString+":" + inpacket.messageString +"\n");
				            }
				         }
				      );
			}
			
		}
		//myChatSession.printLog();
		//myChatSession.clearLog();
		//System.out.println("Session Ended with client " + ipString + " ! \n");	
	}
}






