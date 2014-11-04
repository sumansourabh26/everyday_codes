package httpServer;

import java.util.Date;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;

public class Server {
	static int countofconnections = 0;

	public static void main(String[] args) throws IOException {
		int port = 14998;
		
		ServerSocket socketServerSocket = new ServerSocket(port);
		
		while(true) {
			Socket socketClientSocket = socketServerSocket.accept();
			countofconnections++;
			socketClientSocket.setKeepAlive(true);
			
			//Runnable handler = new TinyHttpdSocketHandler(socket);
			ThreadHandler threadHandler = new ThreadHandler(socketClientSocket);
			Thread socketThread = new Thread(threadHandler, "Thread for " + socketClientSocket.toString());
			
			//example "Thread for Socket[addr=/127.0.0.1,port=56025,localport=14998]"
			
			System.out.println("---------Opening new connection"+socketClientSocket.toString()+"at time "+(new Date()).toString()+"--------------"+
							" \n------------------------------connection count is now : " + countofconnections+ "--------------------------");
			socketThread.setDaemon(true);
			socketThread.start();

			
		}

	}

}
