import java.util.List;
import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.Node;
import org.dom4j.io.SAXReader;

public class TestDom4j
{
   /**
    * This method is used to load the xml file to a document and return it
    *
    * @param xmlFileName is the xml file name to be loaded
    * @return Document
    */
   public static Document getDocument( final String xmlFileName )
   {
      Document document = null;
      SAXReader reader = new SAXReader();
      try
      {
         document = reader.read( xmlFileName );
      }
      catch (DocumentException e)
      {
         e.printStackTrace();
      }
      return document;
   }

   /**
    * @param args
    */
   public static void main( String[] args )
   {
      String xmlFileName = "sample.xml";
      String xPath = "//Root/Address";
      Document document = getDocument( xmlFileName );
      List<Node> nodes = document.selectNodes( xPath );
      for (Node node : nodes)
      {
         String studentId = node.valueOf( "@studentId" );
         System.out.println("Student Id : " + studentId );
      }
   }
}