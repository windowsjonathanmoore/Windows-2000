/*
	The Trackbar class
	A series of lights that indicate a trackbar progress value

	Notes:
		This script is a discrete version of the progress trackbar 
	we see so often in user interfaces. It's designed so that the
	progress is proportional to the number of lights, which is determined
	by the user of the object. It's also designed so that clicking on
	a particular light will set all the lights up to and including the 
	one clicked, although that logic must be taken care of in script 
	at a higher level. This is because the progress indicated by the
	trackbar is usually the result of interaction with other objects.
		
		There are 4 images used by the trackbar object, which use the
	following filename indicators:

		_ON 	- The glowing light
		_ON_HI 	- Mouseover image for the glowing light.
		_OFF	- A non-glowing light. 
		_OFF_HI	- Mouseover image for the non-glowing light.

	The constructor also requires you to specify the filename extension
	(usually ".gif" of ".jpg"), to use different image formats for the 
	graphics.

	This object also requires that the IMG tag names take the form of
	Light0, Light1, Light2, etc., so that the routine has a valid target
	for image replacement.

	As for UI functionality, the non-running state should have no lights
	lit. For that case (ex: when the operation is stopped), there is a 
	ClearTrackbar method. Also, all lights should be lit only when you're
	at 100%. This requires some creative use of Math.floor() and index 
	adjustment to get the corresponding image indexes to track correctly.

	Mod history:
*/
function Trackbar(
				BaseImgTagName, 
				baseFilename,
				fileExtension,
				numImages
				)
{
	this.baseTagName	= BaseImgTagName;
	this.numImages 		= numImages;
	this.previousState 	= -1;			//Default value for no lights lit

	//Use local image caching for speed
	this.normalImg	= new Image();
	this.activeImg	= new Image();
	this.onHiliteImg	= new Image();
	this.offHiliteImg	= new Image();

	this.normalImg.src = baseFilename + "_OFF" + fileExtension;
	this.activeImg.src = baseFilename + "_ON" + fileExtension;
	this.onHiliteImg.src = baseFilename + "_ON_HI" + fileExtension;
	this.offHiliteImg.src = baseFilename + "_OFF_HI" + fileExtension;

	this.tagNameArray = new Array();
	this.trackerState = new Array();
	for( var i=0; i<numImages; i++)
	{
		this.tagNameArray[i] = BaseImgTagName + i.toString();
		this.trackerState[i] = 0;
	}
}
/*
	Methods used by the Trackbar class.
*/
Trackbar.prototype.SelectNormal = function(imgNumber)
{
	if(this.trackerState[imgNumber])
	{
		document[this.tagNameArray[imgNumber]].src = this.activeImg.src;
	}
	else
	{
		document[this.tagNameArray[imgNumber]].src = this.normalImg.src;
	}
}
Trackbar.prototype.SelectActive = function(imgNumber)
{
	//For progressive updates by the calling routine
	document[this.tagNameArray[imgNumber]].src = this.activeImg.src;
	this.trackerState[imgNumber] = 1;
}
Trackbar.prototype.SelectHilite = function(imgNumber)
{
	if(this.trackerState[imgNumber])
	{
		document[this.tagNameArray[imgNumber]].src = this.onHiliteImg.src;
	}
	else
	{
		document[this.tagNameArray[imgNumber]].src = this.offHiliteImg.src;
	}
}
Trackbar.prototype.LightUpToLED = function(imgNumber)
{
	if(imgNumber == this.previousState ) return;
	if(imgNumber < 0) imgNumber= 0;
	if(imgNumber >= this.numImages) imgNumber=this.numImages-1; //remember:zero based

	if(imgNumber > this.previousState ) //best-case; only light a few.
	{
		for(var i= this.previousState + 1; i<= imgNumber; i++)
		{
			document[this.tagNameArray[i]].src = this.activeImg.src;
			this.trackerState[i] = 1;
		}
		this.previousState = imgNumber;
	}
	else   //worst-case; must rebuild entire trackbar.
	{
		for(var i= 0; i<= imgNumber; i++)
		{
			document[this.tagNameArray[i]].src = this.activeImg.src;
			this.trackerState[i] = 1;
		}
		for(var i= imgNumber+1; i< this.numImages; i++)
		{
			document[this.tagNameArray[i]].src = this.normalImg.src;
			this.trackerState[i] = 0;
		}
		this.previousState = imgNumber;
	}
	//lastly, mouse is over this image; select the hilite
//	document[this.tagNameArray[imgNumber]].src = this.onHiliteImg.src;
}
Trackbar.prototype.ClearTrackbar = function()
{
	for(var i= 0; i< this.numImages; i++)
	{
		document[this.tagNameArray[i]].src = this.normalImg.src;
		this.trackerState[i] = 0;
	}
	this.previousState = -1;
}
