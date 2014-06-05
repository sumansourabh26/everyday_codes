

import java.awt.print.Printable;
import java.io.IOException;
import java.io.Serializable;
import java.sql.Timestamp;
import java.util.Date;

public class JPacket extends JMessage implements Serializable{
//	Timestamp nowtTimestamp;
	Date date ;
	
	public JPacket(String messageString) {
		super(messageString);
		date = new Date();
	}

}
