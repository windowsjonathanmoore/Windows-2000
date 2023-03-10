<% @LANGUAGE="jscript" %>
<HTML>
<HEAD>
<META NAME="Filename" CONTENT="imedia/netshow/asxfeatures/default.asp">
<%
  // -----------------------------------------------------------
  // MetaData constructor function
  // Authors/Editors enter document-specific data here to populate INC'd elements
  // -----------------------------------------------------------

	function MetaData()
	{
		// -----------------------------------------------------------
		// Generic information entered for every document
		// Put in HEAD TITLE and META tags
		// -----------------------------------------------------------

this.title = "MSDN Online Samples-ASX Features";
		this.description = "Home Page for the MSDN Online Web and Internet Samples Section";
		this.keywords = "reusing browser technology; networking; Active Desktop & Channels; DHTML, Data Binding; web content management; common controls; protocols; data formats; component development";
		this.robots = "All";

		this.author = "";
		this.posted = "";
		this.updated = "";

		// -----------------------------------------------------------
		// Optional DocDataBlock in footer-xxx.inc
		// TENTATIVE
		// -----------------------------------------------------------

		this.displayDocDataBlock = false;

		// -----------------------------------------------------------
		// Debug stuff - overrides actual document.pathname
		// Comment out to see page in actual context
		// Debug print code in footer-xxx.inc
		// -----------------------------------------------------------

		this.displayDebugInfo = false;
		this.debugPath = "";

		// -----------------------------------------------------------
		// InetSDK NavLinks data
		// -----------------------------------------------------------

		this.prevText = "";
		this.prevLink = "";
		this.nextText = "";
		this.nextLink = "";
		this.upText = "";
		this.upLink = "";
	}

	var oMD = new MetaData();
%>

<!-- #include virtual="/msdn-online/shared/inc/header.inc" -->
<!-- #include virtual="/workshop/templates/SampleDownloadScripts.inc" -->

<SCRIPT LANGUAGE="javascript"><!--

  // -----------------------------------------------------------
  // window_load()
  // Container function for load.
  // -----------------------------------------------------------

  function window_load()
  {
    if (oBD.getsNavBar) if ("function" == typeof(CommonLoad)) CommonLoad();
  }
  window.onload = window_load;

//--></SCRIPT>
</HEAD>
<BODY TOPMARGIN="0" LEFTMARGIN="0" MARGINHEIGHT="0" MARGINWIDTH="0" BGCOLOR="#FFFFFF">

<!-- #include virtual="/msdn-online/shared/inc/doctop.inc" -->
<!--#include virtual="/workshop/templates/SampObjects.inc" -->

<DIV CLASS="clsDocBody">

<!-- DOCUMENT CONTENT START -->

<!--
	NOTE: 
	The table below is included for every page belonging to a particular sample.
	It contains the dropdown list box w/ all of the source files for the particular sample.
-->

<script language="Javascript"><!--
function DownloadSamples() {  
     if ( CheckBrowser() )
        CAB0721_OnClick();
     else
        AlertMessage()             
}
//--></script>

