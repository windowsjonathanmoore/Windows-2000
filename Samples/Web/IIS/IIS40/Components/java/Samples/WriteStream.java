/**
 * WriteStream: Using the framework to output binary data.
 */

package IISSample;

import aspcomp.*;
import com.ms.com.*;


public class WriteStream 
{

    static byte[] byteArray = {
            (byte)'T', (byte)'h', (byte)'i', (byte)'s', (byte)' ', 
            (byte)'b', (byte)'y', (byte)'t', (byte)'e', (byte)' ',
            (byte)'a', (byte)'r', (byte)'r', (byte)'a', (byte)'y',
            (byte)' ', (byte)'i', (byte)'s', (byte)' ', (byte)'b',
            (byte)'e', (byte)'i', (byte)'n', (byte)'g', (byte)' ',
            (byte)'w', (byte)'r', (byte)'i', (byte)'t', (byte)'t',
            (byte)'e', (byte)'n', (byte)' ', (byte)'u', (byte)'s',
            (byte)'i', (byte)'n', (byte)'g', (byte)' ', (byte)'t',
            (byte)'h', (byte)'e', (byte)' ', (byte)'<', (byte)'I',
            (byte)'>', (byte)'r', (byte)'e', (byte)'s', (byte)'p',
            (byte)'o', (byte)'n', (byte)'s', (byte)'e', (byte)'.',
            (byte)'w', (byte)'r', (byte)'i', (byte)'t', (byte)'e',
            (byte)'(', (byte)'b', (byte)'y', (byte)'t', (byte)'e',
            (byte)'[', (byte)']', (byte)')', (byte)'<', (byte)'/',
            (byte)'I', (byte)'>', (byte)' ', (byte)'m', (byte)'e',
            (byte)'t', (byte)'h', (byte)'o', (byte)'d', (byte)' ',
            (byte)'o', (byte)'f', (byte)' ', (byte)' ', (byte)'a',
            (byte)' ', (byte)'s', (byte)'t', (byte)'r', (byte)'e',
            (byte)'a', (byte)'m', (byte)'.', (byte)'<', (byte)'P', 
            (byte)'>'
    };

    public void writeBytes() 
    {
        Response response = AspContext.getResponse();

        // Use the response object to stream out binary data
        try 
        {
            response.write((byte[])byteArray);
        } 
        catch (Throwable e) 
        {
            response.write("<P>Error writing stream!<P>");
        }

    }

}
