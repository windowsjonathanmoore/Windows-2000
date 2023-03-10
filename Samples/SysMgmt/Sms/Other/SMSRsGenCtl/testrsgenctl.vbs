Option Explicit

    Const ADDPROP_NONE = &H0
    Const ADDPROP_GUID = &H2
    Const ADDPROP_KEY  = &H8
    Const ADDPROP_NAME = &H44

    Dim DDR
     
    Set DDR = CreateObject("SMSResGen.SMSResGen.1")

    DDR.DDRNew "Carpool3", "CarsRUs", "JAX"
    DDR.DDRAddString "VIN", "9FD7821T8B14751", 15, ADDPROP_NAME
    DDR.DDRAddString "License", "ABC123", 8, ADDPROP_NONE
    DDR.DDRAddString "Make", "Pontiac", 15, ADDPROP_NONE
    DDR.DDRAddString "Model", "Bonneville", 15, ADDPROP_NONE
    DDR.DDRAddInteger "ModelYear", 1996, ADDPROP_NONE
    DDR.DDRAddString "Color", "Green", 16, ADDPROP_NONE
    DDR.DDRAddString "SMSUniqueIdentifier", "VIN:9FD7821T8B14751", _
                     20, ADDPROP_GUID And ADDPROP_KEY

    DDR.DDRAddStringArray "ArrayProp", Array("One","Two","Three"), 20, ADDPROP_NONE
    DDR.DDRAddIntegerArray "IntArrayProp", Array(1, 2, 3), ADDPROP_NONE

    DDR.DDRWrite "Test.ddr"

    MsgBox "Created Test.ddr in the current directory"
	

