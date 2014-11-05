package httpServer;

import java.util.Date;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;

public class Server {
	static int countofconnections = 0;
	static HashMap<String, Integer> connectionCount = new HashMap<>();

	public static void main(String[] args) throws IOException {
		final int port = 14998;
		
		ServerSocket socketServerSocket = new ServerSocket(port);
		
		//for DOS Attack prevention		
		
		while(true) {
			Socket socketClientSocket = socketServerSocket.accept();
			countofconnections++;
			socketClientSocket.setKeepAlive(true);
			String IPAddress = socketClientSocket.getInetAddress().toString();
			
			if(connectionCount.containsKey(IPAddress)) {
				int countValue = connectionCount.get(IPAddress);
				connectionCount.put(IPAddress, countValue+1);
			}
			else {
				connectionCount.put(IPAddress, 1);
			}
			
			if(connectionCount.get(IPAddress) > 15) {
				socketClientSocket.close();
				System.out.println("attempt of dos from "+IPAddress);
			}
			System.out.println("total "+connectionCount.get(IPAddress)+ " from "+IPAddress);
			
			//Runnable handler = new TinyHttpdSocketHandler(socket);
			ThreadHandler threadHandler = new ThreadHandler(socketClientSocket,IPAddress);
			Thread socketThread = new Thread(threadHandler, "Thread for " + socketClientSocket.toString());
			
			//example "Thread for Socket[addr=/127.0.0.1,port=56025,localport=14998]"
			
			System.out.println("---------Opening new connection"+socketClientSocket.toString()+"at time "+(new Date()).toString()+"--------------"+
							" \n---------------------------------------------------connection count is now : " + countofconnections+ "-----------------------------------------------");
			socketThread.setDaemon(true);
			socketThread.start();

			
		}

	}

}
