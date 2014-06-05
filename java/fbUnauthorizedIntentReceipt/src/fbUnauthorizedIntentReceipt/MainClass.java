package fbUnauthorizedIntentReceipt;

import org.apache.bcel.classfile.JavaClass;
import org.apache.bcel.classfile.LocalVariableTable;
import org.apache.bcel.classfile.Method;
import org.apache.bcel.generic.ASTORE;
import org.apache.bcel.generic.ConstantPoolGen;
import org.apache.bcel.generic.INVOKESTATIC;
import org.apache.bcel.generic.INVOKEVIRTUAL;
import org.apache.bcel.generic.Instruction;
import org.apache.bcel.generic.InstructionHandle;
import org.apache.bcel.generic.InstructionList;
import org.apache.bcel.generic.LocalVariableInstruction;
import org.apache.bcel.generic.MethodGen;
import org.omg.CORBA.PRIVATE_MEMBER;

import edu.umd.cs.findbugs.BugInstance;
import edu.umd.cs.findbugs.BugReporter;
import edu.umd.cs.findbugs.Detector;
import edu.umd.cs.findbugs.Priorities;
import edu.umd.cs.findbugs.ba.ClassContext;
import edu.umd.cs.findbugs.ba.bcp.LocalVariable;
import edu.umd.cs.findbugs.bcel.OpcodeStackDetector;

public class MainClass extends OpcodeStackDetector  {
	
	private BugReporter bugReporter;
	private boolean intentFound;
	private boolean setActionFound;
	
	public MainClass(BugReporter bugReporter) {
		this.bugReporter = bugReporter;
	}
	
	public void visit(Method obj) {
		intentFound = false;
		setActionFound = false;
	}
	
	@Override
	public void sawOpcode(int seen) {
			String calledClassName = getClassConstantOperand();
	        String calledMethodName = getNameConstantOperand();
	        String calledMethodSig = getSigConstantOperand();

			if (seen == INVOKESPECIAL &&
					calledClassName.equals("android/content/Intent")&&
					calledMethodName.equals("<init>")) {
				if(calledMethodSig.equals("()V")){
					intentFound= true;
				}
				else if (calledMethodSig.equals("(Ljava/lang/String;)V") || calledMethodSig.equals("(Ljava/lang/String;Landroid/net/Uri;)V") ) {
					intentFound=true;
					setActionFound= true;
					
				}				
			}
			
			if(seen == INVOKEVIRTUAL &&
					calledClassName.equals("android/content/Intent")&&
					calledMethodName.equals("setAction")&&
					calledMethodSig.equals("(Ljava/lang/String;)Landroid/content/Intent")) {
				setActionFound = true;
			}
			
			if(seen == INVOKEVIRTUAL &&
					((calledMethodName.equals("startActivity")|| calledMethodName.equals("sendBroadcast"))&& calledMethodSig.equals("(Ljava/lang/String;)Landroid/content/Intent"))&&
					(calledMethodName.equals("startService") && calledMethodSig.equals("(Landroid/content/Intent;)Landroid/content/ComponentName"))&&
					setActionFound&&
					intentFound) {
				bugReporter.reportBug(new BugInstance(this, "WUIR_UNAUTHORIZED_INTENT_RECEIPT", Priorities.HIGH_PRIORITY)
                .addClassAndMethod(this).addSourceLine(this));
			}
	}
}
