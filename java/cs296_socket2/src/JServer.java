import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.util.*;

public class JServer extends JChatComm {
	private static final String JPacket = null;
	ServerSocket myServerSocket;
	Socket mySocket;
	ObjectOutputStream outputStream;
	ObjectInputStream inputStream;
	String ipString;
	private JPacket inputJPacket;
	
	public JServer() {
		super();
		
		try {
			myServerSocket = new ServerSocket(5123);
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		try {
			myServerSocket.setSoTimeout(10000000);
		} catch (SocketException e) {
			System.out.println("error in socket connection");
			e.printStackTrace();
		}
			
	}
	
	void acceptConnection() throws IOException {
		while(true) {
			try {
				System.out.println("Waiting for a client to connect ... "); 
				mySocket = myServerSocket.accept(); //wait for connection
				ipString = mySocket.getInetAddress().getHostName();
				
				System.out.println("Connected to client : " + ipString);
								
			
				outputStream = new ObjectOutputStream(mySocket.getOutputStream());
				inputStream = new ObjectInputStream(mySocket.getInputStream());
				
				JPacket outJPacket = new JPacket("Sure. Let us begin");
				JPacket inJPacket;
				
				try {
					inJPacket = (JPacket) inputStream.readObject();
					appendLog(inJPacket,ipString);
					if(!inJPacket.messageString.equals("Free for chat?")) {
						System.out.println("write \"Free for chat\" to request for chat...!");
						return;
					}
				} catch (ClassNotFoundException e) {
					e.printStackTrace();
				}
				
				outputStream.writeObject(outJPacket);
				System.out.println("Sure. Let us begin");
				appendLog(outJPacket,"You");
				
//				Scanner in;
//				in = new Scanner(System.in);
//				String messageString = in.nextLine();
//				JPacket outputJPacket = new JPacket(messageString);
//				outputStream.writeObject(outputJPacket);
//				if(!messageString.equals("Sure. Let us begin")) {
//					continue;
//				}
				
				while (true){
					boolean toend= receiveMessage(inputStream,ipString);
					if (toend) {
						break;
					}
				System.out.print("Me: ");
				sendMessage(outputStream);
				}
			}
			catch (SocketTimeoutException socketTimeoutException) {
				System.out.println("Server timed out. Restart the server for a new connection attempt");
				break;
			}
			printLog();
			clearLog();
			System.out.println("Session Ended with client " + ipString + " ! \n");
				
		}
		
	}
}






