package httpServer;

import java.util.Date;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.SocketTimeoutException;
//import java.util.ArrayList;

public class ThreadHandler implements Runnable{
	Socket socketClientSocket;
	static int countOfRequest = 0;
	//ServerSocket socketServerSocket;
	
	ThreadHandler(Socket socketClientSocket){
		this.socketClientSocket = socketClientSocket;
		//this.socketServerSocket = socketServerSocket;
	}

	@Override
	public void run(){
		boolean alive = true;
		try {
			socketClientSocket.setSoTimeout(20000);
			BufferedReader inputFromClient = new BufferedReader(new InputStreamReader(socketClientSocket.getInputStream()));
			DataOutputStream outputToClient = new DataOutputStream(socketClientSocket.getOutputStream());
			
			
			String messegeFromClient = inputFromClient.readLine();
			
			while(messegeFromClient!=null && !messegeFromClient.equals("")) {
				
				String requestString = messegeFromClient;
				System.out.println(messegeFromClient);
			
				//String in = inputFromClient.readLine();
				
				while(messegeFromClient!=null && !messegeFromClient.equals("")) {
					messegeFromClient = inputFromClient.readLine();
					if(messegeFromClient.startsWith("Connection:")) {
						String[] connectionTimeString = messegeFromClient.split(" ");
						if(connectionTimeString[1].equals("keep-alive")) {
							alive = true;
						}
					}
				}
				countOfRequest++;
				System.out.println("request handled in the thread"+this.toString() +" is now: "+countOfRequest+"------time now is "+(new Date()).toString());
				
				responseSender(requestString, outputToClient); //to send response
				
				if(alive) {
					socketClientSocket.setKeepAlive(true);
					socketClientSocket.setSoTimeout(15000); //same connection will wait for 50 seconds for next request
				}
				else {
					socketClientSocket.close();
					System.out.println("closing socket");
					break;
				}
				messegeFromClient=inputFromClient.readLine();
				System.out.println("its ready now "+messegeFromClient);

			}
			socketClientSocket.close();
			Server.countofconnections--;
			System.out.println(socketClientSocket.toString()+"outside while loop. Remaning count of connections: "+ Server.countofconnections  );
			System.out.println("time now is "+(new Date()).toString());
			
		} catch (  SocketTimeoutException e) {
			try {
				socketClientSocket.close();
				Server.countofconnections--;
				System.out.println(socketClientSocket.toString()+"closed due to timeout. Remaning count of connections: "+ Server.countofconnections  );
				System.out.println("time now is "+(new Date()).toString());
				
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		} catch (IOException ie) {
			ie.printStackTrace();
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
