Sample: BookSrvr

Purpose: This application demonstrates how to use the MSMQ Mail with C. It simulates a book server, 
which replies to queries done by Email. The user can send queries to a queue, specifying the book he 
is searching for, and whether he wishes to get all of the books or only those currently in stock.

Requirements:
MSMQ 2.0 or later must be installed.

Overview:
The receive queue name must be passed as a command line parameter to the application. After creating 
synchronization event with working thread, the thread opens this queue for receive access. The thread 
creates an asynchronous receive event. When a message arrives, its form is checked. The form name 
must be IPM.BOOKS.QUERY. There have to be a field of type string called “query”, indicating the book 
the user looks for, and a field of type boolean called “instock”, specifying if we should check among all 
books or among the books in stock only. If the received message is of different form, it is ignored. A 
response message is sent, listing the books in the library. Note that this book list contains either all books 
or only those in stock, according to the sender’s request. The query field is never used here.

Comments:
MSMQ Mail is not supported on DS disabled computers. In such case, the application will exit with an 
appropriate popup message.
