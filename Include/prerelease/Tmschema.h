//-----------------------------------------------------------------
//   TmSchema.h - Theme Manager schema (properties, parts, etc)
//-----------------------------------------------------------------
//   Note: this file is normally #include-ed twice a single .cpp 
//         file.  The 2nd time, SCHEME_STRINGS should be defined.  
//         This allows the enums and strings to be kept in a 
//         single logical table and ensure they stay in sync with
//         each other.
//-----------------------------------------------------------------
#if (defined(SCHEMA_STRINGS)) || (! defined(TMSCHEMA_H))
//-----------------------------------------------------------------
#define TMSCHEMA_H
//-----------------------------------------------------------------
#include "SchemaDef.h"
//-----------------------------------------------------------------
#define THEMEMGR_VERSION 1  // increment if order of props changes or 
                            // any props are deleted (will prevent loading
                            // of controlsets that use older version
//-----------------------------------------------------------------
BEGIN_TM_SCHEMA(ThemeMgrSchema)

//-----------------------------------------------------------------
//   TM_ENUM (must also be declared in PROPERTIES section)
//-----------------------------------------------------------------
BEGIN_TM_ENUM(BGTYPE)
    TM_ENUM(BT, IMAGEFILE)
    TM_ENUM(BT, BORDERFILL)
    TM_ENUM(BT, NTLFILE)
    TM_ENUM(BT, NONE)
END_TM_ENUM()

BEGIN_TM_ENUM(IMAGELAYOUT)
    TM_ENUM(IL, VERTICAL)
    TM_ENUM(IL, HORIZONTAL)
END_TM_ENUM()

BEGIN_TM_ENUM(BORDERTYPE)
    TM_ENUM(BT, RECT)
    TM_ENUM(BT, ROUNDRECT)
    TM_ENUM(BT, ELLIPSE)
END_TM_ENUM()

BEGIN_TM_ENUM(FILLTYPE)
    TM_ENUM(FT, SOLID)
    TM_ENUM(FT, VERTGRADIENT)
    TM_ENUM(FT, HORZGRADIENT)
    TM_ENUM(FT, RADIALGRADIENT)
    TM_ENUM(FT, TILEIMAGE)
END_TM_ENUM()

BEGIN_TM_ENUM(SIZINGTYPE)
    TM_ENUM(ST, TRUESIZE)
    TM_ENUM(ST, STRETCH)
    TM_ENUM(ST, TILE)
    TM_ENUM(ST, TILEHORZ)
    TM_ENUM(ST, TILEVERT)
    TM_ENUM(ST, TILECENTER)
END_TM_ENUM()

BEGIN_TM_ENUM(HALIGN)
    TM_ENUM(HA, LEFT)
    TM_ENUM(HA, CENTER)
    TM_ENUM(HA, RIGHT)
END_TM_ENUM()

BEGIN_TM_ENUM(CONTENTALIGNMENT)
    TM_ENUM(CA, LEFT)
    TM_ENUM(CA, CENTER)
    TM_ENUM(CA, RIGHT)
END_TM_ENUM()

BEGIN_TM_ENUM(VALIGN)
    TM_ENUM(VA, TOP)
    TM_ENUM(VA, CENTER)
    TM_ENUM(VA, BOTTOM)
END_TM_ENUM()

BEGIN_TM_ENUM(OFFSETTYPE)
    TM_ENUM(OT, TOPLEFT)
    TM_ENUM(OT, TOPRIGHT)
    TM_ENUM(OT, TOPMIDDLE)
    TM_ENUM(OT, BOTTOMLEFT)
    TM_ENUM(OT, BOTTOMRIGHT)
    TM_ENUM(OT, BOTTOMMIDDLE)
    TM_ENUM(OT, MIDDLELEFT)
    TM_ENUM(OT, MIDDLERIGHT)
    TM_ENUM(OT, LEFTOFCAPTION)
    TM_ENUM(OT, RIGHTOFCAPTION)
    TM_ENUM(OT, LEFTOFLASTBUTTON)
    TM_ENUM(OT, RIGHTOFLASTBUTTON)
    TM_ENUM(OT, ABOVELASTBUTTON)
    TM_ENUM(OT, BELOWLASTBUTTON)
END_TM_ENUM()

BEGIN_TM_ENUM(ICONEFFECT)
    TM_ENUM(ICE, NONE)
    TM_ENUM(ICE, GLOW)
    TM_ENUM(ICE, SHADOW)
    TM_ENUM(ICE, PULSE)
    TM_ENUM(ICE, ALPHA)
END_TM_ENUM()

BEGIN_TM_ENUM(TEXTSHADOWTYPE)
    TM_ENUM(TST, NONE)
    TM_ENUM(TST, SINGLE)
    TM_ENUM(TST, CONTINUOUS)
END_TM_ENUM()

//-----------------------------------------------------------------
//    PROPERTIES
//-----------------------------------------------------------------
BEGIN_TM_PROPS()

    //---- primitive types ----
    TM_PROP_BASE(TMT, 200)
    TM_PROP(TMT, STRING,         STRING)
    TM_PROP(TMT, INT,            INT)
    TM_PROP(TMT, BOOL,           BOOL)
    TM_PROP(TMT, COLOR,          COLOR)
    TM_PROP(TMT, MARGINS,        MARGINS)
    TM_PROP(TMT, FILENAME,       FILENAME)
    TM_PROP(TMT, SIZE,           SIZE)
    TM_PROP(TMT, POSITION,       POSITION)
    TM_PROP(TMT, RECT,           RECT)
    TM_PROP(TMT, FONT,           FONT)
    TM_PROP(TMT, INTLIST,        INTLIST)

    //---- special misc. properties ----
    TM_PROP_BASE(TMT, 400)
    TM_PROP(TMT, COLORSCHEMES,   STRING)
    TM_PROP(TMT, SIZES,          STRING)
    TM_PROP(TMT, CHARSET,        INT)

    //---- [documentation] properties ----

