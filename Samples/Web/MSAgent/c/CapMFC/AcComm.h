#if !defined(AFX_AGENTCTLCOMMANDEX_H__AB8FEBA2_3841_11D2_8512_00C04FA34A14__INCLUDED_)
#define AFX_AGENTCTLCOMMANDEX_H__AB8FEBA2_3841_11D2_8512_00C04FA34A14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CAgentCtlCommandEx wrapper class

class CAgentCtlCommandEx : public COleDispatchDriver
{
public:
	CAgentCtlCommandEx() {}		// Calls COleDispatchDriver default constructor
	CAgentCtlCommandEx(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAgentCtlCommandEx(const CAgentCtlCommandEx& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetVoice();
	void SetVoice(LPCTSTR lpszNewValue);
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	BOOL GetEnabled();
	void SetEnabled(BOOL bNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	long GetConfidence();
	void SetConfidence(long nNewValue);
	CString GetConfidenceText();
	void SetConfidenceText(LPCTSTR lpszNewValue);
	void SetHelpContextID(long nNewValue);
	long GetHelpContextID();
	void SetVoiceCaption(LPCTSTR lpszNewValue);
	CString GetVoiceCaption();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGENTCTLCOMMANDEX_H__AB8FEBA2_3841_11D2_8512_00C04FA34A14__INCLUDED_)
