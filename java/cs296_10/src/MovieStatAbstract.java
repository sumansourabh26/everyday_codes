import java.io.IOException;
import java.util.Map;


public interface MovieStatAbstract {
	
	int countScriptWords() throws IOException;
	public void printCharCounts() throws IOException;
	public void printCharCountsWithGender() throws IOException;

}
