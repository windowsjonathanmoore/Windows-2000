//
// Auto-generated using JActiveX.EXE 4.79.2337
//   (jactivex /nologo /d . /e /l "comsvcs.lst" C:\WINNT\System32\comsvcs.dll)
//
// WARNING: Do not remove the comments that include "@com" directives.
// This source file must be compiled by a @com-aware compiler.
// If you are using the Microsoft Visual J++ compiler, you must use
// version 1.02.3920 or later. Previous versions will not issue an error
// but will not generate COM-enabled class files.
//

package comsvcs;

import com.ms.com.*;
import com.ms.com.IUnknown;
import com.ms.com.Variant;

// Enum: tagCRMREGFLAGS

public interface tagCRMREGFLAGS
{
  public static final int CRMREGFLAG_PREPAREPHASE = 1;
  public static final int CRMREGFLAG_COMMITPHASE = 2;
  public static final int CRMREGFLAG_ABORTPHASE = 4;
  public static final int CRMREGFLAG_ALLPHASES = 7;
  public static final int CRMREGFLAG_FAILIFINDOUBTSREMAIN = 16;
}