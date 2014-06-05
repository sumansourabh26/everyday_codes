package cs296JTalk;

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
	
	public boolean sendMessage(ObjectOutputStream outputStream){
		String messageString = in.nextLine();
		messageString = messageString.substring(0, Math.min(messageString.length(), 140));
		JPacket outputJPacket = new JPacket(messageString);
		try {
			outputStream.writeObject(outputJPacket);
			outputStream.flush();
			appendLog(outputJPacket,"You");
		} catch (IOException ioException) 
			{
			System.out.println("\n pain in sendmessage \n");
		}
		return outputJPacket.messageString.equals("End Chat");
	}
	

	public boolean receiveMessage(ObjectInputStream inputStream, String ipString) {
		JPacket messageJPacketfinal = new JPacket(""); 
		try {
			messageJPacketfinal = (JPacket) inputStream.readObject();
			appendLog(messageJPacketfinal,ipString);
			System.out.println(ipString+ " : " + messageJPacketfinal.messageString);
		} catch (ClassNotFoundException e) {
			System.out.println("recieve message has some error \n");
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return messageJPacketfinal.messageString.equals("End Chat");
	}
}
