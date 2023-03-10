/*  ********************************************************************************
    Enumerator.java ****************************************************************
    ********************************************************************************  */

package aspcomp;

/**
 * Common enumerator interface.
 */

public interface Enumerator 
    extends java.lang.Cloneable,
            java.util.Enumeration
{

/*  ********************************************************************************
    External (Public) Interface Methods ********************************************
    ********************************************************************************  */

    public void reset();


/*  ********************************************************************************
    External (Public) java.util.Enumeration Interface Methods **********************
    ********************************************************************************  */

    //    boolean hasMoreElements()
    //    Object  nextElement() throws NoSuchElementException


/*  ********************************************************************************
    External (Public) java.lang.Cloneable Interface Methods ************************
    ********************************************************************************  */

    //    public Object clone()
}
