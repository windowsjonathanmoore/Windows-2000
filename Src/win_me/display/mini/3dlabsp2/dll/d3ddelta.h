/******************************Module*Header**********************************\
*
*                           *************************************
*                           * Permedia 2: Direct 3D SAMPLE CODE *
*                           *************************************
*
* Module Name: d3ddelta.h
*
*  Content: 3DLabs Delta unit related defines. Used only by D3D.
*
* Copyright (c) 1994-1998 3Dlabs Inc. Ltd. All rights reserved.
* Copyright (c) 1995-1999 Microsoft Corporation.  All rights reserved.
\*****************************************************************************/
#ifndef _DLL_D3DDELTA_H_
#define _DLL_D3DDELTA_H_

//-----------------------------------------------------------------------------
//   Conversion macros from ARGB values into Delta Gambit registers format
//-----------------------------------------------------------------------------
#define RGB_GET_GAMBIT_ALPHA(ci)  (((ci) & 0xff000000) >> 2)
#define RGB_GET_GAMBIT_RED(ci)    (((ci) & 0xff0000) << 6)
#define RGB_GET_GAMBIT_GREEN(ci)  (((ci) & 0xff00) << 14)
#define RGB_GET_GAMBIT_BLUE(ci)   (((ci) & 0xff) << 22)

#define RGB_GET_GAMBIT_FOG(ci)    (((ci) & 0xff000000) >> 10)

#define AS_ULONG(val)   *((volatile DWORD *) &(val))


//-----------------------------------------------------------------------------
//     Macros defining the different Vertex types.tags for the Delta unit
//-----------------------------------------------------------------------------

#define VTX_FOG     (0x1 << 25)     
#define VTX_RGB     (0x7 << 21)
#define VTX_R       (0x1 << 21)
#define VTX_RGBA    (0xF << 21)
#define VTX_COLOR   (0x1 << 30)
#define VTX_STQ     (0x7 << 16)
#define VTX_KSKD    (0x3 << 19)
#define VTX_KS      (0x1 << 19)
#define VTX_XYZ     (0x7 << 26)
#define VTX_XY      (0x3 << 26)
#define VTX_GRP     (0x2 << 14)

#define GAMBIT_RGB_VTX                (VTX_GRP | VTX_RGB | VTX_XYZ)   
#define GAMBIT_RGB_F_VTX              (VTX_GRP | VTX_RGB | VTX_XYZ | VTX_FOG) 
#define GAMBIT_RGB_TEX_VTX            (VTX_GRP | VTX_RGB | VTX_XYZ | VTX_STQ)
#define GAMBIT_RGB_F_TEX_VTX          (VTX_GRP | VTX_RGB | VTX_XYZ |         \
                                                 VTX_STQ | VTX_FOG)
#define GAMBIT_RGBA_VTX               (VTX_GRP | VTX_RGBA | VTX_XYZ)  
#define GAMBIT_RGBA_F_VTX             (VTX_GRP | VTX_RGBA | VTX_XYZ | VTX_FOG)
#define GAMBIT_RGBA_TEX_VTX           (VTX_GRP | VTX_RGBA | VTX_XYZ | VTX_STQ)
#define GAMBIT_RGBA_F_TEX_VTX         (VTX_GRP | VTX_RGBA | VTX_XYZ |        \
                                                 VTX_STQ | VTX_FOG)
#define GAMBIT_FLAT_VTX               (VTX_GRP | VTX_XYZ)
#define GAMBIT_XYZ_VTX                (VTX_GRP | VTX_XYZ)
#define GAMBIT_XYZ_COLOR_VTX          (VTX_GRP | VTX_XYZ | VTX_COLOR)
#define GAMBIT_XYZ_STQ_VTX            (VTX_GRP | VTX_XYZ | VTX_STQ)
#define GAMBIT_XYZ_STQ_FOG_VTX        (VTX_GRP | VTX_XYZ | VTX_STQ | VTX_FOG)
#define GAMBIT_XYZ_STQ_KSKD_VTX       (VTX_GRP | VTX_XYZ | VTX_STQ | VTX_KSKD)
#define GAMBIT_XYZ_STQ_KS_VTX         (VTX_GRP | VTX_XYZ | VTX_STQ | VTX_KS)
#define GAMBIT_XYZ_STQ_KS_COL_VTX     (VTX_GRP | VTX_XYZ | VTX_STQ |         \
                                                 VTX_KS | VTX_COLOR)
