import java.net.*;
import java.util.*;
import java.awt.*;
import java.applet.*;
import javax.swing.*;
import javax.swing.event.*;

/**
 * ditched because of the listener.
 * will be completed later.
 * @author suman
 *
 */

public class BuckySites extends JApplet{
	
	private HashMap<String, URL> websiteinfo;
	private ArrayList<String> titles;
	private JList mainlist;
	
	//inits 
	public void init() {
		websiteinfo = new HashMap<String,URL>();
		titles = new ArrayList<String>();
		
		//grabHTMLInfo();
		add(new JLabel("what is website you want to browse?"),BorderLayout.NORTH);
		mainlist = new JList(titles.toArray());
		
	}

}
