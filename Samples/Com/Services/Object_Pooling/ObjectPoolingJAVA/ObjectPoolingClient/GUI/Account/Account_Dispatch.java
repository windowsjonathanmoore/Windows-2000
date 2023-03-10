//
// Auto-generated using JActiveX.EXE 5.00.3167.1
//   ("D:\Program Files\Microsoft Visual Studio\VJ98\jactivex.exe"   /w /xi /X:rkc /l "D:\DOCUME~1\a-joest\LOCALS~1\Temp\jvcB.tmp" /nologo /d "D:\mssdk\Samples\Com\Services\Object_Pooling\ObjectPoolingJAVA\ObjectPoolingClient\GUI" "D:\mssdk\Samples\Com\Services\Object_Pooling\ObjectPoolingJAVA\ObjectPoolingComponent\Account\Account.dll")
//
// WARNING: Do not remove the comments that include "@com" directives.
// This source file must be compiled by a @com-aware compiler.
// If you are using the Microsoft Visual J++ compiler, you must use
// version 1.02.3920 or later. Previous versions will not issue an error
// but will not generate COM-enabled class files.
//

package account;

import com.ms.com.*;
import com.ms.com.IUnknown;
import com.ms.com.Variant;

// Dispatch-only interface Account_Dispatch
/** @com.interface(iid=7F6FAA87-5F51-4C2C-8E41-029F975ABF8C, thread=AUTO, type=DISPATCH) */
public interface Account_Dispatch extends IUnknown
{
  /** @com.method(dispid=100, type=METHOD, name="wait", returntype=VOID)
      @com.parameters([in,out,elementType=VARIANT,type=PTR] Parameter0, [in,out,elementType=VARIANT,type=PTR] Parameter1, [type=VARIANT] return) */
  public Variant wait(Variant Parameter0, Variant Parameter1);

  /** @com.method(dispid=101, type=METHOD, name="debit", returntype=VOID)
      @com.parameters([in,type=STRING] Parameter0, [in,type=I4] Parameter1) */
  public void debit(String Parameter0, int Parameter1);

  // hashCode UNMAPPABLE: Name is a keyword or conflicts with another member.
  //  public int hashCode();

  /** @com.method(dispid=103, type=METHOD, name="checkBalance", returntype=VOID)
      @com.parameters([in,type=STRING] Parameter0, [type=I4] return) */
  public int checkBalance(String Parameter0);

  /** @com.method(dispid=104, type=METHOD, name="credit", returntype=VOID)
      @com.parameters([in,type=STRING] Parameter0, [in,type=I4] Parameter1) */
  public void credit(String Parameter0, int Parameter1);

  /** @com.method(dispid=105, type=METHOD, name="transfer", returntype=VOID)
      @com.parameters([in,type=STRING] Parameter0, [in,type=STRING] Parameter1, [in,type=I4] Parameter2) */
  public void transfer(String Parameter0, String Parameter1, int Parameter2);

  // toString UNMAPPABLE: Name is a keyword or conflicts with another member.
  //  public String toString();

  // equals UNMAPPABLE: Name is a keyword or conflicts with another member.
  //  public boolean equals(Object Parameter0);

  // notify UNMAPPABLE: Name is a keyword or conflicts with another member.
  //  public void notify();

  // getClass UNMAPPABLE: Name is a keyword or conflicts with another member.
  //  public Object getClass();

  // notifyAll UNMAPPABLE: Name is a keyword or conflicts with another member.
  //  public void notifyAll();


  public static final com.ms.com._Guid iid = new com.ms.com._Guid((int)0x7f6faa87, (short)0x5f51, (short)0x4c2c, (byte)0x8e, (byte)0x41, (byte)0x2, (byte)0x9f, (byte)0x97, (byte)0x5a, (byte)0xbf, (byte)0x8c);
}