#define GAMBIT_XYZ_STQ_KS_COL_FOG_VTX (VTX_GRP | VTX_XYZ | VTX_STQ |         \
                                                 VTX_KS | VTX_COLOR | VTX_FOG)
#define GAMBIT_XY_VTX                 (VTX_GRP | VTX_XY)
#define GAMBIT_XY_STQ_VTX             (VTX_GRP | VTX_XY | VTX_STQ)
#define GAMBIT_XY_STQ_FOG_VTX         (VTX_GRP | VTX_XY | VTX_STQ | VTX_FOG)
#define GAMBIT_XY_STQ_KSKD_VTX        (VTX_GRP | VTX_XY | VTX_STQ | VTX_KSKD)
#define GAMBIT_COLS_VTX               (VTX_GRP | VTX_RGB)
#define GAMBIT_PACKED_COLS_VTX        (VTX_GRP | VTX_COLOR)
#define GAMBIT_COLS_ALPHA_VTX         (VTX_GRP | VTX_RGBA)
#define GAMBIT_COLS_KSKD_VTX          (VTX_GRP | VTX_RGB | VTX_KSKD)
#define GAMBIT_FLAT_F_VTX             (VTX_GRP | VTX_XYZ | VTX_FOG)
#define GAMBIT_FLAT_TEX_VTX           (VTX_GRP | VTX_XYZ | VTX_STQ)
#define GAMBIT_FLAT_F_TEX_VTX         (VTX_GRP | VTX_XYZ | VTX_STQ | VTX_FOG)
#define GAMBIT_CI_VTX                 (VTX_GRP | VTX_R | VTX_XYZ) 
#define GAMBIT_CI_F_VTX               (VTX_GRP | VTX_R | VTX_XYZ | VTX_FOG)


//-----------------------------------------------------------------------------
//                     Vertex Data downloading macros
//-----------------------------------------------------------------------------
// 4 Entries
#define SEND_VERTEX_XYZ(ppdev, Num, x_value, y_value, z_value)  \
{                                                               \
    LOAD_INPUT_FIFO_DATA(ppdev, (GAMBIT_XYZ_VTX | Num));        \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(x_value));             \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(y_value));             \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(z_value));             \
}

// 7 Entries
#define SEND_VERTEX_STQ_XYZ(ppdev, Num, s_value, t_value, q_value,  \
                                 x_value, y_value, z_value)         \
{                                                                   \
    LOAD_INPUT_FIFO_DATA(ppdev,  (GAMBIT_XYZ_STQ_VTX | Num));       \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(s_value));                 \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(t_value));                 \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(q_value));                 \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(x_value));                 \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(y_value));                 \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(z_value));                 \
}

// 8 Entries
#define SEND_VERTEX_STQ_KS_XYZ(ppdev, Num, s_value, t_value, q_value,   \
                                    Ks_value, x_value, y_value, z_value)\
{                                                                       \
    LOAD_INPUT_FIFO_DATA(ppdev,  (GAMBIT_XYZ_STQ_KS_VTX | Num));        \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(s_value));                     \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(t_value));                     \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(q_value));                     \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(Ks_value));                    \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(x_value));                     \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(y_value));                     \
    LOAD_INPUT_FIFO_DATA(ppdev, AS_ULONG(z_value));                     \
}

// 2 Entries
#define SEND_VERTEX_FOG(ppdev, vNo, fog_value)  \
{                                               \
    LOAD_INPUT_FIFO_DATA(ppdev, vNo);           \
    LOAD_INPUT_FIFO_DATA(ppdev, fog_value);     \
}

// 4 Entries
#define SEND_VERTEX_RGB_MONO(ppdev, vNo, Color)             \
{                                                           \
    LOAD_INPUT_FIFO_DATA(ppdev, (GAMBIT_COLS_VTX | vNo));   \
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_BLUE(Color));\
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_BLUE(Color));\
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_BLUE(Color));\
}

// 4 Entries
#define SEND_VERTEX_RGB(ppdev, vNo, Color)                  \
{                                                           \
    LOAD_INPUT_FIFO_DATA(ppdev, (GAMBIT_COLS_VTX | vNo));   \
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_RED(Color)); \
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_GREEN(Color));\
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_BLUE(Color));\
}

