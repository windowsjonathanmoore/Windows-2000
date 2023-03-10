#if !defined(AFX_AGENTCTLEX_H__AB8FEBA6_3841_11D2_8512_00C04FA34A14__INCLUDED_)
#define AFX_AGENTCTLEX_H__AB8FEBA6_3841_11D2_8512_00C04FA34A14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CAgentCtlCharacters;
class CAgentCtlPropertySheet;
class CAgentCtlAudioObject;

/////////////////////////////////////////////////////////////////////////////
// CAgentCtlEx wrapper class

class CAgentCtlEx : public CWnd
{
protected:
	DECLARE_DYNCREATE(CAgentCtlEx)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xd45fd31b, 0x5c6e, 0x11d1, { 0x9e, 0xc1, 0x0, 0xc0, 0x4f, 0xd7, 0x8, 0x1f } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	CAgentCtlCharacters GetCharacters();
	CAgentCtlAudioObject GetAudioOutput();
	LPDISPATCH GetSpeechInput();
	CAgentCtlPropertySheet GetPropertySheet();
	LPDISPATCH GetCommandsWindow();
	BOOL GetConnected();
	void SetConnected(BOOL bNewValue);
	BOOL GetSuspended();
	void ShowDefaultCharacterProperties(const VARIANT& x, const VARIANT& y);
	BOOL GetRaiseRequestErrors();
	void SetRaiseRequestErrors(BOOL bNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGENTCTLEX_H__AB8FEBA6_3841_11D2_8512_00C04FA34A14__INCLUDED_)
