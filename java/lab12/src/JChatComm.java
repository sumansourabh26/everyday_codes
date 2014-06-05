import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.*;

public class JChatComm extends JChatSession{
	Scanner in;
	public JChatComm() {
		super();
		in = new Scanner(System.in);
	}
	
	public boolean sendMessage(ObjectOutputStream outputStream, JPacket outputJPacket){
		try {
			outputStream.writeObject(outputJPacket);
			outputStream.flush();
			if(!outputJPacket.messageString.equals("CloseCode35736")) {
				appendLog(outputJPacket,"You");
			}
		} catch (IOException ioException) 
			{
			System.out.println("\n pain in sendmessage \n");
		}
		return outputJPacket.messageString.equals("End Chat");
	}
	

	public JPacket receiveMessage(ObjectInputStream inputStream, String ipString) {
		JPacket messageJPacketfinal = new JPacket(""); 
		try {
			messageJPacketfinal = (JPacket) inputStream.readObject();
			if(!messageJPacketfinal.messageString.equals("CloseCode35736")) {
				appendLog(messageJPacketfinal,"You");
			}
		} catch (ClassNotFoundException e) {
			System.out.println("recieve message has some error \n");
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return messageJPacketfinal;
	}
}
