' -------------------------------------------------------------
' V2.0
  Const szVersionNumber = "V2.0"
'
' By AliTu
'
' ADSI/VB Script to read ACS policy data from directory service
'
' -------------------------------------------------------------

' Option Explicit

On Error Resume Next

Dim lngError
    lngError = 0

Dim oProvider
Dim oTarget
Dim oArgs
Dim stContainer, stUser, stPass, stPol

Const ADS_ATTR_DEFAULT = 0

Const ADSTYPE_BACKLINK          	= 18
Const ADSTYPE_BOOLEAN           	= 6 ' VARIANT_BOOL
Const ADSTYPE_CASE_EXACT_STRING     	= 2 ' BSTR
Const ADSTYPE_CASE_IGNORE_STRING    	= 3 ' BSTR
Const ADSTYPE_CASE_IGNORE_LIST      	= 13
Const ADSTYPE_DN_STRING         	= 1 ' BSTR
Const ADSTYPE_EMAIL         		= 24    ' BSTR
Const ADSTYPE_FAXNUMBER         = 23    ' BSTR
Const ADSTYPE_HOLD          	= 20
Const ADSTYPE_INTEGER           = 7 ' long
Const ADSTYPE_INVALID           = 0 ' invalid
Const ADSTYPE_LARGE_INTEGER     = 10    ' Safe array of bytes
Const ADSTYPE_NETADDRESS        = 21    ' BSTR
Const ADSTYPE_NT_SECURITY_DESCRIPTOR    = 25
Const ADSTYPE_NUMERIC_STRING    = 5 ' BSTR
Const ADSTYPE_OBJECT_CLASS      = 12
Const ADSTYPE_OCTET_LIST        = 14
Const ADSTYPE_OCTET_STRING      = 8 ' VARIANT (uninterpreted byte strings, SAFEARRAY of unsigned chars)
Const ADSTYPE_PATH          	= 15    ' BSTR
Const ADSTYPE_POSTAL_ADDRESS    = 16    ' BSTR
Const ADSTYPE_PRINTABLE_STRING  = 4 ' BSTR
Const ADSTYPE_PROV_SPECIFIC     = 11
Const ADSTYPE_REPLICA_POINTER   = 22
Const ADSTYPE_TIMESTAMP         = 17    ' DATE
Const ADSTYPE_TYPED_NAME        = 19
Const ADSTYPE_UNKNOWN           = 26    ' unknown
Const ADSTYPE_UTC_TIME          = 9 ' BSTR

Const ACS_MAXIMUM_PROPERTY_NAME_LEN  =  35 

stUser = "administrator"
stpass = ""

Set oArgs = WScript.Arguments

If oArgs.Count <> 2 Then
   WScript.Echo ""
   WScript.Echo ""
   WScript.Echo "Readpol.vbs " & szVersionNumber & " - Read ACS Policies from Windows 2000 Directory Service "
   WScript.Echo ""
   WScript.Echo ""
   WScript.Echo "readpol [subnet|global] [user|all|config]"
   WScript.Echo ""
   WScript.Echo vbTab & "global: search under the global container"
   WScript.Echo vbTab & "subnet: search under this subnet container"
   WScript.Echo ""
   WScript.Echo vbTab & "user:   look for only this user name"
   WScript.Echo vbTab & "all:    to see all users"
   WScript.Echo vbTab & "config: to see subnet configuration"
   WScript.Echo ""
   WScript.Echo "Sample:"
   WScript.Echo vbTab & "readpol 172.31.240.0\/21 all"
   WScript.Echo vbTab & "readpol global all"
   WScript.Echo vbTab & "readpol 172.31.240.0\/21 config"
   WScript.Echo vbTab & "readpol 172.31.240.0\/21 YourUserName"
   WScript.Echo vbTab & "readpol global YourUserName"
   WScript.Echo ""
   WScript.Quit(0)
End If

WScript.Echo ""
WScript.Echo "Readpol.vbs " & szVersionNumber & " - Read ACS Policies from Windows 2000 Directory Service"


Set rootDSE= GetObject("LDAP://RootDSE")

stPol       = oArgs(1)
stPlace     = oArgs(0)

stSubnetContainer = "LDAP://CN=ACS,CN=" & oArgs(0) & ",CN=Subnets,CN=Sites," & rootDSE.Get("ConfigurationNamingContext")
stGlobalContainer = "LDAP://CN=ACS,CN=Services," & rootDSE.Get("ConfigurationNamingContext")


