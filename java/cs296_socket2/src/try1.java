import java.util.*;
import com.sun.java_cup.internal.runtime.Scanner;


public class try1 {
	
	public static void main(String[] arg) {
		String s = "sdbdsmagvbdkjavn vkdjsanvkjdnsavkjbnfdjkvbf ndvb fd k,vb";
		s = s.substring(0, Math.min(s.length(), 140));
		System.out.println(s);
	}

}
//JPacket inputJPacket=new JPacket(""), outputJPacket;

//try {
//	inputJPacket = (JPacket) inputStream.readObject();
//} catch (ClassNotFoundException e) {
//	System.out.println("the pain in checking free for chat");
//	e.printStackTrace(); 
//}
//
//if(inputJPacket.messagesString.equals("Free for a chat?")) {
//	String messageString = in.nextLine();
//	outputStream.writeObject(new JPacket(messageString));
//	if(!messageString.equals("Sure. Let us begin")) {
//		break;
//	}
//}
//else {
//	break;
//}