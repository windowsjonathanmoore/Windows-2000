			Events News JAVA Sample


>>>To configure and build:

1. Add the following to CLASSPATH in User Environment Variables:
       
	- Name: CLASSPATH
	- <path to Services\Events\EventNewsJAVA folder>
	- <path to Services\Events\EventNewsJAVA\NewsEvent folder>
         	
2. Open the \Events\EventNewsJAVA\NewsEvent\helper\sampleConstants.java file, and change the paths of PersistSubs.dll, CascadeEvent.dll, and NewsEvent.dll to reflect their intended location.

    
3. Build all the projects in the following sequence:
    
	a) NewsEvent
	b) CascadeEvent
	c) PersistSubs
	d) NewsFlash
	e) NewsSubscriber

>>>To run the sample:

1. Run NewsSubscriber.exe, and do either step 2 (for direct events) or steps 3-5 (for cascade events).
    
2. Click Direct to receive the event directly from the publisher, and then click either Subscribe button.
    		 
3. To show that an event class can act both as a subscriber and a publisher, in App name, type the name for the cascade event application (for example, CASCADE) and proceed with steps 4 and 5.	 
	
4. To install the cascade event class, make sure the path in Dll Path is pointing to the location of CascadeEvent.dll, and then click Install.
	
5. Click Cascade to receive the event from the cascade event class, and then click the corresponding Subscribe button.

6. Run NewsFlash.exe.

7. Install the event class by making sure the path in EC DLL Path is pointing to the location of NewsEvent.dll, and then clicking Install.

8. In Symbol, type the symbol (for example, MSFT). 

9. In Headline, type the headline (for example, OVERSHOOT ANALYST EXPECTATIONS), and then click the Publish button. 
  
