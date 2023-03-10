
			crmfilesvj

This project is a sample Compensating Resource Manager (CRM) that creates and deletes files. It can be installed in a server application or in a library application. 

The crmfilesvj.Worker provides an interface for creating or deleting files.

The crmfilesvj.Compensator implements ICrmCompensatorVariants to receive transaction outcome notifications.


While the crmfilesvj.Worker requires a transaction, the crmfilesvj.Compensator should not have a transaction.

To build Crmfilesvj.dll:

1.	Run GenerateJavaWrappers.cmd. This batch file creates Java wrappers for %SystemRoot%\system32\comsvcs.dll and compiles Crmfilesvj.idl to produce Crmfilesvj.tlb.

2.	Put the crmfilesvj subdirectory on your Classpath System environment variable. The comsvcs and crmfilesvj class files in this subdirectory are required by crmfilesvj.dll.

3.	Build the comsvcs project.

4.	Build the crmfilesvj project.

