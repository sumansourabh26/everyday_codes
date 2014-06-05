import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.*;//.ServerSocket;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class jtalkG18 {
	static boolean toRun = true;
	public static JList<JServer> serverJList;
	
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		if(args[0].equals("server")) {
			ServerSocket serverSocket = new ServerSocket(5123);
			final activeServerList activeList = new activeServerList();
			
			final JFrame serverFrame = new JFrame("Server Side");
			serverFrame.setLayout(new FlowLayout());
			//final JList<JServer> serverJList;
			//final DefaultListModel<JServer> serverList = new DefaultListModel();
			serverJList = new JList(activeList.serverList);
			serverJList.setVisibleRowCount(3);
			serverJList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
			

			serverFrame.add(new JLabel("Clients waiting for a chat"));
			serverFrame.add(new JScrollPane(serverJList));
			serverFrame.setSize(400, 200);
			serverFrame.setDefaultLookAndFeelDecorated(true);
			serverFrame.setVisible(true);
			serverFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			serverJList.addListSelectionListener(
					new ListSelectionListener() {
						
						public void valueChanged(ListSelectionEvent arg0) {
							JServer server = (JServer) activeList.serverList.get(serverJList.getSelectedIndex());
							try {
								server.outputStream.writeObject(new JPacket("ChatAccept"));
							} catch (IOException e) {
								e.printStackTrace();
							}
							server.start();
							
						}
					}
			);
			serverFrame.addWindowListener( new WindowAdapter()
			{
			    public void windowClosing(WindowEvent e) {
			    	for(int i = 0; i < activeList.serverList.size(); i++) {
			    		JServer serverToClose =  activeList.serverList.get(i);
			    		try {
							serverToClose.closeThis();
						} catch (IOException e1) {
							e1.printStackTrace();
						}
			    	}
			    	serverFrame.setVisible(false);
					serverFrame.dispose();
					toRun = false;
			    }
			});
			
			
			
			while (toRun) {
				Socket mySocket = serverSocket.accept();
				ObjectOutputStream outputStream =  new ObjectOutputStream(mySocket.getOutputStream());
				ObjectInputStream inputStream = new ObjectInputStream(mySocket.getInputStream());
				
	            JServer server = new JServer(mySocket,inputStream, outputStream);
	            JPacket messageJPacket = (JPacket) inputStream.readObject();
	            outputStream.writeObject(new JPacket("ServerIsListening"));
	            activeList.add(server);
	        }
			
	    }
		else {
			JFrame clientFrame = new JFrame("Connect to Server");
			clientFrame.setLayout(new FlowLayout());
			
			final JTextField ipField  = new JTextField("enter the ip");
			JButton connectButton = new JButton("CONNECT...");
			clientFrame.add(new JLabel("Enter server's IP to connect..."));
			clientFrame.add(ipField,FlowLayout.CENTER);
			clientFrame.add(connectButton,FlowLayout.CENTER);
			clientFrame.setBackground(Color.BLUE);
			connectButton.addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						Socket mySocket = null;
						try {
							mySocket = new Socket(InetAddress.getByName(ipField.getText()),5123);
							JClient client = new JClient(mySocket);
							client.start();
							
						} catch (UnknownHostException e1) {
							e1.printStackTrace();
						} catch (IOException e1) {
							e1.printStackTrace();
						}
					}
				}
			);
			ipField.addActionListener(
				new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Socket mySocket = null;
						try {
							mySocket = new Socket(InetAddress.getByName(ipField.getText()),5123);
							JClient client = new JClient(mySocket);
							client.start();
							
						} catch (UnknownHostException e1) {
							e1.printStackTrace();
						} catch (IOException e1) {
							e1.printStackTrace();
						}						
					}
				}
			);
			clientFrame.setSize(400, 200);
			clientFrame.setDefaultLookAndFeelDecorated(true);
			clientFrame.setVisible(true);
			clientFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			
		}
	}
	

}
