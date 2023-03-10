/*****************************************************************************
 * (C) 1999 Microsoft Corporation.  All rights reserved.                     *
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// This script shows how to change a property of all the applications to a fixed
// predetermined value
//

var WTE = WScript.CreateObject("WTE.Root");
var admin = WTE.Arrays.GetContainingArray();
var applications = admin.Applications;

apps = new Enumerator(applications);

try {
    for (; !apps.atEnd(); apps.moveNext() ) {
        var app = apps.item();
        app.OperatorExtension = "1160";
    }
    admin.Save();
    WScript.echo("All applications' operator extensions were changed");
}

catch(e) {
    WScript.echo(e.description);
}

