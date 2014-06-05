package cs296JTalk;

import java.net.Socket;
import java.net.ServerSocket;
import java.awt.print.Printable;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.*;


public class JChatSession {
	
	ArrayList<String> source;
	ArrayList<JPacket> packets;
	
	public JChatSession( ) {
		source = new ArrayList<String>();
		packets = new ArrayList<JPacket>();
	}
	
	public void appendLog(JPacket packet, String nameString) {
		source.add(nameString);
		packets.add(packet);
	}
	
	public void clearLog() {
		source.clear();
		packets.clear();
	}
	
	
	public void printLog() {
		System.out.println("\n ----------------- Printing Log ---------------------");
		for (int i = 0; i < source.size(); i++) {
			System.out.println(packets.get(i).date +" "+ source.get(i)+" : "+packets.get(i).messageString);
		}
		   System.out.println("----------------- Log Finished ---------------------\n");
	}
	

}
