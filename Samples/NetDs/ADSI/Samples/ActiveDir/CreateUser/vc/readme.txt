///////////////////////////////////////////////////////////////////////////////
// Create Active Directory User
//
///////////////////////////////////////////////////////////////////////////////

Usage:
Createuser  /LDAP <LDAP Path> /UNAME <NT 5 user Name> /SAMNAME <Downlevel NT Name>  [/FILE <Info for user] [ /USER <user name> /PASS < password>]
Where:
<LDAP Path> is the DN of  container for the user object
<NT 5 User Name> is the CN of the user being created
<DownLevel Name> is the NT 4 downlevel Sam Account Name, < 20 characters
Optional parms:
/FILE 
<Info for User> is a filename containing detailed user information
/USER - alternative credentials to use to create the account
<user name>  User ID of alternative credentials
/PASS - password switch
<password> - password text of the user ID provided with /USER switch
ie:
Createuser /LDAP "LDAP://OU=My Ou,DC=My,DC=domain,DC=Com" /UNAME "Joe User" /SAMNAME "joeu" /USER administrator /PASS password
Creates user Joe User in the Organization Unit "My Ou" in My.Domain.Com with SAM Account name "joeu" as administrator
