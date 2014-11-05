package httpServer;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.LinkedList;
import java.util.Queue;

public class QueueHandler extends Thread{
	Socket socketClientSocket;
	//BufferedReader inputFromClient;
	DataOutputStream outputToClient;
	Queue<Request> requests = new LinkedList<Request>();
	
	public QueueHandler(Socket socketClientSocket,DataOutputStream outputToClient) {
		this.socketClientSocket = socketClientSocket;
		//this.inputFromClient = inputFromClient;
		this.outputToClient = outputToClient;
	}
	
	void addRequestToQueue(Request r) {
		requests.add(r);
		
	}
	
	public void run() {
		
		while(!requests.isEmpty()) {
			System.out.println("Queue size is before this is: "+ requests.size());
			Request head = requests.remove();
			System.out.println("this request is "+head.messegeFromClient);
			try {
				responseSender(head.messegeFromClient, outputToClient);
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		}
		
	}
	
	void responseSender(String requestString, DataOutputStream outputToClient) throws IOException {
		String[] tokensStrings = requestString.split(" ");
		if(tokensStrings[0].equals("GET")) {
			String requestedFilename = tokensStrings[1];
			if(requestedFilename.startsWith("/")) {
				requestedFilename = requestedFilename.substring(1);
				if(requestedFilename.startsWith("~")) {
					requestedFilename = "/home/suman/users/"+requestedFilename.substring(1);
				}
				else {
					requestedFilename = "/home/suman/public_html/"+requestedFilename;
				}
				System.out.println(requestedFilename);
			}
			File filetosend = new File(requestedFilename);
			int filesize = (int) filetosend.length();
			FileInputStream fileStream = null;
			boolean fileFound = true;
			try {
				fileStream = new FileInputStream(requestedFilename);					
			} catch (Exception e) {
				fileFound = false;
			}
			
			if(fileFound) {
				byte[] fileinByte =new byte[filesize];
				fileStream.read(fileinByte);
				outputToClient.writeBytes("HTTP/1.1 200 Document Follows\r\n");
				outputToClient.writeBytes("Connection: keep-alive\r\n");
				outputToClient.writeBytes("Content-Length: "+filesize+"\r\n\r\n");
				outputToClient.write(fileinByte, 0, filesize);
			}
			else {
				outputToClient.writeBytes("HTTP/1.1 404 Document NOT FOUND\r\n\r\n");
				outputToClient.writeBytes("404 document not found");
				
			}
			outputToClient.flush();
		}				
		
		
	}
	
}
