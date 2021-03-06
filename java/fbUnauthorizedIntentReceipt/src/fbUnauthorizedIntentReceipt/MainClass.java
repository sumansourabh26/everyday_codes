package fbUnauthorizedIntentReceipt;


import java.lang.reflect.Method;

import edu.umd.cs.findbugs.BugInstance;
import edu.umd.cs.findbugs.BugReporter;
import edu.umd.cs.findbugs.Priorities;
import edu.umd.cs.findbugs.bcel.OpcodeStackDetector;

public class MainClass extends OpcodeStackDetector  {
	
	private BugReporter bugReporter;
	private boolean intentFound;
	boolean DEBUG = true;
	public MainClass(BugReporter bugReporter) {
		this.bugReporter = bugReporter;
	}
	
	public void visit(Method obj) {
		intentFound = false;
	}
	
	@Override
	public void sawOpcode(int seen) {
			if(seen == INVOKESPECIAL || seen == INVOKEVIRTUAL){
				String calledClassName = getClassConstantOperand();
		        String calledMethodName = getNameConstantOperand();
		        String calledMethodSig = getSigConstantOperand();
		        System.out.println(calledClassName+":"+calledMethodName+":"+calledMethodSig);
				if (seen == INVOKESPECIAL &&
						calledClassName.equals("android/content/Intent")&&
						calledMethodName.equals("<init>")) {
					if(calledMethodSig.equals("()V")){
						intentFound= true;
						if(DEBUG){
							System.out.println("intent found");
						}
					}
					else if (calledMethodSig.equals("(Ljava/lang/String;)V") || calledMethodSig.equals("(Ljava/lang/String;Landroid/net/Uri;)V") ) {
						intentFound=true;
						//setActionFound= true;
					}				
				}
				
				if((seen == INVOKEVIRTUAL &&
						((calledMethodName.equals("sendStickyBroadcast"))&& calledMethodSig.equals("(Landroid/content/Intent;)V"))&&
						intentFound)){
					if(DEBUG){
						System.out.println("without unauthorized intent found");
					}
					bugReporter.reportBug(new BugInstance(this, "WSB_STICKY_BROADCAST", Priorities.HIGH_PRIORITY)
	                .addClassAndMethod(this).addSourceLine(this));
				}
			}
	}
}
