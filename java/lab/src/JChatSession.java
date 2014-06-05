

import java.io.FileWriter;
import java.io.IOException;
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
	public void writeFile() throws IOException {
		Date d = new Date();
		int year = d.getYear()+1900;
		
		int dt, mt;
		dt = d.getDate();
		mt = d.getMonth();
		String dtString = Integer.toString(dt);
		String mtString = Integer.toString(mt);
		
		if (dtString.length() == 1) dtString = "0" + dtString;
		if (mtString.length() == 1) mtString = "0" + mtString;

		String filename = "chat_log_"+ dtString +"-"+mtString+"-"+ year%100+".txt";
	    FileWriter fw;
	    fw = new FileWriter(filename,true);
	    fw.write("\n ----------------- Printing Log ---------------------\n");
		for (int i = 0; i < source.size(); i++) {
		    fw.write(packets.get(i).date +" "+ source.get(i)+" : "+packets.get(i).messageString+"\n");//appends the string to the file
		}
		fw.write("\n ----------------- Log Finished ---------------------");
		fw.close();	
	 
	
	}
	

}
