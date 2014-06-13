import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.Element;
import org.dom4j.Node;
import org.dom4j.io.SAXReader;
import org.dom4j.io.XMLWriter;
import org.dom4j.DocumentHelper;

 
public class IntentSpoofing {
    //@SuppressWarnings("unchecked")
	static void reportError(File file, Node node,int i) throws DocumentException, IOException {
		Element root = null;
		Document document = null;
		if(!file.exists()) {
			document = DocumentHelper.createDocument();
			root = document.addElement("BugCollection");
		}
		else {
			SAXReader reader = new SAXReader();
			document = reader.read(file);
			root = document.getRootElement(); 
		}
		Element bugnode = root.addElement("BugInstance");
		bugnode.addAttribute("type", "WISPF_INTENT_SPOOFING");
		bugnode.addAttribute("priority", "2");
		bugnode.addAttribute("category", "WISPF");
		Element Class = bugnode.addElement("Class");
		Class.addAttribute("node_name", node.valueOf("@android:name"));
		
		bugnode.addAttribute("ShortDiscription", 
				"Intent Spoofing");
		bugnode.addAttribute("LongDiscription", 
				"Found a vulnerabilty to Intent Spoofing in receiver "+node.valueOf("@android:name"));
		if(i == 1) {
			bugnode.addAttribute("CDATA",
					"<p>The receiver is public but is not protected by any permission.<br>"
					+ "A malicious application can possibly call this receiver and access your app.<br>"
					+ "Add a permission if the reciever is used by some external broadcast/intent or simply turn the \"android"
					+ ":exported = off\" in case this reciever is used by only internal components only.</p>");
		}
		if(i == 2) {
			bugnode.addAttribute("CDATA","<p>Since the reciever has intent-filter(s) without any permission attribute.<br> "
					 +"A malicious application can possibly call this receiver and access your app.<br>"
					 +"Add a permission if the reciever is used by some external broadcast/intent or simply turn the \"android"
					 +":exported = off\" in case this reciever is used by only internal components only.</p>");
		}
		XMLWriter outXmlWriter = new XMLWriter(
				new FileWriter(file));
		outXmlWriter.write(document);
		outXmlWriter.close();
		
	}
    public static void main(String[] args) throws DocumentException, IOException {

        SAXReader reader = new SAXReader();
        
        Document document = reader.read("/home/suman/Desktop/com.net.pvr/AndroidManifest.xml");
        
        File xmloutFile = new File("output.xml");
   
        List<Node> nodes = document.selectNodes("/manifest/application/receiver");
        if (nodes.isEmpty()) {
			System.out.println("no receiver found");
		} else {
			for (Node node : nodes) {
				
	    		System.out.println("reveiver name:"+node.valueOf("@android:name"));
	    		if(node.valueOf("@android:exported").equals("false")) {
	    			System.out.println("this receiver is private");
	    		}
	    		else if (node.valueOf("@android:exported").equals("true")) {
	    			if(!node.valueOf("@android:permission").isEmpty()) {
	    				System.out.println("this reciever public is public buts protected by permission");	
	    			}
	    			else {
						System.out.println("this reciever is public and not protected");
						reportError(xmloutFile,node,1);
					}
				}
	    		else {
					if(!node.selectNodes("intent-filer").isEmpty() && 
							node.valueOf("@android:permission").isEmpty()) {
						System.out.println("the reciever is public and not protected");
						reportError(xmloutFile, node, 2);
					}
				}
	        }
		}
        
    }
}