/*
	The ButtonAnim class
	A little javascript image replacement animation.
	
	Notes:
		This constructor assumes that all frames of the animations
	are .gif files, whose names follow the convention:
					baseFilename_n.gif
	where n is the frame number (zero based). The routine animates
	the given number of frames in animTime_ms milliseconds, then 
	pauses repeatDelay_ms.
		What's cool about this is that you can have any number of these
	guys on a given page. Page events can trigger them to turn on and off.



*/
function ButtonAnim(buttonName,
					imgTagName, 
					baseFilename, 
					numImages,
					animTime_ms,
					repeatDelay_ms)
{
	this.recursionObject = buttonName +".tick()";
	this.resetImgObject = buttonName + ".resetToFrameZero()";
	this.theTagName	= imgTagName;	
	this.timeoutId	= null;

	//Use caution: image filename convention is ZERO based!
	this.numFrames = numImages;

	//Time tick between frames
	this.frameTick = animTime_ms/numImages;

	//Delay between animated sequences
	this.repeatDelay = repeatDelay_ms;

	//The object needs to keep track of where it is
	//for event handling purposes.
	this.currentFrameNum = 0;

	//Object also has to know whether to run or not.
	this.isRunning = false;

	//Load all the images into local memory for speed.
	this.images = new Array(numImages);

	for(i=0; i<numImages; i++)
	{
		this.images[i] = new Image();
		this.images[i].src = baseFilename + "_" + i.toString() +".jpg";
	}
}

ButtonAnim.prototype.tick = function()
{
	//A function that references itself to do the
	//image replacement.

	if(!this.isRunning)
	{
		clearTimeout(this.timeoutId);
		this.timeoutId = null;
		return;
	}
	document[this.theTagName].src = this.images[this.currentFrameNum].src;
	this.currentFrameNum++;
	if(this.currentFrameNum == this.numFrames)
	{
		this.currentFrameNum = 0;
		this.timeoutId = setTimeout(this.recursionObject,	this.frameTick+this.repeatDelay);
	}
	else
	{
		this.timeoutId = setTimeout(this.recursionObject, this.frameTick);
	}
}
ButtonAnim.prototype.resetToFrameZero = function()
{
	document[this.theTagName].src = this.images[0].src;
}
ButtonAnim.prototype.startAnim = function()
{
	if(!this.isRunning)
	{
		this.isRunning = true;
		this.tick();
	}
}
ButtonAnim.prototype.stopAnim = function()
{
	clearTimeout(this.timeoutId);
	this.timeoutId = null;
	this.isRunning = false;
	setTimeout(this.resetImgObject, this.frameTick);
}
ButtonAnim.prototype.toggleAnim = function()
{
	if(this.isRunning == false)
	{
		this.startAnim();	
	}
	else
	{
		this.stopAnim();
	}
}

