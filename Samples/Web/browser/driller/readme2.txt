======================================================
Notes for "Drill" Sample
======================================================

There are two Drill samples, both do the same thing, however one is written using MFC and the other is written using Visual Basic.

OVERVIEW
========
The drill samples demonstrate hosting the WebBrowser control as part of another application. The buttons and address input are supplied by the hosting application and commands are sent to the WebBrowser control on the form. Entering a URL in the address field on the form will result in the WebBrowser control navigating to that page.

Additionally the Drill samples show how a hosting application can "drill" into the WebBrowser control and investigate the loaded HTML document. In this case the host walks the ALL collection of the document object of the loaded html page using Dynamic HTML and populate a list box with each element encountered.

NOTES on Driller
================
The sample is an MFC based ActiveX control container and is a dialog based application with control container support enabled.

The sample is a VC6.0 sample.

The two functions of interest are OnBtnGo() and
OnBtnDrill(). Both are in the file drillerDlg.cpp.

OnBtnGo:
The function uses the Navigate2 method of the IWebBrowser2
interface to navigate to the URL.

OnBtnDrill()
This function shows how to walk the object model for
an HTML page. It does the equivalent of the following
in script:


cnt = document.all.length;
for (i=0;i<cnt;i++)
{
 elem = document.all.item(i);
 output(elem.tagName);
 if (elem.tagName == "IMG")
    output(elem.href);
}

The code in C++ will be as follows:

   IDispatch* pDisp = pBrowser->GetDocument();

The document property gives access to the object model
for the HTML document. From here on one can walk
down the dynamic HTML object model.

For example, getting the IHTMLDocument2 interface
is equivalent to getting to the document object
in the object model. The document object exposes
the HTML document through a number of collections
and properties.

All the interfaces for the object model are defined
in MSHTML.h which is in the IE5 Headers.

Some of the methods of the IHTMLDocument2 interface are:

         get_all( IHTMLElementCollection   *p) 
         get_images( IHTMLElementCollection   *p) 
         get_applets( IHTMLElementCollection   *p) 
         get_links( IHTMLElementCollection   *p) 
         get_forms( IHTMLElementCollection   *p) 
         get_anchors( IHTMLElementCollection   *p) 
         get_scripts( IHTMLElementCollection   *p) 
         get_frames( IHTMLFramesCollection2   *p) 
         get_embeds( IHTMLElementCollection   *p) 
         get_plugins( IHTMLElementCollection   *p) 
       
Most of these methods returns a collection which corresponds to the
collection in the object model. For example get_all returns the all
collection,which is a collection of all the elements in the document.
Similarly get_images returns the images collection, get_links the
links collection, get_forms the forms collection and so on.

IDispatch* pDisp = pBrowser->GetDocument();

if (pDisp != NULL )
{
IHTMLDocument2* pHTMLDocument2;
HRESULT hr;
hr = pDisp->QueryInterface( IID_IHTMLDocument2,
(void**)&pHTMLDocument2 );
if (hr == S_OK)
{

IHTMLElementCollection* pColl;
hr = pHTMLDocument2->get_all( &pColl );

Using get_all we get the all collection of the object model.
This is the same as doing allColl = document.all from within
script.

Below is how to walk the all collection. The same
technique can be used to walk any collection. The idea
is to get the length using get_length and then
iterate through each element.

if (hr == S_OK)
{
LONG celem;
hr = pColl->get_length( &celem );

if ( hr == S_OK )
{
for ( int i=0; i< celem; i++ )
{
VARIANT varIndex;
varIndex.vt = VT_UINT;
varIndex.lVal = i;
VARIANT var2;
VariantInit( &var2 );
IDispatch* pDisp;

hr = pColl->item( varIndex,
var2, &pDisp );

The item method of the collection gives the element's dispatch
interface. Each element implements the IHTMLElement interface which
can be used to access the elements methods and properties.

Again look at the IHTMLElement interface in MSHTML.h for the
different methods that is has. There is a corresponding method
for every element property in the object model. So for example
if you want to get the tagName of the element use the get_tagName
method. The tagName is a the HTML tag of the element. For example
the tagName of the following line of HTML code:
<H1> This is Heading 1 </H1>
will be H1.

if ( hr == S_OK )
{

IHTMLElement* pElem;

hr =
pDisp->QueryInterface( IID_IHTMLElement, (void **)&pElem );

if ( hr == S_OK )
{

BSTR bstr;
hr =
pElem->get_tagName(&bstr);
CString strTag =
bstr;


An element could implement other interfaces depending on the
type of the element. For example if the element is an
image it will implement the IHTMLImgElement interface. The
IHTMLImgElement interface gives more information about
the IMG element. In this sample we use the IHTMLImgElement
to get the URL for the image.

IHTMLImgElement*
pImgElem;
hr =
pDisp->QueryInterface( IID_IHTMLImgElement, (void **)&pImgElem );
if ( hr == S_OK
)
{

pImgElem->get_href(&bstr);
strTag
+= " - ";
strTag
+= bstr;

pImgElem->Release();
}


m_listTags.AddString( strTag );


pElem->Release();
}
pDisp->Release();
}
}
}

pColl->Release();
}
pHTMLDocument2->Release();
}
pDisp->Release();
}