If stPlace = "global" Then 
   stContainer = stGlobalContainer
Else
   stContainer = stSubnetContainer
End If

Set oTarget = GetObject(stContainer)
If (Err.Number <> 0) Then
   lngError = Err.Number
   Err.Clear
   WScript.Echo ""
   WScript.Echo "Error 0x" + CStr(Hex(lngError)) + " occurred when binding to container " 
   WScript.Echo stContainer
   WScript.Echo ""
   WScript.Echo "Make sure that above container does exist and/or domain is correct"
   WScript.Echo ""
   WScript.Quit(0)
End If

WScript.Echo ""
WScript.Echo "Searching:" 
WScript.Echo stContainer

DisplayAll oTarget, stPol


' Search for an object under a given container
'
' --------------------------------------

Function  doesExist( ObjName, Container )

    Dim Child,Parent 
    Set Parent = GetObject(Container)

    For Each Child in Parent

        Child.GetInfo

        If Child.Name = ObjName Then
           doesExist = TRUE
           Exit Function
        End If
    Next
    
    doesExist = FALSE

End Function


' Enumarate all policies under subnet
'
' -----------------------------------   

Sub DisplayAll(oParent, User)

    Dim oChild
    Dim cnUser 
    cnUser = "CN=" + User

    If ( (User <> "all") And (User <> "config" ) ) Then
       WScript.Echo "Looking for polices of", User
       WScript.Echo ""
    End If

    For Each oChild in oParent

        Dim count, i
        oChild.GetInfo

        If ( isMatching( User, oChild ) = TRUE ) Then

           WScript.Echo   ""
           WScript.Echo   "Name: " & oChild.Name 
           WScript.Echo   "------------------------------------------" 

           count = oChild.PropertyCount
           For i=1 to count
               Dim pProperty
               set pProperty = oChild.Next

               If isAcs(pProperty.name) = TRUE Then
                  ListPropertyValues(pProperty)
               End If

               ' WScript.Echo pProperty.name  ',pProperty.ADsType
           Next 

        End If
    Next
End Sub


Function  isMatching( User, Child )
Dim stUserName
    stUserName = "2:CN="+User+",CN=Users," & rootDSE.Get("defaultNamingContext")

    isMatching = FALSE

    If User="all" Then
         isMatching = (Child.Name <> "CN=Config")
         Exit Function
    ElseIf User = "config" Then
         isMatching = (Child.Name = "CN=Config")
         Exit Function 
    Else
         count = Child.PropertyCount
         For j=1 to count
             Dim pProperty
             set pProperty = Child.Next
             If pProperty.name = "aCSIdentityName" Then
                for each a_value in pProperty.Values
                    'isMatching = (stUserName = a_value.CaseIgnoreString)
                    If Instr(1, a_value.CaseIgnoreString, User, 1) <> 0 Then  isMatching = TRUE
                    Child.Reset
                    Exit Function
                Next
             End If 
         Next
    End If

End Function


