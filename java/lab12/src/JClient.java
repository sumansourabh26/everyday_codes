import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.*;
//import java.net.SocketTimeoutException;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;


public class JClient extends Thread {
	
	JChatSession myChatSession;
	private ObjectOutputStream outputStream;
	private ObjectInputStream inputStream;
	private String ipString;
	private Socket mySocket;
	JChatComm mycomm;
	boolean toRun;
		

	public JClient(Socket mySocket){
		this.mySocket = mySocket;
		toRun = true;
	}
	
	public void run() {
		myChatSession = new JChatSession();
		mycomm = new JChatComm();
		ipString = mySocket.getInetAddress().getHostName();
		try {

			final JFrame chatBox = new JFrame("Client chat with "+ipString);
			chatBox.setLayout(new FlowLayout());
			final JTextField messageField = new JTextField("NOT CONNECTED", 20);
			messageField.setEditable(false);
			final JTextArea logArea = new JTextArea(20,30);
			final String smileys[] = {":)",":(",":'(",":/","O.o","-_-","\\m/" };
			final JComboBox box = new JComboBox(smileys);
			
			box.addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						messageField.setText( messageField.getText()+" "+ smileys[box.getSelectedIndex()]);
						
					}
				}
			);
			
//			final JScrollPane chatboxscroll = new JScrollPane(logArea);
//			chatboxscroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
//			chatboxscroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
//			chatBox.add(chatboxscroll);
			chatBox.add(logArea);
			chatBox.add(messageField);
			chatBox.add(box);
			logArea.setEditable(false);
			chatBox.setSize(400, 600);
			chatBox.setVisible(true);
			chatBox.setDefaultLookAndFeelDecorated(true);
			chatBox.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
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
						outputStream.writeObject(new JPacket("CloseCode35736"));
						inputStream.close();
						outputStream.close();
						chatBox.setVisible(false);
						//chatBox.dispose();
						mySocket.close();
						toRun = false;
						mycomm.writeFile();
					} catch (IOException e1) {
						e1.printStackTrace();
					}
			    }
			});
			//mySocket = new Socket(InetAddress.getByName(ipString),5123);
			outputStream = new ObjectOutputStream(mySocket.getOutputStream());
			outputStream.flush();			
			inputStream = new ObjectInputStream(mySocket.getInputStream());
			
			mycomm.sendMessage(outputStream,new JPacket("FreeForChatCode73t6384")); // checking if server is present
			mySocket.setSoTimeout(10000);
			JPacket messageJPacket = (JPacket) inputStream.readObject(); 
			if(!messageJPacket.messageString.equals("ServerIsListening")) { //checking if server is compatible one or not
				try {
					inputStream.close();
					outputStream.close();
					mySocket.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			mySocket.setSoTimeout(10000000);
			messageJPacket = (JPacket) inputStream.readObject();
			if (messageJPacket.messageString.equals("ChatAccept")) {
				messageField.setEditable(true);
				
				messageField.setText("Good to go");
			}
			
			while(toRun) {
				final JPacket inpacket = mycomm.receiveMessage(inputStream, ipString);
				if(inpacket.messageString.equals("CloseCode35736")) {
					try {
						inputStream.close();
						outputStream.close();
						chatBox.setVisible(false);
						//chatBox.dispose()
						mySocket.close();
						toRun = false;
						mycomm.writeFile();
					} catch (IOException e) {
						// TODO Auto-generated catch block
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
			
		} catch (IOException | ClassNotFoundException eofException) {
			eofException.printStackTrace();
			System.out.println("Chat Ended");
		}

		
	}

}
