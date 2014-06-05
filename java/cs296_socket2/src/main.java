import java.io.IOException;

import java.util.*;

public class main {

	public static void main(String[] args) {
		
		if(args.length == 0) {
			JServer myJServer = new JServer();
			try {
				myJServer.acceptConnection();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		else {
			JClient myclient;
			myclient = new JClient(args[0]);
			try {
				myclient.callServer();
			} catch (IOException e) {
				e.printStackTrace();
				System.out.println("\n stack trace error\n");
			}
		}
	}
	

}
