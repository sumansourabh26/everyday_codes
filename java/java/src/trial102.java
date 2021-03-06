import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;
import org.dom4j.io.XMLWriter;

class Foo {

    public Document createDocument(Document document) {
        //Document document = DocumentHelper.createDocument();
        Element root = document.addElement( "root" );

        Element author1 = root.addElement( "author" )
            .addAttribute( "name", "James" )
            .addAttribute( "location", "UK" )
            .addText( "James Strachan" );
        
        Element author2 = root.addElement( "author" )
            .addAttribute( "name", "Bob" )
            .addAttribute( "location", "USgc" )
            .addText( "Bob McWhirter" );

        return document;
    }
}


public class trial102 {

	public static void main(String[] args) throws IOException, DocumentException {
		// TODO Auto-generated method stub
		SAXReader reader = new SAXReader();
		//Document document = reader.read("foo.xml");
		Document document = DocumentHelper.createDocument();
		//Foo dFoo = new Foo();
		Element root = document.getRootElement();
		document.addElement("sdklgjsdsdkjg");
		document.addElement("kvnsdnvndbmfnb mfdnvm fndj");
				
		
		XMLWriter outXmlWriter = new XMLWriter(
				new FileWriter( new File( "foo.xml" )));
		
		outXmlWriter.write(document);
		outXmlWriter.close();
		System.out.println("ksgnjn");
		


	}

}