// 2 Entries
#define SEND_VERTEX_RGBA_P2(ppdev, vNo, Color)                  \
{                                                               \
    LOAD_INPUT_FIFO_DATA(ppdev, (GAMBIT_PACKED_COLS_VTX | vNo));\
    LOAD_INPUT_FIFO_DATA(ppdev, Color);                         \
}

// 2 Entries
#define SEND_VERTEX_RGB_MONO_P2(pdev, vNo, Color)                                   \
{                                                                                   \
    DWORD dwBlueVal = RGB_GET_GAMBIT_BLUE(Color);                                   \
    LOAD_INPUT_FIFO_DATA(ppdev, (GAMBIT_PACKED_COLS_VTX | vNo));                    \
    LOAD_INPUT_FIFO_DATA(ppdev, dwBlueVal | (dwBlueVal << 8) | (dwBlueVal << 16));  \
}

// 5 Entries
#define SEND_VERTEX_RGBA(ppdev, vNo, Color)                         \
{                                                                   \
    LOAD_INPUT_FIFO_DATA(ppdev, (GAMBIT_COLS_ALPHA_VTX | vNo));     \
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_RED(Color));         \
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_GREEN(Color));       \
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_BLUE(Color));        \
    LOAD_INPUT_FIFO_DATA(ppdev, RGB_GET_GAMBIT_ALPHA(Color));       \
}

//-----------------------------------------------------------------------------
//                        HW Alpha stippling macros
//-----------------------------------------------------------------------------

extern DWORD FlatStipplePatterns[128];

#define SET_STIPPLED_ALPHA(ppdev, AlphaValue)                                           \
{                                                                                       \
    DWORD* pStipple;                                                                    \
    DWORD NewAlpha = AlphaValue;                                                        \
    if (NewAlpha != pContext->LastAlpha)                                                \
    {                                                                                   \
        pContext->LastAlpha = NewAlpha;                                                 \
        pStipple = FlatStipplePatterns + (NewAlpha << 3);                               \
        LOAD_INPUT_FIFO_DATA(ppdev, (0x00ff8000 | __Permedia2TagAreaStipplePattern0));  \
        LOAD_INPUT_FIFO_DATA(ppdev, pStipple[0]);                                       \
        LOAD_INPUT_FIFO_DATA(ppdev, pStipple[1]);                                       \
        LOAD_INPUT_FIFO_DATA(ppdev, pStipple[2]);                                       \
        LOAD_INPUT_FIFO_DATA(ppdev, pStipple[3]);                                       \
        LOAD_INPUT_FIFO_DATA(ppdev, pStipple[4]);                                       \
        LOAD_INPUT_FIFO_DATA(ppdev, pStipple[5]);                                       \
        LOAD_INPUT_FIFO_DATA(ppdev, pStipple[6]);                                       \
        LOAD_INPUT_FIFO_DATA(ppdev, pStipple[7]);                                       \
                                                                                        \
    }                                                                                   \
    RENDER_AREA_STIPPLE_ENABLE(ulRenderCmd);                                            \
}

//-----------------------------------------------------------------------------
//                        Rendering command setup macros
//-----------------------------------------------------------------------------

#define RENDER_AREA_STIPPLE_ENABLE(a) a |= __RENDER_AREA_STIPPLE_ENABLE;
#define RENDER_AREA_STIPPLE_DISABLE(a) a &= ~__RENDER_AREA_STIPPLE_ENABLE;

#define RENDER_TEXTURE_ENABLE(a) a |= __RENDER_TEXTURE_ENABLE;
#define RENDER_TEXTURE_DISABLE(a) a &= ~__RENDER_TEXTURE_ENABLE;

#define RENDER_FOG_ENABLE(a) a |= (1 << 14);
#define RENDER_FOG_DISABLE(a) a &= ~(1 << 14);

#define RENDER_SUB_PIXEL_CORRECTION_ENABLE(a) a |= (1 << 16);
#define RENDER_SUB_PIXEL_CORRECTION_DISABLE(a) a &= ~(1 << 16);


#define RENDER_LINE(a) a &= ~(0xC0);
#define RENDER_TRAPEZOID(a) {a &= ~(0xC0); a |= (0x40);}
#define RENDER_POINT(a) {a &= ~(0xC0);a |= (0x80);}

#define RENDER_NEGATIVE_CULL(a) a |= (1 << 20);
#define RENDER_POSITIVE_CULL(a) a &= ~(1 << 20);


#endif /* #ifndef _DLL_D3DDELTA_H_ */