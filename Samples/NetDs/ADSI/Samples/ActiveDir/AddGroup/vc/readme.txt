///////////////////////////////////////////////////////////////////////////////////////////
//
//  Adding a group in Active Directory
//
/////////////////////////////////////////////////////////////////////////////////////////
This sample adds a group in a specified container in Active Directory. The container is
normally an organizational unit.

Usage:
Addgroup <ADSPath> <Windows2000_Group> <DownLevel_Name> [<grouptype> {global | local | universal }] [<GroupSecurity> {Security  | NoSecurity}]

Where:
<ADSPath> is AdsPath of the container of the group
<Windows2000_Group> is the Windows 2000 Group name
<DownLevel_Name> is the NT 4 Downlevel compatible group name
Optional parms:
Grouptype describes the groups scope and must be one of the following global, local or universal
GroupSecurity is the security context of the group and must be one of the following "Security" or "NoSecurity"
Example:
Addgroup "LDAP://ou=My OU, DC=DNS_Domain_1,DC=Com" "Win2K Group Name" "Downlevel Name" global Security
Creates the group "Win2K Group Name" in the OU call "My OU" with global scope and adds the ability to secure the group.