Note: If there is not a limit set on the server, this sample will fail with
a run time error -2147016694(8007200a) "The specified directory service attribute
or value does not exist" at line objMTA.GetInfoEx Array("Deliv-Cont-Length"), 0.
Once you set a value in the Exchange Admin program for the MTA Message size limit
then the code will work as expected.