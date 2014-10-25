package httpServer;


import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;

public class ThreadHandler extends Thread{
	Socket socketClientSocket;
	//ServerSocket socketServerSocket;
	
	ThreadHandler(Socket socketClientSocket){
		this.socketClientSocket = socketClientSocket;
		//this.socketServerSocket = socketServerSocket;
	}
/*	public void start() {
		
	}*/

	@Override
	public void run(){
		
		try {
			int count = 0;
			socketClientSocket.setSoTimeout(40000);
			BufferedReader inputFromClient = null;
			try {
				inputFromClient = new BufferedReader(new InputStreamReader(socketClientSocket.getInputStream()));
			} catch (IOException e2) {
				System.out.println("error in BufferedReader");
				e2.printStackTrace();
			}
			DataOutputStream outputToClient = null;
			try {
				outputToClient = new DataOutputStream(socketClientSocket.getOutputStream());
			} catch (IOException e1) {
				System.out.println("error in DataOutputStream");
				e1.printStackTrace();
			}
			
			String messegeFromClient = null;
			try {
				messegeFromClient = inputFromClient.readLine();
			} catch (IOException e2) {
				System.out.println("error in input from client");
				e2.printStackTrace();
			}
			
			while(messegeFromClient!=null) {
			
				String in = inputFromClient.readLine();
				while(in!=null && !in.equals("")) {
					//System.out.println(in);
					in = inputFromClient.readLine();
				}
				System.out.println(count++);	
				System.out.println( messegeFromClient+ "\n");
				String[] tokensStrings = messegeFromClient.split(" ");
				
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
						try {
							fileStream.read(fileinByte);
							outputToClient.writeBytes("HTTP/1.0 200 Document Follows\r\n");
							outputToClient.writeBytes("Content-Length: "+filesize+"\r\n\r\n");
							outputToClient.write(fileinByte, 0, filesize);
						} catch (IOException e) {
							System.out.println("error in writing response");
							e.printStackTrace();
						}
		
					}
					else {
						try {
							outputToClient.writeBytes("HTTP/1.0 404 Document NOT FOUND\r\n\r\n");
							outputToClient.writeBytes("404 document nahi hai be");
						} catch (IOException e) {
							System.out.println("error in case of file not found");
							e.printStackTrace();
						}
					}
					outputToClient.flush();
					socketClientSocket.setKeepAlive(true);
					socketClientSocket.setSoTimeout(5000);
				}
				System.out.println("waiting");
				messegeFromClient = inputFromClient.readLine();
			
				System.out.println(messegeFromClient);
				
			}
			socketClientSocket.close();
			System.out.println("skgvsdkvgjdklsjvl;");
		} catch (  SocketTimeoutException e) {
			try {
				socketClientSocket.close();
				System.out.println("socket closed");
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} catch (IOException ie) {
			ie.printStackTrace();
		}
					
	}
}
