# This sample demonstrates how to create/delete objects in DS

use OLE;             # Include OLE and Win32 extensions
use Win32;

# Create the Global Providers object
$adsiNameSpaces = CreateObject OLE 'ADsNameSpaces'
                  or warn "Couldn't create new instance of the ADSI Name Spaces Check your registry for ADsNameSpaces key under classes!!";

$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error0: ", Win32::FormatMessage($errNum);
   exit(1);
}
else
{
    print "Successfully created the NameSpaces object\n";
}

# Now get the LDAP Provider object 
$ldapNameSpace = $adsiNameSpaces->getobject("", "LDAP:");

$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error1: ", Win32::FormatMessage($errNum);
   exit(1);
}
else
{
    print "Successfully got the LDAP Provider object\n";
}

# Let us bind to a DS
$myDSObject = $ldapNameSpace->OpenDSObject("LDAP:/\/\NW01T1/\DC=NW01T1DOM,DC=NTDEV,DC=Microsoft,DC=Com", "cn=administrator,cn=users,dc=nw01t1dom,dc=ntdev,dc=microsoft,dc=com", "", 1);

$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error2: ", Win32::FormatMessage($errNum);
   exit(1);
}
else
{
    print "Successfully bound to an object\n";
}
###################################
# Create an User object in the DS #
###################################
$newObj = $myDSObject->create("User", "cn=Anandha");

$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error3: ", Win32::FormatMessage($errNum);
   exit(1);
}
else
{
    print "Successfully called IADsContainer::Create to create an object\n";
}

# We have to set the mandatory property samAccountName
$newObj->put("samAccountName", "Anandha");

$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error4: ", Win32::FormatMessage($errNum);
}
else
{
    print "Successfully set SamAccountName property on the created object\n";
}

# SetInfo on the object
$newObj->setinfo();

$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error5: ", Win32::FormatMessage($errNum);
}
else
{
    print "Successfully created the object in DS (SetInfo passes)\n";
}

# Now delete the User object
$myDSObject->delete("User", "cn=Anandha");

$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error6: ", Win32::FormatMessage($errNum);
}
else
{
    print "Successfully deleted the object\n";
}

# Close handles to the OLE objects
DestroyObject OLE $myDSObject;
$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error7: ", Win32::FormatMessage($errNum);
   exit(1);
}
else
{
    print "Successfully destroyed the object myDSObject\n";
}

DestroyObject OLE $ldapNameSpace;
$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error8: ", Win32::FormatMessage($errNum);
   exit(1);
}
else
{
    print "Successfully destroyed the object ldapNameSpace \n";
}

DestroyObject OLE $adsiNameSpaces;
$errNum = Win32::OLELastError;
if ($errNum != 0)
{
   print "OLE Error9: ", Win32::FormatMessage($errNum);
   exit(1);
}
else
{
    print "Successfully destroyed the object adsiNameSpaces \n";
}
