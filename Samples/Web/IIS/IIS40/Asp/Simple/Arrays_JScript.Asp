<%@ LANGUAGE = JScript %>
<%
    // Declare a simple fixed size array
    aFixed = new Array(4);

    // Declare a dynamic (resizable) array
    aColors = new Array();


    // Assign values to fixed size array

    aFixed[0] = "Fixed";
    aFixed[1] = "Size";
    aFixed[2] = "Array";
    aFixed[3] = "Session ID: " + Session.SessionID;


    // Store values representing a simple color table
    // to each of the elements

    aColors[0] = "RED"; 
    aColors[1] = "GREEN"; 
    aColors[2] = "BLUE";  
    aColors[3] = "AQUA";
    aColors[4] = "YELLOW";
    aColors[5] = "FUCHSIA";
    aColors[6] = "GRAY";
    aColors[7] = "LIME";
    aColors[8] = "MAROON";
    aColors[9] = "NAVY";
    aColors[10] = "OLIVE";
    aColors[11] = "PURPLE";
    aColors[12] = "SILVER";
    aColors[13] = "TEAL";
%>

<HTML>
    <HEAD>
        <TITLE>Array Sample</TITLE>
    </HEAD>

    <BODY BGCOLOR="White" topmargin="10" leftmargin="10">

        <!-- Display Header -->

        <FONT SIZE="4" FACE="Arial, Helvetica">
        <B>Array Sample</B></FONT><BR>
      
        <HR SIZE="1" COLOR="#000000">

        <TABLE CELLPADDING=10 BORDER=1 CELLSPACING=0>
            <TR>
                <TD BGCOLOR=WHITE>
				    <FONT SIZE="3" FACE="Arial, Helvetica">
		                <B>A Resizable Array</B><br>
                    </FONT>
				</TD>

                <TD BGCOLOR=WHITE>
                    <FONT SIZE="3" FACE="Arial, Helvetica">
		                <B>A Fixed Size (4 element) Array</B><BR>
                    </FONT>
				</TD>
			</TR>

            <TR>                
                <TD>
					<%
						// Calculate Array Size

						nColors = aColors.length;
                         

						// Print out contents of resizable array
						// into table column

						for(i = 0; i < nColors; i++)
						{
							Response.Write("<FONT COLOR=" + aColors[i] + ">" + aColors[i] + "<br></FONT>");
						} 
					%>
                </TD>

                <TD>
                    <%
						// Calculate Array Size                        
                        
						nColors = aFixed.length;


						// Print out contents of fixed array into
						// table column

						for(i = 0; i < nColors; i++)
						{
							Response.Write(aFixed[i] + "<br>");
						} 
					%>
				</TD>
            </TR>
        </TABLE>
    </BODY>
</HTML>
