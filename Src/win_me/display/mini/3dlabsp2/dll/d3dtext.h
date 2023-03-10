/******************************Module*Header**********************************\
*
*                           *************************************
*                           * Permedia 2: Direct 3D SAMPLE CODE *
*                           *************************************
*
* Module Name: d3dtext.h
*
*  Content:  D3D Texture management related definitions and macros
*
* Copyright (c) 1994-1998 3Dlabs Inc. Ltd. All rights reserved.
* Copyright (c) 1995-1999 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/

#ifndef _DLL_D3DTEXT_H_
#define _DLL_D3DTEXT_H_


//-----------------------------------------------------------------------------
//                       Texture structure definitions
//-----------------------------------------------------------------------------

// We only handle one single mipmap on this sample driver since the P2 doesn't
// natively support them
#if D3D_MIPMAPPING
#define MAX_MIP_LEVELS 12
#else
#define MAX_MIP_LEVELS 1
#endif // D3D_MIPMAPPING


// stores information needed to quickly setup a mipmap level on
// the chip.  At the moment this is Partial Products and widths/heights
typedef struct tagMIPTEXTURE 
{

    // Widths and heights for this mip level
    INT         logWidth;
    INT         logHeight;

    // Partial products for this mip level
    ULONG       ulPackedPP;

    // Offset in pixels to start of the texture
    // for the current miplevel
    DWORD       PixelOffset;

} MIPTEXTURE;

typedef struct _P2_MANAGED_TEXTURE 
{
    DWORD               dwFlags;    // Private flags
    FLATPTR             fpVidMem;   // store the real vidmem 
                                    // for managed textures
    LPVIDMEM            pvmHeap;   // heap pointer for the managed 
                                    // video texture
} P2_MANAGED_TEXTURE, *PP2_MANAGED_TEXTURE;
#define P2_SURFACE_NEEDUPDATE   0x00000200  //indicating managed 

typedef struct _permedia_d3dtexture 
{
    // Magic number to verify validity of pointer
    ULONG               MagicNo ;
    // the following four memebers are exact replicates
    // of those in DDRAWI_DDRAWSURFACE_GBL
    DWORD               dwFlags;
    DWORD               dwCaps;
    DWORD               dwCaps2;
    FLATPTR             fpVidMem;       // pointer to video memory
    LONG                lPitch;         // pitch of surface
    DDPIXELFORMAT       ddpfSurface;    // pixel format of surface
    BOOL                bAlpha;
    UINT_PTR            lSurfaceOffset;

    // Width and Height of texture
    WORD                wWidth;
    WORD                wHeight;

    // The AGP that the last texture came from
    DWORD               dwGARTDevLast;


    BOOL                bMipMap;
    DWORD               m_dwBytes;
    DWORD               m_dwPriority;
    DWORD               m_dwTicks;
    DWORD               m_dwHeapIndex;
    ULONG               HandleListIndex;    // indicating which list it's with
    // For setting up MipMaps 
    MIPTEXTURE          MipLevels[MAX_MIP_LEVELS];

    DWORD               dwKeyLow;
    DWORD               dwKeyHigh;
    DWORD               dwPaletteHandle;

    // The number of mipmap levels this texture should have
    int                 iMipLevels;
    P2_MANAGED_TEXTURE  P2ManagedTexture;
} PERMEDIA_D3DTEXTURE, *PPERMEDIA_D3DTEXTURE;

//-----------------------------------------------------------------------------
//                       DX7 Texture management definitions
//-----------------------------------------------------------------------------

typedef struct _permedia_d3dpalette 
{
    DWORD           dwFlags;
    WORD            wStartIndex;
    WORD            wNumEntries;
    PALETTEENTRY    ColorTable[256];   // array of palette entries, could be dynamic later
} PERMEDIA_D3DPALETTE, *PPERMEDIA_D3DPALETTE;

#define LISTGROWSIZE    1024
typedef struct _DWLIST
{
    PPERMEDIA_D3DTEXTURE   *dwSurfaceList;  // array to hold handles, 
                                            // dynamically allocated 
                                            // dwSurfaceList[0] is the number 
                                            // of entries in dwSurfaceList 
                                            // if allocated
    PPERMEDIA_D3DPALETTE   *dwPaletteList;  // array to hold handles, 
                                            // dynamically allocated 
                                            // dwPaletteList[0] is the number
                                            // of entries in dwPaletteList
                                            // if allocated
    LPVOID                  pDDLcl;         // owning ddraw pointer as a key
    LPVOID                  lpD3DContext;   // list of D3DContexts with same pDDLcl
} DWLIST;
typedef DWLIST  FAR* LPDWLIST;
extern  DWLIST  HandleList[]; 

typedef struct _HANDLELISTHDR
{
    WORD    wMaxAllowedHandle;              //Maximum Handle possible in list
    WORD    wNumofValidHandles;             //Number of Valid Handles in list
} HANDLELISTHDR, *PHANDLELISTHDR;
//-----------------------------------------------------------------------------
//                  Texture coordinate wrapping macros
//-----------------------------------------------------------------------------
#define FLUSH_DUE_TO_WRAP(par)
#define DONT_FLUSH_DUE_TO_WRAP(par)
#define WRAP(par, wrapit) if(wrapit) {                      \
    float elp;                                              \
    float erp;                                              \
    float emp;                                              \
    elp = (float)fabs(par##1 - par##0);                     \
    erp = (float)fabs(par##2 - par##1);                     \
    emp = (float)fabs(par##0 - par##2);                     \
    if( (elp > (float)0.5) && (erp > (float)0.5) )          \
    {                                                       \
        if (par##1 < par##2) { par##1 += 1.0; }             \
        else { par##2 += 1.0; par##0 += 1.0; }              \
        FLUSH_DUE_TO_WRAP(par);                             \
    }                                                       \
    else if( (erp > (float)0.5) && (emp > (float)0.5) )     \
    {                                                       \
        if (par##2 < par##0) { par##2 += 1.0; }             \
        else { par##0 += 1.0; par##1 += 1.0; }              \
        FLUSH_DUE_TO_WRAP(par);                             \
    }                                                       \
    else if( (emp > (float)0.5) && (elp > (float)0.5) )     \
    {                                                       \
        if(par##0 < par##1) { par##0 += 1.0; }              \
        else { par##1 += 1.0; par##2 += 1.0; }              \
        FLUSH_DUE_TO_WRAP(par);                             \
    }                                                       \
    else                                                    \
    {                                                       \
        DONT_FLUSH_DUE_TO_WRAP(par);                        \
    }                                                       \
} else {                                                    \
    DONT_FLUSH_DUE_TO_WRAP(par);                            \
}

 
#define WRAP_LINE(par, wrapit) if(wrapit) {                 \
    float elp;                                              \
    elp = (float)fabs(par##1 - par##0);                     \
    if(elp > (float)0.5)                                    \
    {                                                       \
        if (par##1 < par##0) { par##1 += 1.0; }             \
        else { par##0 += 1.0;}                              \
        FLUSH_DUE_TO_WRAP(par);                             \
    }                                                       \
    else                                                    \
    {                                                       \
        DONT_FLUSH_DUE_TO_WRAP(par);                        \
    }                                                       \
} else {                                                    \
    DONT_FLUSH_DUE_TO_WRAP(par);                            \
}


//-----------------------------------------------------------------------------
//                  Texture coordinate recentering macros
//-----------------------------------------------------------------------------

// Keeps the texture coordinates centered around 0 
// and avoid exceeding the texel wrapping limit.
#define RECENTER_TEX_COORDS(Maxf, Maxi, fTC0, fTC1, fTC2)                \
{                                                                        \
    long tcmax;                                                          \
    unsigned long tcmin;                                                 \
    int i;                                                               \
                                                                         \
    tcmax = LONG_AT(fTC0);                                               \
    if (tcmax < LONG_AT(fTC1)) tcmax = LONG_AT(fTC1);                    \
    if (tcmax < LONG_AT(fTC2)) tcmax = LONG_AT(fTC2);                    \
    if (tcmax >= *(long *)&Maxf)                                         \
    {                                                                    \
        myFtoi(&i, *(float *)&tcmax);                                    \
        i -= Maxi;                                                       \
        fTC0 -= i;                                                       \
        fTC1 -= i;                                                       \
        fTC2 -= i;                                                       \
    }                                                                    \
    else                                                                 \
    {                                                                    \
        tcmin = ULONG_AT(fTC0);                                          \
        if (tcmin < ULONG_AT(fTC1)) tcmin = ULONG_AT(fTC1);              \
        if (tcmin < ULONG_AT(fTC2)) tcmin = ULONG_AT(fTC2);              \
        if (*(float *)&tcmin <= -Maxf)                                   \
        {                                                                \
            myFtoi(&i, *(float *)&tcmin);                                \
            i += Maxi;                                                   \
            fTC0 -= i;                                                   \
            fTC1 -= i;                                                   \
            fTC2 -= i;                                                   \
        }                                                                \
    }                                                                    \
}

#endif //#ifdef _DLL_D3DTEXT_H_