<TABLE CELLPADDING="0" CELLSPACING="0" BORDER="0">
	<TR>
		<TD WIDTH="15" ROWSPAN="6"></TD>
		<TD COLSPAN="4"><I>Windows Media</I><BR><H2 CLASS="clsSampTitle">ASX Features</H2></TD>
	</TR>
	<TR>
		<TD HEIGHT="2" COLSPAN="4"></TD>
	</TR>
	<TR>
		<!-- DOWNLOAD_START -->
		<TD VALIGN="middle" WIDTH="22"><A HREF="Javascript:DownloadSamples()"><IMG ALIGN="middle" SRC="/downloads/graphics/download.gif" WIDTH="14" HEIGHT="16" BORDER="0"></A></TD>
		<TD CLASS="clsDemo" WIDTH="120"><A HREF="Javascript:DownloadSamples()">Download sample</A></TD>
		<!-- DOWNLOAD_END -->
		<!-- DEMO_START -->
		<TD VALIGN="middle" WIDTH="22"><A HREF="#" ONCLICK="if ( CheckDemo(4,3) ) showSampleStatus('advancedASX.asx','480','640'); return false;"><IMG ALIGN="middle" SRC="/downloads/graphics/demo.gif" WIDTH="16" HEIGHT="16" BORDER="0"></A></TD>
		<TD CLASS="clsDemo" WIDTH="80"><A HREF="#" ONCLICK="if ( CheckDemo(4,3) ) showSampleStatus('advancedASX.asx','480','640'); return false;">Demo</A></TD>
		<!-- DEMO_END -->
	</TR>
	<TR>
		<TD HEIGHT="10" COLSPAN="4"></TD>
	</TR>
	<!-- <TR>
		<TD HEIGHT="10" COLSPAN="4"><FONT FACE="MS Sans Serif, Arial, Helvetica, Swiss, Geneva" SIZE=2>View source file</FONT></TD>
	</TR> -->
	<TR>
		<TD COLSPAN="4"><FORM CLASS="samples">
<!-- LISTHEAD_START -->
		<SELECT STYLE="width:68pt;font-size:8pt" NAME="region" onchange="window.location=this.options[selectedIndex].value;this.selectedIndex=0;">
		<OPTION VALUE="Javascript:NoFileSelected()">view source</OPTION>
<!-- LISTHEAD_END -->
<!-- LISTBOX_START -->
<OPTION VALUE="Javascript:showSource('imedia/netshow/asxfeatures/advancedasx.asx','400','600')">advancedasx.asx</OPTION>
<!-- XBUILDER <A HREF="/downloads/samples/internet/ShowSource.asp?Filename=imedia\netshow\asxfeatures\advancedasx.asx"></A> -->
		</SELECT>
<!-- LISTBOX_END -->
		</FORM></TD>
	</TR>
</TABLE>

<P>
<B>Goal</B>
<P>To create a moderately advanced ASX file.


<P><B>Description</B>
<p>
An ASX file is an eXtensible Markup Language (XML)-based text file which references a Uniform Resource Locator (URL) for a piece of media content.  By using more advanced features of the ASX, you can do a host of things, such as: string multiple clips together, include meta data (title, author, copyright information), banner ads, and much more.</p>

<P><B>Code to Include</B>
<P>As before, to reference an ASX file, simply add the following code to your Web page:
<PRE>
&lt;A HREF="http://webserver/path/yourfile.asx"&gt;Link to Streaming Content&lt;/A&gt;
</PRE>
The browser will open this file and then launch the Windows Media Player to play this content.


<P><B>Code Examples</B>
<P>The code behind this ASX is extensively commented, piece by piece, to show you exactly how each tag functions.  <BR>
Look at the code in this sample ASX file by clicking on the "View Source" drop-down box above. 

</p>

<!-- DESCRIPTION_DETAIL_START 
<b>More Details</b><br>
<p>

</p>
DESCRIPTION_DETAIL_END --> 

<b>Browser/Platform Compatibility</b><br>
<p>
<P>Since ASXs work through a helper application, they are compatible with any browser that supports helper applications.
</p>

<!-- USAGE_START 
<b>Usage</b><br>
<p>

</p>
USAGE_END --> 

<!-- OTHER_START 
<b>Other</b><br>
<p>

</p>
<!-- OTHER_ENDN -->

<!-- RELATED_LINKS_START 
<b>Related Links</b><br>
<p>
The following links are to related articles.</P>
<UL>
<LI><A HREF="">http://</A>
</UL>
</p>
RELATED_LINKS_END --> 

<!-- DOCUMENTATION_LINKS_START 
<b>Documentation</b><br>
<p>
For detailed documentation on this sample, please go to <A HREF=""></A>
</p>
DOCUMENTATION_LINKS_END --> 

<!-- DOCUMENT CONTENT END -->

</DIV>
<!-- #include virtual="/msdn-online/shared/inc/footer.inc" -->
</BODY>
</HTML>

