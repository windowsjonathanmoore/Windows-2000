======================================================
ODBC Access sample databases
======================================================

WTEDB_97.mdb and WTEDB_2000.mdb are Access sample database (for 
Access97 and Access2000) that can be used as a database for Web
Telephony Engine logging. They both containes a table called
WTETable.

To use logging to an ODBC database create an entry in the User DSN
and point it to the database. Then, configure WTE in the administration
tool to use logging to database, and set the DSN name and the table
name as the parameters.