#define TMT_FIRST_RCSTRING_NAME   TMT_DISPLAYNAME
#define TMT_LAST_RCSTRING_NAME    TMT_DESCRIPTION

    TM_PROP_BASE(TMT, 600)
    TM_PROP(TMT, DISPLAYNAME,    STRING)
    TM_PROP(TMT, TOOLTIP,        STRING)
    TM_PROP(TMT, COMPANY,        STRING)
    TM_PROP(TMT, AUTHOR,         STRING)
    TM_PROP(TMT, COPYRIGHT,      STRING)
    TM_PROP(TMT, URL,            STRING)
    TM_PROP(TMT, VERSION,        STRING)
    TM_PROP(TMT, DESCRIPTION,    STRING)

    //---- theme metrics: fonts ----

#define TMT_FIRSTFONT TMT_CAPTIONFONT
#define TMT_LASTFONT  TMT_ICONTITLEFONT

    TM_PROP_BASE(TMT, 800)
    TM_PROP(TMT, CAPTIONFONT,        FONT)
    TM_PROP(TMT, SMALLCAPTIONFONT,   FONT)
    TM_PROP(TMT, MENUFONT,           FONT)
    TM_PROP(TMT, STATUSFONT,         FONT)
    TM_PROP(TMT, MSGBOXFONT,         FONT)
    TM_PROP(TMT, ICONTITLEFONT,      FONT)

    //---- theme metrics: bools ----

#define TMT_FIRSTBOOL   TMT_FLATMENUS
#define TMT_LASTBOOL    TMT_SYSTEMPOS

    TM_PROP_BASE(TMT, 1000)
    TM_PROP(TMT, FLATMENUS,            BOOL)
    TM_PROP(TMT, SYSTEMSIZE,           BOOL)
    TM_PROP(TMT, SYSTEMPOS,            BOOL)

    //---- theme metrics: sizes ----

#define TMT_FIRSTSIZE   TMT_BORDERWIDTH
#define TMT_LASTSIZE    TMT_MENUBARHEIGHT

    TM_PROP_BASE(TMT, 1200)
    TM_PROP(TMT, BORDERWIDTH,          SIZE)
    TM_PROP(TMT, SCROLLBARWIDTH,       SIZE)
    TM_PROP(TMT, SCROLLBARHEIGHT,      SIZE)
    TM_PROP(TMT, CAPTIONBARWIDTH,      SIZE)
    TM_PROP(TMT, CAPTIONBARHEIGHT,     SIZE)
    TM_PROP(TMT, SMCAPTIONBARWIDTH,    SIZE)
    TM_PROP(TMT, SMCAPTIONBARHEIGHT,   SIZE)
    TM_PROP(TMT, MENUBARWIDTH,         SIZE)
    TM_PROP(TMT, MENUBARHEIGHT,        SIZE)

    //---- theme metrics: ints ----

#define TMT_FIRSTINT   TMT_DPIX
#define TMT_LASTINT    TMT_MINCOLORDEPTH

    TM_PROP_BASE(TMT, 1300)
    TM_PROP(TMT, DPIX,              INT)
    TM_PROP(TMT, DPIY,              INT)
    TM_PROP(TMT, MINCOLORDEPTH,     INT)

    //---- theme metrics: strings ----

#define TMT_FIRSTSTRING   TMT_CSSNAME
#define TMT_LASTSTRING    TMT_XMLNAME

    TM_PROP_BASE(TMT, 1400)
    TM_PROP(TMT, CSSNAME,            STRING)
    TM_PROP(TMT, XMLNAME,            STRING)

    //---- theme metrics: colors ----

