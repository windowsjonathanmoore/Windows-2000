//
// Copyright (c) 1998-1999  Microsoft Corporation
//


///////////////////////////////////////////////////////////////////////////
// h323priv.h : header file for H323 msp private interfaces
/////////////////////////////////////////////////////////////////////////////

#ifndef __H323_PRIVATE_H__
#define __H323_PRIVATE_H__

#define H245_CAPABILITY_DEFINED 1

typedef enum H245_CAPABILITY
{
    HC_G711,
    HC_G723,
    HC_H263QCIF,
    HC_H261QCIF

} H245_CAPABILITY;


interface DECLSPEC_UUID("44cf6a9d-cb40-4bbc-b2d3-b6aa93322c71") DECLSPEC_NOVTABLE 
IH323LineEx : public IUnknown
{
    STDMETHOD (SetExternalT120Address) (
        IN  BOOL    fEnable,
        IN  DWORD   dwIP,
        IN  WORD    wPort
        ) PURE;

    STDMETHOD (SetDefaultCapabilityPreferrence) (
        IN  DWORD              dwNumCaps,
        IN  H245_CAPABILITY *  pCapabilities,
        IN  DWORD *            pWeights
        ) PURE;

    STDMETHOD (SetAlias) (
        IN WCHAR *strAlias,
        IN DWORD dwLength
        ) PURE;
};
#define IID_IH323LineEx (__uuidof(IH323LineEx))


interface DECLSPEC_UUID("c3341386-af91-4ef9-83b6-be3762e42ecb") DECLSPEC_NOVTABLE 
IKeyFrameControl : public IUnknown
{
    STDMETHOD (UpdatePicture) () PURE;

    STDMETHOD (PeriodicUpdatePicture) (
        IN BOOL fEnable, 
        IN DWORD dwInterval
        ) PURE;
};

#define IID_IKeyFrameControl (__uuidof(IKeyFrameControl))


#ifndef RTP_MEDIATYPE_DEFINED
#define RTP_MEDIATYPE_DEFINED

struct DECLSPEC_UUID("14099BC0-787B-11d0-9CD3-00A0C9081C19") MEDIATYPE_RTP_Single_Stream;

#endif //RTP_MEDIATYPE_DEFINED

#endif // __IPCONF_PRIVATE_H__
