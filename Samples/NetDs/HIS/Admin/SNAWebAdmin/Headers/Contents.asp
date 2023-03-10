<%@ LANGUAGE="VBSCRIPT"%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<title>SNA Contents Page</title>
<base target="main">
<style TYPE="text/css">
<!--
A:hover       {color: #FF0000}
.nounderline  {text-decoration: none;}
.aClass       {text-decoration: none; font-weight: bold; color: "#FFFFFF"}
.topicClass   {text-decoration: none; color: "#FFFFFF"}

.IE4linkClass {text-decoration: none; font: 12px Arial; font-weight: bold; color: #FFFFFF; line-height: 20px}
.IE4subtopicClass {text-decoration: none; font: 11px Arial; font-weight: normal; color: #FFFFFF}
.IE4selectedClass {text-decoration: none; font: 12px Arial; font-weight: bold; color: #FF0000}
.IE4divMargin {margin-left: 11px}
//-->
</style>
</head>

<body bgcolor="#000000" TOPMARGIN="0" LEFTMARGIN="0" LINK="#0000CC" VLINK="#666666" text="#FFFFFF">
<!--TOOLBAR_START-->
<script LANGUAGE="javascript">
<!--
function turnRed() {
	what = window.event.srcElement;
	if (what.tagName == "IMG") {
		what.src = what.src.substring(0,(what.src.indexOf(".gif"))) + "-red.gif";
		window.event.cancelBubble = true;
	}
}

function turnWhite () {
	what = window.event.srcElement
	if (what.tagName == "IMG") {
		what.src = what.src.substring(0,(what.src.indexOf("-red.gif"))) + ".gif";
		window.event.cancelBubble = true;
	}
}
//-->
</script>
<script LANGUAGE="JavaScript">
<!--
// IE4 script


var currentTopic = 0;
var originalTopic = 0;


var lonePicks = "#1#"
var loneHeaderVal = "#" + currentTopic + "#";

function reveal(id) {
    if (ver4Verify) {
        if (document.all["topic" + id].style.display == "") {
            // current menu is visible, so it should turn invisible
            document.all["topic" + id].style.display = "none";
            document.all["img" + id].src = "../../SNAWebAdmin/images/up.gif";
            document.all["img" + id].style.top = "1px";
            currentTopic = 0;
        }
        else {
            // current menu is invisible, so it should turn visible and all other menus should turn invisible
            if (currentTopic != 0) {
                // another topic is already visible, so hide it
                loneHeaderVal = "#" + currentTopic + "#";
                if (lonePicks.indexOf(loneHeaderVal) == -1) {
                    document.all["topic" + currentTopic].style.display = "none";
                    // an arrow exists, so change its state to closed (if above was true, then there is no arrow so we don't want to cause an error in the script)
                    document.all["img" + currentTopic].src = "../../SNAWebAdmin/images/up.gif";
                    document.all["img" + currentTopic].style.top = "1px";
                }
                else {
                // this is the first topic opened
                document.all["img" + currentTopic].src = "../../SNAWebAdmin/images/down.gif";
                document.all["img" + currentTopic].style.top = "1px";
                }
            }
            document.all["topic" + id].style.display = "";
            document.all["img" + id].src = "../../SNAWebAdmin/images/down.gif";
            document.all["img" + id].style.top = "4px";
            currentTopic = id;
            loneHeaderVal = "#" + currentTopic + "#";
        }
    }
}
//-->
</script>
<script
LANGUAGE="JavaScript">
<!--

function ver4Verify() {
 if (navigator.appVersion.indexOf("4.") != -1) {
  return true;
 }
 else {
  return false;
 }
}

//-->
</script>
<align="center">
<table>
  <tr>
    <td align="left"><table BORDER="0" CELLPADDING="0" CELLSPACING="0" width="172">
      <tr>
        <td width="172" height="0"><div ID="link1"><p><img
        src="../images/SNA_HEAD.GIF" alt="Loading..." width="130" height="50"></p>
        </div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20" WIDTH="172"><img ID="img1" BORDER="0" SRC="../images/greenright.gif"
        ALT="ZZZ" width="11" height="11"><a CLASS="IE4SelectedClass" HREF="Welcome.htm" Target="main">Welcome</a></td>
      </tr>
    </table>
    <div ID="topic1" STYLE="display: none" CLASS="IE4divMargin"></div>
<!--SNA Services-->
    <table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link2"></div></td>
      </tr>
	  <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img2" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(2)" target="_self">SNA Services</a></td>
      </tr>
    </table>
    <div ID="topic2" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../Services/MsSna_ServiceSna.asp" Target="main">-Host Integration Server Service</a><br>
    <a CLASS="IE4subtopicClass" HREF="../Services/MsSna_ServicePrint.asp" Target="main">-SNA Print Services</a><br>
    <a CLASS="IE4subtopicClass" HREF="../Services/MsSna_ServiceTN3270.asp" Target="main">-SNA TN3270 Services</a><br>
    <a CLASS="IE4subtopicClass" HREF="../Services/MsSna_ServiceTN5250.asp" Target="main">-SNA TN5250 Services</a><br>
    <a CLASS="IE4subtopicClass" HREF="../Services/MsSna_ServiceSharedFolder.asp" Target="main">-SNA AS400 Services</a><br>
<!--Domain Info-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link3"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img3" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(3)" target="_self">Domain Information</a></td>
      </tr>
    </table>
    <div ID="topic3" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/Domain/MsSna_Domain.asp" TARGET="main">-SNA Domain</a><br>
<!--Connections-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link4"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img4" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(4)" target="_self">Connections</a></td>
      </tr>
    </table>
    <div ID="topic4" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../Connections/MsSna_Connection8022Dlc.asp" Target="main">-802.2 Connection Information</a><br>
<!--Adapters-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link5"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img5" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(5)" target="_self">Adapters</a></td>
      </tr>
    </table>
    <div ID="topic5" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/Adapters/MsSNA_Adapter_Get.asp" Target="main">-All Installed Adapters (uses Get)</a><br>
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/Adapters/MsSNA_Adapter_Exec.asp" Target="main">-All Installed Adapters (uses WQL Query)</a><br>
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/Adapters/MsSNA_AdapterToMachine.asp" Target="main">-Adapter to Machine Query (refernce type Query)</a><br>
<!--Pools-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link6"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img6" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(6)" target="_self">Pools</a></td>
      </tr>
    </table>
    <div ID="topic6" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/Pools/MsSna_Pool.asp" Target="main">-Pools</a><br>
<!--Modes-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link7"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img7" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(7)" target="_self">APPC Modes</a></td>
      </tr>
    </table>
    <div ID="topic7" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/APPC/MsSNA_AppcMode.asp" Target="main">-Modes</a><br>
<!--3270LUs-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link8"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img8" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(8)" target="_self">3270 LU information</a></td>
      </tr>
    </table>
    <div ID="topic8" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/3270LUs/MsSna_LuDisplay.asp" Target="main">-3270 Display LUs</a><br>
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/3270LUs/MsSna_LuLua.asp" Target="main">-3270 LUA LUs</a><br>
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/3270LUs/MsSna_LuPrint.asp" Target="main">-3270 Print LUs</a><br>
    <a CLASS="IE4subtopicClass" HREF="../3270LUs/ALL_SNA_3270_LUs.asp" Target="main">-ALL 3270 LUs</a><br>
<!--APPC LUs-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link9"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img9" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(9)" target="_self">APPC LU Information</a></td>
      </tr>
    </table>
    <div ID="topic9" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/APPC/MsSna_LuAppcLocal.asp" Target="main">-Local APPC LUs</a><br>
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/APPC/MsSna_LuAppcRemote.asp" Target="main">-Remote APPC LUs</a><br>
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/APPC/MsSNA_AppcPartner.asp" Targer="main">-APPC Partnerships</a><br>
<!--Users-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link10"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img10" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(10)" target="_self">Users</a></td>
      </tr>
    </table>
    <div ID="topic10" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/Users/MsSna_ConfiguredUser.asp" Target="main">-Configured Users</a><br>
<!--SFGW-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link11"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img11" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(11)" target="_self">Shared Folder Gateway</a></td>
      </tr>
    </table>
    <div ID="topic11" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/SFGW/MsSna_AS400.asp" Target="main">-AS400 SFGW Definitions</a><br>
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/SFGW/MsSna_AS400Folder.asp" Target="main">-AS400 Folder Definitions</a><br>
<!--All Status-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link12"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img12" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(12)" target="_self">Master Status</a></td>
      </tr>
    </table>
    <div ID="topic12" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../Status/All_SNA_Services_Status.asp" Target="main">-Host Integration Server Services and Connection Status</a><br>
<!--Make Changes-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link13"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img13" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(13)" target="_self">Make Changes to SNA</a></td>
      </tr>
    </table>
    <div ID="topic13" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../Change/AddUser/Add_User.asp" Target="main">-Add Users to SNA Server</a><br>
    <a CLASS="IE4subtopicClass" HREF="../Change/DeleteUser/Delete_User.asp" Target="main">-Delete Users From SNA Server</a><br>
    <a CLASS="IE4subtopicClass" HREF="../Change/Add3270Lu/Add_3270LuToUser.asp" Target="main">-Add 3270 Display LU to User Record</a><br>
<!--Server Info-->
    </div><table BORDER="0" CELLPADDING="0" CELLSPACING="0">
      <tr>
        <td><div ID="link14"></div></td>
      </tr>
      <tr>
        <td VALIGN="CENTER" HEIGHT="20"><a CLASS="IE4SelectedClass" target="main">
        <img BORDER="0" ID="img14" SRC="../images/greenright.gif" STYLE="position: relative; top: 1px" width="11" height="11"></a></td>
        <td VALIGN="center"><a CLASS="IE4LinkClass" HREF="javascript:reveal(14)" target="_self">Host Integration Server Info</a></td>
      </tr>
    </table>
    <div ID="topic14" STYLE="display: none" CLASS="IE4divMargin">
    <a CLASS="IE4subtopicClass" HREF="../../SNAWebAdmin/Server/MsSna_Server.asp" Target="main">-Display Host Integration Server Information</a><br>
   
<!-- deleted from here-->
<!-- deleted to here-->
      </div>
    </table>
<p><p>

</body>




