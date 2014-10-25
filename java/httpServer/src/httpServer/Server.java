package httpServer;

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
			System.out.println(" connection count is now : " + countofconnections+ " ");
			
			new ThreadHandler(socketClientSocket).start();
			
		}

	}

}
