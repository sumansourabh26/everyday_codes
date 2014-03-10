import javax.swing.JOptionPane;

public class gui1 {
	public static void main(String args[]){
		
		String a =(String)JOptionPane.showInputDialog(null,"head","enter a",JOptionPane.PLAIN_MESSAGE,null,null,"enter a here");
		JOptionPane.showMessageDialog(null, "the a is "+a, "it shows a", JOptionPane.DEFAULT_OPTION, null);
	}
}