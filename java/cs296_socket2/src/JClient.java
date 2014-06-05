import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
//import java.net.SocketTimeoutException;


public class JClient extends JChatComm{
	private ObjectOutputStream outputStream;
	private ObjectInputStream inputStream;
	private String ipString;
	private Socket mySocket;
		

	public JClient(String hostIpString) {
		super();
		ipString = hostIpString;		
	}
	
	void callServer() throws IOException {
		try {
			
			System.out.println(" Trying to connect to a server ...");
			mySocket = new Socket(InetAddress.getByName(ipString),5123);
			System.out.println("Connected to server :" + mySocket.getInetAddress().getHostName());
			
			outputStream = new ObjectOutputStream(mySocket.getOutputStream());
			outputStream.flush();//				

			inputStream = new ObjectInputStream(mySocket.getInputStream());
			System.out.println("Streams established. Ready for a chat ...");
			
			JPacket outJPacket = new JPacket("Free for chat?");
			JPacket inJPacket;
			
			outputStream.writeObject(outJPacket);
			System.out.println("Free for chat?");
			appendLog(outJPacket,"You");
			mySocket.setSoTimeout(10000);
			try {
				inJPacket = (JPacket) inputStream.readObject();
				appendLog(inJPacket,ipString);
				if(!inJPacket.messageString.equals("Sure. Let us begin")) {
					System.out.println("Expected rply \"Sure. Let us begin\". So Go back. Chat later. "); //to be removed
					
//					outJPacket.messageString = "832573407384687";
//					outputStream.writeObject(outJPacket);
					
					mySocket.close();
					inputStream.close();
					outputStream.close();
					return;
				}
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}catch (java.net.SocketTimeoutException e) {
				System.out.println("Sorry its timeout :( . May be later. "); //to be removed
				
//				outJPacket.messageString = "832573407384687";
//				outputStream.writeObject(outJPacket);
				
				mySocket.close();
				inputStream.close();
				outputStream.close();
				return;
			}
			
			
			mySocket.setSoTimeout(0);
			
			while(true) {
				System.out.print("Me: ");
				
				boolean toend = sendMessage(outputStream);
				if (toend) {
					break;
				}
				receiveMessage(inputStream,ipString);
			}
			printLog();			
			
		} catch (EOFException eofException) {
			System.out.println("chat ended");
		}
		mySocket.close();
		inputStream.close();
		outputStream.close();
		
	}

}
