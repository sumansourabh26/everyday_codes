

import java.io.IOException;
import java.io.Serializable;
import java.net.Socket;
import java.net.ServerSocket;
import java.sql.Timestamp;

public class JMessage implements Serializable{
	public String messageString;
	
	public JMessage(String messageString) {
		this.messageString = messageString;
	}
}