#define TMT_FIRSTCOLOR  TMT_SCROLLBAR
#define TMT_LASTCOLOR   TMT_MENUBAR

    TM_PROP_BASE(TMT, 1600)
    TM_PROP(TMT, SCROLLBAR,          COLOR)
    TM_PROP(TMT, BACKGROUND,         COLOR)
    TM_PROP(TMT, ACTIVECAPTION,      COLOR)
    TM_PROP(TMT, INACTIVECAPTION,    COLOR)
    TM_PROP(TMT, MENU,               COLOR)
    TM_PROP(TMT, WINDOW,             COLOR)
    TM_PROP(TMT, WINDOWFRAME,        COLOR)
    TM_PROP(TMT, MENUTEXT,           COLOR)
    TM_PROP(TMT, WINDOWTEXT,         COLOR)
    TM_PROP(TMT, CAPTIONTEXT,        COLOR)
    TM_PROP(TMT, ACTIVEBORDER,       COLOR)
    TM_PROP(TMT, INACTIVEBORDER,     COLOR)
    TM_PROP(TMT, APPWORKSPACE,       COLOR)
    TM_PROP(TMT, HIGHLIGHT,          COLOR)
    TM_PROP(TMT, HIGHLIGHTTEXT,      COLOR)
    TM_PROP(TMT, BTNFACE,            COLOR)
    TM_PROP(TMT, BTNSHADOW,          COLOR)
    TM_PROP(TMT, GRAYTEXT,           COLOR)
    TM_PROP(TMT, BTNTEXT,            COLOR)
    TM_PROP(TMT, INACTIVECAPTIONTEXT,     COLOR)
    TM_PROP(TMT, BTNHIGHLIGHT,            COLOR)
    TM_PROP(TMT, DKSHADOW3D,              COLOR)
    TM_PROP(TMT, LIGHT3D,                 COLOR)
    TM_PROP(TMT, INFOTEXT,                COLOR)
    TM_PROP(TMT, INFOBK,                  COLOR)
    TM_PROP(TMT, BUTTONALTERNATEFACE,     COLOR)
    TM_PROP(TMT, HOTTRACKING,             COLOR)
    TM_PROP(TMT, GRADIENTACTIVECAPTION,   COLOR)
    TM_PROP(TMT, GRADIENTINACTIVECAPTION, COLOR)
    TM_PROP(TMT, MENUHILIGHT,             COLOR)
    TM_PROP(TMT, MENUBAR,                 COLOR)

    //---- hue substitutions ----
    TM_PROP_BASE(TMT, 1800)
    TM_PROP(TMT, FROMHUE1,  INT)
    TM_PROP(TMT, FROMHUE2,  INT)
    TM_PROP(TMT, FROMHUE3,  INT)
    TM_PROP(TMT, FROMHUE4,  INT)
    TM_PROP(TMT, FROMHUE5,  INT)
    TM_PROP(TMT, TOHUE1,    INT)
    TM_PROP(TMT, TOHUE2,    INT)
    TM_PROP(TMT, TOHUE3,    INT)
    TM_PROP(TMT, TOHUE4,    INT)
    TM_PROP(TMT, TOHUE5,    INT)

    //---- color substitutions ----
    TM_PROP_BASE(TMT, 2000)
    TM_PROP(TMT, FROMCOLOR1,  COLOR)
    TM_PROP(TMT, FROMCOLOR2,  COLOR)
    TM_PROP(TMT, FROMCOLOR3,  COLOR)
    TM_PROP(TMT, FROMCOLOR4,  COLOR)
    TM_PROP(TMT, FROMCOLOR5,  COLOR)
    TM_PROP(TMT, TOCOLOR1,    COLOR)
    TM_PROP(TMT, TOCOLOR2,    COLOR)
    TM_PROP(TMT, TOCOLOR3,    COLOR)
    TM_PROP(TMT, TOCOLOR4,    COLOR)
    TM_PROP(TMT, TOCOLOR5,    COLOR)

    //---- rendering BOOL properties ----
    TM_PROP_BASE(TMT, 2200)
    TM_PROP(TMT, TRANSPARENT,   BOOL)       // image has transparent areas (see TransparentColor)
    TM_PROP(TMT, AUTOSIZE,      BOOL)       // if TRUE, nonclient caption width varies with text extent
    TM_PROP(TMT, BORDERONLY,    BOOL)       // only draw the border area of the image
    TM_PROP(TMT, COMPOSITED,    BOOL)       // control will handle the composite drawing
    TM_PROP(TMT, BGFILL,        BOOL)       // if TRUE, TRUESIZE images should be drawn on bg fill
    TM_PROP(TMT, GLYPHTRANSPARENT,   BOOL)  // glyph has transparent areas (see GlyphTransparentColor)
    TM_PROP(TMT, GLYPHONLY,   BOOL)         // only draw glyph (not background)
    TM_PROP(TMT, ALWAYSSHOWSIZINGBAR, BOOL)
    TM_PROP(TMT, MIRRORIMAGE, BOOL)         // default=TRUE means image gets mirrored in RTL (Mirror) windows

    //---- temp. perf options ----
    TM_PROP(TMT, CACHEBRUSHES,  BOOL)       // cache brushes needed for tiling 5 (of 9) grids
    TM_PROP(TMT, SOLIDBORDER,   BOOL)       // treat each border line as solid (use sampled color)
    TM_PROP(TMT, SOLIDCONTENT,  BOOL)       // treat middle area as solid (use sampled color)
    TM_PROP(TMT, DIRECTBITS,    BOOL)       // draw with StrectchDIBits()  (not bitmaps)
    TM_PROP(TMT, MANUALTILING,  BOOL)       // loop thru BitBlt's instead of using PatBlt()
    TM_PROP(TMT, DIRECTBRUSH,  BOOL)        // create brush directly from temp. extracted DIB's

    //---- rendering INT properties ----
    TM_PROP_BASE(TMT, 2400)
    TM_PROP(TMT, IMAGECOUNT,        INT)    // the number of state images in an imagefile
    TM_PROP(TMT, ALPHALEVEL,        INT)    // (0-255) alpha value for an icon (DrawThemeIcon part)
    TM_PROP(TMT, BORDERSIZE,        INT)    // the size of the border line for bgtype=BorderFill
    TM_PROP(TMT, ROUNDCORNERWIDTH,  INT)    // (0-100) % of roundness for rounded rects
    TM_PROP(TMT, ROUNDCORNERHEIGHT, INT)    // (0-100) % of roundness for rounded rects
    TM_PROP(TMT, GRADIENTRATIO1,    INT)    // (0-255) - amt of gradient color 1 to use (all must total=255)
    TM_PROP(TMT, GRADIENTRATIO2,    INT)    // (0-255) - amt of gradient color 2 to use (all must total=255)
    TM_PROP(TMT, GRADIENTRATIO3,    INT)    // (0-255) - amt of gradient color 3 to use (all must total=255)
    TM_PROP(TMT, GRADIENTRATIO4,    INT)    // (0-255) - amt of gradient color 4 to use (all must total=255)
    TM_PROP(TMT, GRADIENTRATIO5,    INT)    // (0-255) - amt of gradient color 5 to use (all must total=255)
    TM_PROP(TMT, PROGRESSCHUNKSIZE, INT)    // size of progress control chunks
    TM_PROP(TMT, PROGRESSSPACESIZE, INT)    // size of progress control spaces
    TM_PROP(TMT, SATURATION,        INT)    // (0-255) amt of saturation for DrawThemeIcon() part
    TM_PROP(TMT, TEXTBORDERSIZE,    INT)    // size of border around text chars
    TM_PROP(TMT, ALPHATHRESHOLD,    INT)    // (0-255) the min. alpha value of a pixel that is solid
    TM_PROP(TMT, WIDTH,             SIZE)   // custom window prop: size of part (min. window)
    TM_PROP(TMT, HEIGHT,            SIZE)   // custom window prop: size of part (min. window)
    TM_PROP(TMT, NORMALINDEX,       INT)    // the 1-based index into "filesizes" that is the normal size
    TM_PROP(TMT, GLYPHINDEX,        INT)    // for font-based glyphs, the char index into the font

    //---- rendering FONT properties ----
    TM_PROP_BASE(TMT, 2600)
    TM_PROP(TMT, GLYPHFONT,         FONT)   // the font that the glyph is drawn with

    //---- rendering INTLIST properties ----
    TM_PROP_BASE(TMT, 2800)
    TM_PROP(TMT, FILESIZES,         INTLIST)    // the list of image sizes available for this part

    //---- rendering FILENAME properties ----
    TM_PROP_BASE(TMT, 3000)
    TM_PROP(TMT, IMAGEFILE,         FILENAME)   // the filename of the image (or basename, for mult. images)
    TM_PROP(TMT, IMAGEFILE1,        FILENAME)   // imagefile matching 1st FileSizes size
    TM_PROP(TMT, IMAGEFILE2,        FILENAME)   // imagefile matching 2nd FileSizes size
    TM_PROP(TMT, IMAGEFILE3,        FILENAME)   // imagefile matching 3rd FileSizes size
    TM_PROP(TMT, IMAGEFILE4,        FILENAME)   // imagefile matching 4th FileSizes size
    TM_PROP(TMT, IMAGEFILE5,        FILENAME)   // imagefile matching 5th FileSizes size
    TM_PROP(TMT, NTLFILE,           FILENAME)   
    TM_PROP(TMT, GLYPHIMAGEFILE,    FILENAME)   // the filename for the glyph image

    //---- rendering STRING properties ----
    TM_PROP_BASE(TMT, 3200)
    TM_PROP(TMT, TEXT,              STRING)

    //---- rendering POSITION properties ----
    TM_PROP_BASE(TMT, 3400)
    TM_PROP(TMT, OFFSET,            POSITION)   // for window part layout
    TM_PROP(TMT, TEXTSHADOWOFFSET,  POSITION)   // where char shadows are drawn, relative to orig. chars

    //---- rendering MARGIN properties ----
    TM_PROP_BASE(TMT, 3600)
    TM_PROP(TMT, SIZINGMARGINS,     MARGINS)    // margins used for 9-grid sizing
    TM_PROP(TMT, CONTENTMARGINS,    MARGINS)    // margins that define where content can be placed
    TM_PROP(TMT, CAPTIONMARGINS,    MARGINS)    // margins that define where caption text can be placed

    //---- rendering COLOR properties ----
    TM_PROP_BASE(TMT, 3800)
    TM_PROP(TMT, BORDERCOLOR,      COLOR)       // color of borders for BorderFill 
    TM_PROP(TMT, FILLCOLOR,        COLOR)       // color of bg fill 
    TM_PROP(TMT, TEXTCOLOR,        COLOR)       // color text is drawn in
    TM_PROP(TMT, EDGELIGHTCOLOR,     COLOR)     // edge color
    TM_PROP(TMT, EDGEHIGHLIGHTCOLOR, COLOR)     // edge color
    TM_PROP(TMT, EDGESHADOWCOLOR,    COLOR)     // edge color
    TM_PROP(TMT, EDGEDKSHADOWCOLOR,  COLOR)     // edge color
    TM_PROP(TMT, EDGEFILLCOLOR,  COLOR)         // edge color
    TM_PROP(TMT, TRANSPARENTCOLOR, COLOR)       // color of pixels that are treated as transparent (not drawn)
    TM_PROP(TMT, GRADIENTCOLOR1,   COLOR)       // first color in gradient
    TM_PROP(TMT, GRADIENTCOLOR2,   COLOR)       // second color in gradient
    TM_PROP(TMT, GRADIENTCOLOR3,   COLOR)       // third color in gradient
    TM_PROP(TMT, GRADIENTCOLOR4,   COLOR)       // forth color in gradient
    TM_PROP(TMT, GRADIENTCOLOR5,   COLOR)       // fifth color in gradient
    TM_PROP(TMT, SHADOWCOLOR,      COLOR)       // color of text shadow
    TM_PROP(TMT, GLOWCOLOR,        COLOR)       // color of glow produced by DrawThemeIcon
    TM_PROP(TMT, TEXTBORDERCOLOR,  COLOR)       // color of text border
    TM_PROP(TMT, TEXTSHADOWCOLOR,  COLOR)       // color of text shadow
    TM_PROP(TMT, GLYPHTEXTCOLOR,        COLOR)  // color that font-based glyph is drawn with
    TM_PROP(TMT, GLYPHTRANSPARENTCOLOR, COLOR)  // color of transparent pixels in GlyphImageFile

    //---- rendering enum properties (must be declared in TM_ENUM section above) ----
    TM_PROP_BASE(TMT, 4000)
    TM_PROP(TMT, BGTYPE,           ENUM)        // basic drawing type for each part
    TM_PROP(TMT, BORDERTYPE,       ENUM)        // type of border for BorderFill parts
    TM_PROP(TMT, FILLTYPE,         ENUM)        // fill shape for BorderFill parts
    TM_PROP(TMT, SIZINGTYPE,       ENUM)        // how to size ImageFile parts
    TM_PROP(TMT, HALIGN,           ENUM)        // horizontal alignment for TRUESIZE parts & glyphs
    TM_PROP(TMT, CONTENTALIGNMENT, ENUM)        // custom window prop: how text is aligned in caption
    TM_PROP(TMT, VALIGN,           ENUM)        // horizontal alignment for TRUESIZE parts & glyphs
    TM_PROP(TMT, OFFSETTYPE,       ENUM)        // how window part should be placed
    TM_PROP(TMT, ICONEFFECT,       ENUM)        // type of effect to use with DrawThemeIcon
    TM_PROP(TMT, TEXTSHADOWTYPE,   ENUM)        // type of shadow to draw with text
    TM_PROP(TMT, IMAGELAYOUT,      ENUM)        // how multiple images are arranged (horz. or vert.)

    // start panel specific properties
    TM_PROP(TMT, USERPICTURE,      BOOL)
    TM_PROP(TMT, DEFAULTPANESIZE,  RECT)

