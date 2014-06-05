
------------------------------------------------------------------------------------
Assignment 11 - PEER-TO-PEER CHAT IN JAVA
------------------------------------------------------------------------------------ 

Group No-18

1. Rohit Kumar 120050028
2. Suman Sourabh 120050031
3. Nitin Chandrol 120050035
------------------------------------------------------------------------------------

Note :- make compile builds a jar executable in the the project root folder itself. 
	For executing it as a server execute the command "java -jar jtalkG18.jar" and 
	for as a client "java -jar jtalkG18.jar <ip-address-of-server>".

------------------------------------------------------------------------------------
Brief description of classes and the relation between them:

1. JMessage :- Stores the messages communicated through chat.

2. JPacket :- Inherited from JMessage and additionally, it stores the date and time when
		the message was communicated.

3. JChatSession :- Stores the messages communicated between the client and server and 
		   contains a method to print it. This class is the superclass of JChatComm.

4. JChatComm :- Inherited from JChatSession. Has the main functionality to send and 
		recieve JPackets via socket.

5. JClient :- Inherited from JChatComm. Implements the client i.e. connects to the server 
	      via the protocol given and uses methods of JChatComm to enable conversation.

6. JServer :- Inherited from JChatComm. Implements the server i.e. waits for a client to 
	      connect and listens to it.

	----------------------------------------------------------
			INHERITANCE DIAGRAMS
	----------------------------------------------------------

			--------------------		
	      		-    JChatSession  -		
			--------------------
				 -
				---
				 -
			--------------------		
	      		-    JChatComm     -		
			--------------------
			    -	        -
			  -		 -
			-		  -
	     --------------------	--------------------		
	     -      JClient     -	-      JServer     -		
	     --------------------	--------------------
				

			--------------------		
	      		-      JMessage    -		
			--------------------
				 -
				 -
				 -
			--------------------		
	      		-      JPacket     -		
			--------------------


------------------------------------------------------------------------------------

We have taken care of all plagiarism policies and the whole assignment is our work.
For learning and implementing java sockets, servers etc. we have referred these sources-

1. Java SE 6 Documentation
2. Java tutorials by Oracle	-	http://docs.oracle.com/javase/tutorial/
3. Last but not the least, Google!