Function  isAcs( aName )

    Select Case aName
           Case "aCSIdentityName"                 isAcs = TRUE 
           Case "aCSDirection"                    isAcs = TRUE 
           Case "aCSServiceType"                  isAcs = TRUE 
           Case "aCSMaxTokenRatePerFlow"          isAcs = TRUE 
           Case "aCSMaxPeakBandwidthPerFlow"      isAcs = TRUE 
           Case "aCSMaxDurationPerFlow"           isAcs = TRUE 
           Case "aCSAggregateTokenRatePerUser"    isAcs = TRUE 
           Case "aCSMaxAggregatePeakRatePerUser"  isAcs = TRUE 
           Case "aCSTotalNoOfFlows"               isAcs = TRUE 

           Case "aCSMaximumSDUSize"               isAcs = TRUE 
           Case "aCSMinimumDelayVariation"        isAcs = TRUE 
           Case "aCSMinimumLatency"               isAcs = TRUE 
           Case "aCSMinimumPolicedSize"           isAcs = TRUE 
           Case "aCSPermissionBits"               isAcs = TRUE 
           Case "aCSPriority"                     isAcs = TRUE 
           Case "aCSTimeOfDay"                    isAcs = TRUE 

           Case "aCSAllocableRSVPBandwidth"     isAcs = TRUE 
           Case "aCSCacheTimeout"               isAcs = TRUE 
           Case "aCSDSBMDeadTime"               isAcs = TRUE 
           Case "aCSDSBMPriority"               isAcs = TRUE 
           Case "aCSDSBMRefresh"                isAcs = TRUE 
           Case "aCSEnableACSService"           isAcs = TRUE 
           Case "aCSEnableRSVPAccounting"       isAcs = TRUE 
           Case "aCSEnableRSVPMessageLogging"   isAcs = TRUE 
           Case "aCSEventLogLevel"              isAcs = TRUE 
           Case "aCSMaxDurationPerFlow"         isAcs = TRUE 
           Case "aCSMaxNoOfAccountFiles"        isAcs = TRUE 
           Case "aCSMaxNoOfLogFiles"            isAcs = TRUE 
           Case "aCSMaxPeakBandwidth"           isAcs = TRUE 
           Case "aCSMaxPeakBandwidthPerFlow"    isAcs = TRUE 
           Case "aCSMaxSizeOfRSVPAccountFile"   isAcs = TRUE 
           Case "aCSMaxSizeOfRSVPLogFile"       isAcs = TRUE 
           Case "aCSMaxTokenRatePerFlow"        isAcs = TRUE 
           Case "aCSNonReservedMaxSDUSize"      isAcs = TRUE 
           Case "aCSNonReservedMinPolicedSize"  isAcs = TRUE 
           Case "aCSNonReservedPeakRate"        isAcs = TRUE 
           Case "aCSNonReservedTokenSize"       isAcs = TRUE 
           Case "aCSNonReservedTxLimit"         isAcs = TRUE 
           Case "aCSNonReservedTxSize"          isAcs = TRUE 
           Case "aCSRSVPAccountFilesLocation"   isAcs = TRUE 
           Case "aCSRSVPLogFilesLocation"       isAcs = TRUE 
           Case "aCSServerList"                 isAcs = TRUE 

           Case Else     isAcs = FALSE   
    End Select
End Function


Sub ListPropertyValues(obj)

    Dim j
    Dim value
    Dim spaceSize

    spaceSize = ACS_MAXIMUM_PROPERTY_NAME_LEN - Len(obj.name) 
    if spaceSize < 0 Then spaceSize = 0

    j = 0
    for each value in obj.Values
        j = j + 1

        select case value.AdsType

            case ADSTYPE_BOOLEAN
                WScript.Echo obj.name & Space(spaceSize) & " : " & value.Boolean & " (Boolean)"
            case ADSTYPE_CASE_EXACT_STRING
                WScript.Echo obj.name & Space(spaceSize) & " : " & value.CaseExactString & " (CaseExactString)"
            case ADSTYPE_CASE_IGNORE_STRING
                WScript.Echo obj.name & Space(spaceSize) & " : " & value.CaseIgnoreString & " (CaseIgnoreString)"
            case ADSTYPE_DN_STRING
                WScript.Echo obj.name & Space(spaceSize) & " : " & value.DNString & " (DNString)"
            case ADSTYPE_INTEGER
                WScript.Echo obj.name & Space(spaceSize) & " : " & value.Integer & " (Integer)"
            case ADSTYPE_LARGE_INTEGER
                ' value.LargeInteger
                WScript.Echo obj.name & Space(spaceSize) & " : " & value.LargeInteger.HighPart & "-" & value.LargeInteger.LowPart & " (LargeInteger)"
                ' WScript.Echo vbTab & j & ": " & hex(value.LargeInteger.HighPart) & 
                ' "-" & hex(value.LargeInteger.LowPart) & " (LargeInteger)"
            case ADSTYPE_NUMERIC_STRING
                WScript.Echo obj.name & Space(spaceSize) & " : " & value.NumericString & " (NumericString)"
            case ADSTYPE_OCTET_STRING
                ' value.OctetString
                WScript.Echo obj.name & Space(spaceSize) & " : " & "<octet string>"
            case ADSTYPE_PRINTABLE_STRING
                WScript.Echo obj.name & Space(spaceSize) & " : " & value.PrintableString & " (PrintableString)"
            case ADSTYPE_NT_SECURITY_DESCRIPTOR
                ' value.SecurityDescriptor
                WScript.Echo  obj.name & Space(spaceSize) & " : " & "<nt security descriptor>"
            case ADSTYPE_UTC_TIME
                WScript.Echo  obj.name & Space(spaceSize) & " : " & value.UTCTime & " (UTCTime)"
            case else
                WScript.Echo  obj.name & Space(spaceSize) & " : " & "unknown AdsType = " & value.AdsType
        end select
    next
End Sub
