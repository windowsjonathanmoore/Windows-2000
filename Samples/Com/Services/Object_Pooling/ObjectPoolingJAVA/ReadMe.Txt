				Object Pooling JAVA Sample

>>>To configure before building:

1. Create a new database (Name: Bank)
2. Create a new system Data Source Name (DSN) (Name: Account; User: sa  Password; Database: Bank).
3. Make any database setting changes in Object_Pooling\ObjectPoolingJAVA\ObjectPoolingComponent\Account\util\databaseSettings.java.
4. Set the User Environment Variable Classpath to point to the Object_Pooling\ObjectPoolingJAVA\ObjectPoolingComponent\Account folder.

>>>To build:

1. Open and build Object_Pooling\ObjectPoolingJAVA\ObjectPoolingComponent\Account\Account.vjp.
2. Open and build Object_Pooling\ObjectPoolingJAVA\ObjectPoolingClient\InitDatabase\InitDatabase.vjp.
3. Open Object_Pooling\ObjectPoolingJAVA\ObjectPoolingClient\GUI\ObjectPoolingClient.vjp.
   Add this COM wrapper: ObjectPoolingJAVA\ObjectPoolingComponent\Account\Account.dll
   Build ObjectPoolingClient.exe

>>>To configure:

1. Add the new COM+ application (Name: Object Pooling).
2. Add the new component (Account.dll).
3. Go to Properties of the Account.Account component, and then click the Activation tab.
4. Select the Enable object pooling check box.
5. Enter minimum pool size: 1.
6. Enter maximum pool size: 2.
7. Enter Creation timeout: 60000, and then click OK.
  

>>>To run:

1. Initialize the database for the first time by running  Object_Pooling\ObjectPoolingJAVA\ObjectPoolingClient\InitDatabase\InitDatabase.exe.		
2. Run the client  Object_Pooling\ObjectPoolingJAVA\ObjectPoolingClient\GUI\ObjectPoolingClient.exe.
3. Type in the data (valid account numbers fall in the range of 1-30).
4. Perform the desired operation (such as Balance, Debit, and so forth).

>>>To check object pooling:

1. In Component Services, click Components in Object pooling application.
2. On the toolbar, click the status view icon to see the pool status. 

 	  	
	 