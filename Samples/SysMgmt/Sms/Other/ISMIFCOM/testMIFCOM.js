var oShell = WScript.CreateObject("WScript.Shell");
var oInstallStatusMIF = new ActiveXObject("ISMIFCOM.InstallStatusMIF");
oInstallStatusMIF.Create("TESTMIF", "Microsoft", "TestProduct1", "1.0", "00000409", "111-11111-11", "This is a sample Install Status MIF indicating failure", 0);
oShell.Popup("Done calling IInstallStatusMIF::Create()");
