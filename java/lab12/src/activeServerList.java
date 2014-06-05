import javax.swing.DefaultListModel;
import javax.swing.JList;


public class activeServerList {
	static DefaultListModel<JServer> serverList = new DefaultListModel<JServer>();
	
	public activeServerList() {
	}
	public void add(JServer a) {
		serverList.addElement(a);	
		System.out.println(a+" added");
	}
	public void remove(JServer a) {
		for (int i = 0; i < serverList.size(); i++) {
			if (serverList.get(i).equals(a)) {
				System.out.println(serverList.get(i)+" removed");
				serverList.remove(i);
				break;
			}
		}
	}
	

}
