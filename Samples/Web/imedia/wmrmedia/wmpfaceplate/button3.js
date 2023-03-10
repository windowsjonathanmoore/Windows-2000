/*
	The Button3 class
	A three-state button toggled by image events

	Notes:
		This script was designed to make it easier to put mouseover
	buttons onto web pages. The button has three defined states:
		Normal- It's appearance when it's just sitting there.
		Hilite- Usually some brighter version of the normal graphic
				called on a mouseover event.
		Active- A graphic showing the button is turned 'on', like 
				a play button of a tape recorder.

		This constructor assumes the three buttons are .jpg files, 
	whose names follow the convention:
					baseFilename_N.jpg
					baseFilename_H.jpg
					baseFilename_A.jpg
	where N, H, and A are the normal, hilite, and active graphics for the
	button in question. 

	For potential future use, I've added a variable that stores the button's
	current state. This could make it easier to add more sophisticated behavior
	to the button for different events (ex: hilite the button on mouseover only
	if it's in its normal state)

	Mod history:
		Added an InitState Method, to allow you to initialize the
			button's internal state without changing the graphic.
		Added a filename extension to the constructor, allowing you
			to use both .gif and .jpg files.
*/
function Button3(imgTagName, baseFilename, extension)
{
	this.theTagName	= imgTagName;
	this.currentState = 0;	

	//Use local image caching for speed
	this.normalImg	= new Image();
	this.hiliteImg	= new Image();
	this.activeImg	= new Image();

	this.normalImg.src = baseFilename + "_N" + extension;
	this.hiliteImg.src = baseFilename + "_H" + extension;
	this.activeImg.src = baseFilename + "_A" + extension;
}
/*
	Methods used by the Button class.
*/
Button3.prototype.SelectNormal = function()
{
	document[this.theTagName].src = this.normalImg.src;
	this.currentState = 0;	
}
Button3.prototype.SelectHilite = function()
{
	document[this.theTagName].src = this.hiliteImg.src;
	this.currentState = 1;	
}
Button3.prototype.SelectActive = function()
{
	document[this.theTagName].src = this.activeImg.src;
	this.currentState = 2;	
}
Button3.prototype.InitialState = function( initState )
{
	if( initState==0 || initState==1 || initState==2 )
		this.currentState = initState;	
}
