  ***************************************************************************
  * NOTE                                                                    *
  *                                                                         *
  * The scardcom example is specifically for smart card vendors who wish to *
  * write a controlling Smart Card Service Provider (SCSP) to allow end     *
  * users easy access to their card's services.  Typical users of smart     *
  * cards will not find this example interesting.                           *
  *                                                                         *
  ***************************************************************************

This example provides a "bare bones" Smart Card Service Provider for an
imaginary smart card.  Most smart card vendors should be able to use
this example as a template for creating SCSPs to support their specific
smart cards.  When using this as a template:

    *  Change the names of the files to correspond to your smart card.
       (If all smart card vendors call their file "scardcom", there
       will be problems with files being overwritten!)

    *  Create new GUIDs for your ISCard implementation.  (For the same
       reason.)


How to compile
==============

1) Make sure all smart card hardware and software components have been setup
   correctly per %MSSDK%\Samples\Winbase\SCard\ReadMe.txt.
2) From the scardcom directory, run "NMAKE".

See %MSSDK%\ReadMe.txt for more information.