END_TM_PROPS()
//---------------------------------------------------------------------------
//    "Globals" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(GLOBALS)
    TM_PARTVAL(GP, LINEVERT, 30)
    TM_PART(GP, LINEHORZ)
    TM_PART(GP, BORDER)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(LINEVERT)
       TM_STATE(LVS, FLAT)
       TM_STATE(LVS, RAISED)
       TM_STATE(LVS, SUNKEN)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(LINEHORZ)
       TM_STATE(LHS, FLAT)
       TM_STATE(LHS, RAISED)
       TM_STATE(LHS, SUNKEN)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(BORDER)
       TM_STATE(BSS, FLAT)
       TM_STATE(BSS, RAISED)
       TM_STATE(BSS, SUNKEN)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Window" (i.e., non-client) Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(WINDOW)
    TM_PART(WP, FRAME)
    TM_PART(WP, SMALLFRAME)
    TM_PART(WP, CAPTION)
    TM_PART(WP, SMALLCAPTION)
    TM_PART(WP, MINCAPTION)
    TM_PART(WP, SMALLMINCAPTION)
    TM_PART(WP, MAXCAPTION)
    TM_PART(WP, SMALLMAXCAPTION)
    //---- buttons ----
    TM_PART(WP, SYSBUTTON)
    TM_PART(WP, SMALLSYSBUTTON)
    TM_PART(WP, MDISYSBUTTON)
    TM_PART(WP, MINBUTTON)
    TM_PART(WP, SMALLMINBUTTON)
    TM_PART(WP, MDIMINBUTTON)
    TM_PART(WP, MAXBUTTON)
    TM_PART(WP, SMALLMAXBUTTON)
    TM_PART(WP, CLOSEBUTTON)
    TM_PART(WP, SMALLCLOSEBUTTON)
    TM_PART(WP, MDICLOSEBUTTON)
    TM_PART(WP, RESTOREBUTTON)
    TM_PART(WP, SMALLRESTOREBUTTON)
    TM_PART(WP, MDIRESTOREBUTTON)
    TM_PART(WP, HELPBUTTON)
    TM_PART(WP, SMALLHELPBUTTON)
    TM_PART(WP, MDIHELPBUTTON)
    //---- scrollbars 
    TM_PART(WP, HORZSCROLL)
    TM_PART(WP, HORZTHUMB)
    TM_PART(WP, VERTSCROLL)
    TM_PART(WP, VERTTHUMB)
    //---- dialog ----
    TM_PART(WP, DIALOG)
    //---- hit-test templates ---
    TM_PART(WP, CAPTIONSIZINGTEMPLATE)
    TM_PART(WP, SMALLCAPTIONSIZINGTEMPLATE)
    TM_PART(WP, FRAMESIZINGTEMPLATE)
    TM_PART(WP, SMALLFRAMESIZINGTEMPLATE)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(FRAME)
    TM_STATE(FS, ACTIVE)
    TM_STATE(FS, INACTIVE)
    TM_STATE(FS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(CAPTION)
    TM_STATE(CS, ACTIVE)
    TM_STATE(CS, INACTIVE)
    TM_STATE(CS, DISABLED)
END_TM_PART_STATES()
    
BEGIN_TM_PART_STATES(MAXCAPTION)
    TM_STATE(MXCS, ACTIVE)
    TM_STATE(MXCS, INACTIVE)
    TM_STATE(MXCS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(MINCAPTION)
    TM_STATE(MNCS, ACTIVE)
    TM_STATE(MNCS, INACTIVE)
    TM_STATE(MNCS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(HORZSCROLL)
    TM_STATE(HSS, NORMAL)
    TM_STATE(HSS, HOT)
    TM_STATE(HSS, PUSHED)
    TM_STATE(HSS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(HORZTHUMB)
    TM_STATE(HTS, NORMAL)
    TM_STATE(HTS, HOT)
    TM_STATE(HTS, PUSHED)
    TM_STATE(HTS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(VERTSCROLL)
    TM_STATE(VSS, NORMAL)
    TM_STATE(VSS, HOT)
    TM_STATE(VSS, PUSHED)
    TM_STATE(VSS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(VERTTHUMB)
    TM_STATE(VTS, NORMAL)
    TM_STATE(VTS, HOT)
    TM_STATE(VTS, PUSHED)
    TM_STATE(VTS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(SYSBUTTON)
    TM_STATE(SBS, NORMAL)
    TM_STATE(SBS, HOT)
    TM_STATE(SBS, PUSHED)
    TM_STATE(SBS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(MINBUTTON)
    TM_STATE(MINBS, NORMAL)
    TM_STATE(MINBS, HOT)
    TM_STATE(MINBS, PUSHED)
    TM_STATE(MINBS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(MAXBUTTON)
    TM_STATE(MAXBS, NORMAL)
    TM_STATE(MAXBS, HOT)
    TM_STATE(MAXBS, PUSHED)
    TM_STATE(MAXBS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(RESTOREBUTTON)
    TM_STATE(RBS, NORMAL)
    TM_STATE(RBS, HOT)
    TM_STATE(RBS, PUSHED)
    TM_STATE(RBS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(HELPBUTTON)
    TM_STATE(HBS, NORMAL)
    TM_STATE(HBS, HOT)
    TM_STATE(HBS, PUSHED)
    TM_STATE(HBS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(CLOSEBUTTON)
    TM_STATE(CBS, NORMAL)
    TM_STATE(CBS, HOT)
    TM_STATE(CBS, PUSHED)
    TM_STATE(CBS, DISABLED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Button" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(BUTTON)
    TM_PART(BP, PUSHBUTTON)
    TM_PART(BP, RADIOBUTTON)
    TM_PART(BP, CHECKBOX)
    TM_PART(BP, GROUPBOX)
    TM_PART(BP, USERBUTTON)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(PUSHBUTTON)
    TM_STATE(PBS, NORMAL)
    TM_STATE(PBS, HOT)
    TM_STATE(PBS, PRESSED)
    TM_STATE(PBS, DISABLED)
    TM_STATE(PBS, DEFAULTED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(RADIOBUTTON)
    TM_STATE(RBS, UNCHECKEDNORMAL)
    TM_STATE(RBS, UNCHECKEDHOT)
    TM_STATE(RBS, UNCHECKEDPRESSED)
    TM_STATE(RBS, UNCHECKEDDISABLED)
    TM_STATE(RBS, CHECKEDNORMAL)
    TM_STATE(RBS, CHECKEDHOT)
    TM_STATE(RBS, CHECKEDPRESSED)
    TM_STATE(RBS, CHECKEDDISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(CHECKBOX)
    TM_STATE(CBS, UNCHECKEDNORMAL)
    TM_STATE(CBS, UNCHECKEDHOT)
    TM_STATE(CBS, UNCHECKEDPRESSED)
    TM_STATE(CBS, UNCHECKEDDISABLED)
    TM_STATE(CBS, CHECKEDNORMAL)
    TM_STATE(CBS, CHECKEDHOT)
    TM_STATE(CBS, CHECKEDPRESSED)
    TM_STATE(CBS, CHECKEDDISABLED)
    TM_STATE(CBS, MIXEDNORMAL)
    TM_STATE(CBS, MIXEDHOT)
    TM_STATE(CBS, MIXEDPRESSED)
    TM_STATE(CBS, MIXEDDISABLED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Rebar" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(REBAR)
    TM_PART(RP, GRIPPER)
    TM_PART(RP, GRIPPERVERT)
    TM_PART(RP, BAND)
    TM_PART(RP, CHEVRON)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(CHEVRON)
    TM_STATE(CHEVS, NORMAL)
    TM_STATE(CHEVS, HOT)
    TM_STATE(CHEVS, PRESSED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Toolbar" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(TOOLBAR)
    TM_PART(TP, BUTTON)
    TM_PART(TP, DROPDOWNBUTTON)
    TM_PART(TP, SPLITBUTTON)
    TM_PART(TP, SPLITBUTTONDROPDOWN)
    TM_PART(TP, SEPARATOR)
    TM_PART(TP, SEPARATORVERT)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(TOOLBAR)
    TM_STATE(TS, NORMAL)
    TM_STATE(TS, HOT)
    TM_STATE(TS, PRESSED)
    TM_STATE(TS, DISABLED)
    TM_STATE(TS, CHECKED)
    TM_STATE(TS, HOTCHECKED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Status" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(STATUS)
    TM_PART(SP, PANE)
    TM_PART(SP, GRIPPER)
END_TM_CLASS_PARTS()

//---------------------------------------------------------------------------------------
//   "Menu" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(MENU)
    TM_PART(MP, MENUITEM)
    TM_PART(MP, MENUDROPDOWN)
    TM_PART(MP, MENUBARITEM)
    TM_PART(MP, MENUBARDROPDOWN)
    TM_PART(MP, CHEVRON)
    TM_PART(MP, SEPARATOR)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(MENU)
    TM_STATE(MS, NORMAL)
    TM_STATE(MS, SELECTED)
    TM_STATE(MS, DEMOTED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "ListView" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(LISTVIEW)
    TM_PART(LVP, LISTITEM)
    TM_PART(LVP, LISTGROUP)
    TM_PART(LVP, LISTDETAIL)
    TM_PART(LVP, LISTSORTEDDETAIL)
    TM_PART(LVP, EMPTYTEXT)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(LISTITEM)
    TM_STATE(LIS, NORMAL)
    TM_STATE(LIS, HOT)
    TM_STATE(LIS, SELECTED)
    TM_STATE(LIS, DISABLED)
    TM_STATE(LIS, SELECTEDNOTFOCUS)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Header" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(HEADER)
    TM_PART(HP, HEADERITEM)
    TM_PART(HP, HEADERITEMLEFT)
    TM_PART(HP, HEADERITEMRIGHT)
    TM_PART(HP, HEADERSORTARROW)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(HEADERITEM)
    TM_STATE(HIS, NORMAL)
    TM_STATE(HIS, HOT)
    TM_STATE(HIS, PRESSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(HEADERITEMLEFT)
    TM_STATE(HILS, NORMAL)
    TM_STATE(HILS, HOT)
    TM_STATE(HILS, PRESSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(HEADERITEMRIGHT)
    TM_STATE(HIRS, NORMAL)
    TM_STATE(HIRS, HOT)
    TM_STATE(HIRS, PRESSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(HEADERSORTARROW)
    TM_STATE(HSAS, SORTEDUP)
    TM_STATE(HSAS, SORTEDDOWN)
END_TM_PART_STATES()
//---------------------------------------------------------------------------------------
//   "Progress" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(PROGRESS)
    TM_PART(PP, BAR)
    TM_PART(PP, BARVERT)
    TM_PART(PP, CHUNK)
    TM_PART(PP, CHUNKVERT)
END_TM_CLASS_PARTS()

//---------------------------------------------------------------------------------------
//   "Tab" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(TAB)
    TM_PART(TABP, TABITEM)
    TM_PART(TABP, TABITEMLEFTEDGE)
    TM_PART(TABP, TABITEMRIGHTEDGE)
    TM_PART(TABP, TABITEMBOTHEDGE)
    TM_PART(TABP, TOPTABITEM)
    TM_PART(TABP, TOPTABITEMLEFTEDGE)
    TM_PART(TABP, TOPTABITEMRIGHTEDGE)
    TM_PART(TABP, TOPTABITEMBOTHEDGE)
    TM_PART(TABP, PANE)
    TM_PART(TABP, BODY)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(TABITEM)
    TM_STATE(TIS, NORMAL)
    TM_STATE(TIS, HOT)
    TM_STATE(TIS, SELECTED)
    TM_STATE(TIS, DISABLED)
    TM_STATE(TIS, FOCUSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TABITEMLEFTEDGE)
    TM_STATE(TILES, NORMAL)
    TM_STATE(TILES, HOT)
    TM_STATE(TILES, SELECTED)
    TM_STATE(TILES, DISABLED)
    TM_STATE(TILES, FOCUSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TABITEMRIGHTEDGE)
    TM_STATE(TIRES, NORMAL)
    TM_STATE(TIRES, HOT)
    TM_STATE(TIRES, SELECTED)
    TM_STATE(TIRES, DISABLED)
    TM_STATE(TIRES, FOCUSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TABITEMBOTHEDGES)
    TM_STATE(TIBES, NORMAL)
    TM_STATE(TIBES, HOT)
    TM_STATE(TIBES, SELECTED)
    TM_STATE(TIBES, DISABLED)
    TM_STATE(TIBES, FOCUSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TOPTABITEM)
    TM_STATE(TTIS, NORMAL)
    TM_STATE(TTIS, HOT)
    TM_STATE(TTIS, SELECTED)
    TM_STATE(TTIS, DISABLED)
    TM_STATE(TTIS, FOCUSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TOPTABITEMLEFTEDGE)
    TM_STATE(TTILES, NORMAL)
    TM_STATE(TTILES, HOT)
    TM_STATE(TTILES, SELECTED)
    TM_STATE(TTILES, DISABLED)
    TM_STATE(TTILES, FOCUSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TOPTABITEMRIGHTEDGE)
    TM_STATE(TTIRES, NORMAL)
    TM_STATE(TTIRES, HOT)
    TM_STATE(TTIRES, SELECTED)
    TM_STATE(TTIRES, DISABLED)
    TM_STATE(TTIRES, FOCUSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TOPTABITEMBOTHEDGES)
    TM_STATE(TTIBES, NORMAL)
    TM_STATE(TTIBES, HOT)
    TM_STATE(TTIBES, SELECTED)
    TM_STATE(TTIBES, DISABLED)
    TM_STATE(TTIBES, FOCUSED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Trackbar" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(TRACKBAR)
    TM_PART(TKP, TRACK)
    TM_PART(TKP, TRACKVERT)
    TM_PART(TKP, THUMB)
    TM_PART(TKP, THUMBBOTTOM)
    TM_PART(TKP, THUMBTOP)
    TM_PART(TKP, THUMBVERT)
    TM_PART(TKP, THUMBLEFT)
    TM_PART(TKP, THUMBRIGHT)
    TM_PART(TKP, TICS)
    TM_PART(TKP, TICSVERT)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(TRACKBAR)
    TM_STATE(TKS, NORMAL)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TRACK)
    TM_STATE(TRS, NORMAL)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TRACKVERT)
    TM_STATE(TRVS, NORMAL)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(THUMB)
    TM_STATE(TUS, NORMAL)
    TM_STATE(TUS, HOT)
    TM_STATE(TUS, PRESSED)
    TM_STATE(TUS, FOCUSED)
    TM_STATE(TUS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(THUMBBOTTOM)
    TM_STATE(TUBS, NORMAL)
    TM_STATE(TUBS, HOT)
    TM_STATE(TUBS, PRESSED)
    TM_STATE(TUBS, FOCUSED)
    TM_STATE(TUBS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(THUMBTOP)
    TM_STATE(TUTS, NORMAL)
    TM_STATE(TUTS, HOT)
    TM_STATE(TUTS, PRESSED)
    TM_STATE(TUTS, FOCUSED)
    TM_STATE(TUTS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(THUMBVERT)
    TM_STATE(TUVS, NORMAL)
    TM_STATE(TUVS, HOT)
    TM_STATE(TUVS, PRESSED)
    TM_STATE(TUVS, FOCUSED)
    TM_STATE(TUVS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(THUMBLEFT)
    TM_STATE(TUVLS, NORMAL)
    TM_STATE(TUVLS, HOT)
    TM_STATE(TUVLS, PRESSED)
    TM_STATE(TUVLS, FOCUSED)
    TM_STATE(TUVLS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(THUMBRIGHT)
    TM_STATE(TUVRS, NORMAL)
    TM_STATE(TUVRS, HOT)
    TM_STATE(TUVRS, PRESSED)
    TM_STATE(TUVRS, FOCUSED)
    TM_STATE(TUVRS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TICS)
    TM_STATE(TSS, NORMAL)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(TICSVERT)
    TM_STATE(TSVS, NORMAL)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Tooltips" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(TOOLTIP)
    TM_PART(TTP, STANDARD)
    TM_PART(TTP, STANDARDTITLE)
    TM_PART(TTP, BALLOON)
    TM_PART(TTP, BALLOONTITLE)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(STANDARD)
	TM_STATE(TTSS, NORMAL)
	TM_STATE(TTSS, LINK)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(BALLOON)
	TM_STATE(TTBS, NORMAL)
	TM_STATE(TTBS, LINK)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "TreeView" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(TREEVIEW)
    TM_PART(TVP, TREEITEM)
    TM_PART(TVP, GLYPH)
    TM_PART(TVP, BRANCH)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(TREEITEM)
    TM_STATE(TREIS, NORMAL)
    TM_STATE(TREIS, HOT)
    TM_STATE(TREIS, SELECTED)
    TM_STATE(TREIS, DISABLED)
    TM_STATE(TREIS, SELECTEDNOTFOCUS)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(GLYPH)
    TM_STATE(GLPS, CLOSED)
    TM_STATE(GLPS, OPENED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Spin" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(SPIN)
    TM_PART(SPNP, UP)
    TM_PART(SPNP, DOWN)
    TM_PART(SPNP, UPHORZ)
    TM_PART(SPNP, DOWNHORZ)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(UP)
    TM_STATE(UPS, NORMAL)
    TM_STATE(UPS, HOT)
    TM_STATE(UPS, PRESSED)
    TM_STATE(UPS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(DOWN)
    TM_STATE(DNS, NORMAL)
    TM_STATE(DNS, HOT)
    TM_STATE(DNS, PRESSED)
    TM_STATE(DNS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(UPHORZ)
    TM_STATE(UPHZS, NORMAL)
    TM_STATE(UPHZS, HOT)
    TM_STATE(UPHZS, PRESSED)
    TM_STATE(UPHZS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(DOWNHORZ)
    TM_STATE(DNHZS, NORMAL)
    TM_STATE(DNHZS, HOT)
    TM_STATE(DNHZS, PRESSED)
    TM_STATE(DNHZS, DISABLED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Page" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(PAGE)
    TM_PART(PGRP, UP)
    TM_PART(PGRP, DOWN)
    TM_PART(PGRP, UPHORZ)
    TM_PART(PGRP, DOWNHORZ)
END_TM_CLASS_PARTS()

//--- Pager uses same states as Spin ---

//---------------------------------------------------------------------------------------
//   "Scrollbar" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(SCROLLBAR)
    TM_PART(SBP, ARROWBTN)
    TM_PART(SBP, THUMBBTNHORZ)
    TM_PART(SBP, THUMBBTNVERT)
    TM_PART(SBP, LOWERTRACKHORZ)
    TM_PART(SBP, UPPERTRACKHORZ)
    TM_PART(SBP, LOWERTRACKVERT)
    TM_PART(SBP, UPPERTRACKVERT)
    TM_PART(SBP, GRIPPERHORZ)
    TM_PART(SBP, GRIPPERVERT)
    TM_PART(SBP, SIZEBOX)
END_TM_CLASS_PARTS()



BEGIN_TM_PART_STATES(ARROWBTN)
    TM_STATE(ABS, UPNORMAL)
    TM_STATE(ABS, UPHOT)
    TM_STATE(ABS, UPPRESSED)
    TM_STATE(ABS, UPDISABLED)
    TM_STATE(ABS, DOWNNORMAL)
    TM_STATE(ABS, DOWNHOT)
    TM_STATE(ABS, DOWNPRESSED)
    TM_STATE(ABS, DOWNDISABLED)
    TM_STATE(ABS, LEFTNORMAL)
    TM_STATE(ABS, LEFTHOT)
    TM_STATE(ABS, LEFTPRESSED)
    TM_STATE(ABS, LEFTDISABLED)
    TM_STATE(ABS, RIGHTNORMAL)
    TM_STATE(ABS, RIGHTHOT)
    TM_STATE(ABS, RIGHTPRESSED)
    TM_STATE(ABS, RIGHTDISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(SCROLLBAR)
    TM_STATE(SCRBS, NORMAL)
    TM_STATE(SCRBS, HOT)
    TM_STATE(SCRBS, PRESSED)
    TM_STATE(SCRBS, DISABLED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(SIZEBOX)
    TM_STATE(SZB, RIGHTALIGN)
    TM_STATE(SZB, LEFTALIGN)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Edit" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(EDIT)
    TM_PART(EP, EDITTEXT)
    TM_PART(EP, CARET)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(EDITTEXT)
    TM_STATE(ETS, NORMAL)
    TM_STATE(ETS, HOT)
    TM_STATE(ETS, SELECTED)
    TM_STATE(ETS, DISABLED)
    TM_STATE(ETS, FOCUSED)
    TM_STATE(ETS, READONLY)
    TM_STATE(ETS, ASSIST)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "ComboBox" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(COMBOBOX)
    TM_PART(CP, DROPDOWNBUTTON)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(COMBOBOX)
    TM_STATE(CBXS, NORMAL)
    TM_STATE(CBXS, HOT)
    TM_STATE(CBXS, PRESSED)
    TM_STATE(CBXS, DISABLED)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Taskbar Clock" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(CLOCK)
    TM_PART(CLP, TIME)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(CLOCK)
    TM_STATE(CLS, NORMAL)
END_TM_PART_STATES()

//---------------------------------------------------------------------------------------
//   "Tray Notify" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(TRAYNOTIFY)
    TM_PART(TNP, BACKGROUND)
    TM_PART(TNP, ANIMBACKGROUND)
END_TM_CLASS_PARTS()

//---------------------------------------------------------------------------------------
//   "TaskBar" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(TASKBAR)
    TM_PART(TBP, BACKGROUNDBOTTOM)
    TM_PART(TBP, BACKGROUNDRIGHT)
    TM_PART(TBP, BACKGROUNDTOP)
    TM_PART(TBP, BACKGROUNDLEFT)
    TM_PART(TBP, SIZINGBARBOTTOM)
    TM_PART(TBP, SIZINGBARRIGHT)
    TM_PART(TBP, SIZINGBARTOP)
    TM_PART(TBP, SIZINGBARLEFT)
END_TM_CLASS_PARTS()

//---------------------------------------------------------------------------------------
//   "TaskBand" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(TASKBAND)
    TM_PART(TDP, GROUPCOUNT)
END_TM_CLASS_PARTS()

//---------------------------------------------------------------------------------------
//   "StartPanel" Parts & States
//---------------------------------------------------------------------------------------
BEGIN_TM_CLASS_PARTS(STARTPANEL)
    TM_PART(SPP, USERPANE)
    TM_PART(SPP, MOREPROGRAMS)
    TM_PART(SPP, MOREPROGRAMSARROW)
    TM_PART(SPP, PROGLIST)
    TM_PART(SPP, PROGLISTSEPARATOR)
    TM_PART(SPP, PLACESLIST)
    TM_PART(SPP, PLACESLISTSEPARATOR)
    TM_PART(SPP, LOGOFF)
    TM_PART(SPP, LOGOFFBUTTONS)
    TM_PART(SPP, USERPICTURE)
    TM_PART(SPP, PREVIEW)
END_TM_CLASS_PARTS()

BEGIN_TM_PART_STATES(MOREPROGRAMSARROW)
    TM_STATE(SPS, NORMAL)
    TM_STATE(SPS, HOT)
    TM_STATE(SPS, PRESSED)
END_TM_PART_STATES()

BEGIN_TM_PART_STATES(LOGOFFBUTTONS)
    TM_STATE(SPLS, NORMAL)
    TM_STATE(SPLS, HOT)
    TM_STATE(SPLS, PRESSED)
END_TM_PART_STATES()


//---------------------------------------------------------------------------
END_TM_SCHEMA(ThemeMgrSchema)
//---------------------------------------------------------------------------
#endif      // TMSCHEMA_H
//---------------------------------------------------------------------------
