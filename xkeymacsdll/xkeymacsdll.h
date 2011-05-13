// xkeymacs.h: interface for the CXkeymacsDll class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XKEYMACS_H__88552DEC_1233_4A0A_BE62_9EF7BC618EC6__INCLUDED_)
#define AFX_XKEYMACS_H__88552DEC_1233_4A0A_BE62_9EF7BC618EC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ClipboardSnap.h"

enum { MAX_APP = 64 };
enum { NONE = 0x0, SHIFT = 0x1, CONTROL = 0x2, META = 0x4, CONTROLX = 0x8,
	   MAX_COMMAND_TYPE = NONE + SHIFT + CONTROL + META + CONTROLX + 1 };
enum { /* WIN_SHIFT = 0x100, */ WIN_CTRL = 0x200, WIN_ALT = 0x400, WIN_WIN = 0x800 };
enum { MAX_KEY = 256 };
enum { MAX_FUNCTION = 64 };
enum { MAX_DEFINITION = 256 };

enum { WINDOW_NAME_LENGTH	= 128 };
enum { CLASS_NAME_LENGTH	= 128 };
enum { SUB_KEY_NAME_LENGTH	= 128 };
enum { WINDOW_TEXT_LENGTH   = 128 + 128 + 3};

enum ICON_TYPE { MAIN_ICON, CX_ICON, MX_ICON, META_ICON, SHIFT_ICON, CTRL_ICON, ALT_ICON, MAX_ICON_TYPE };
enum XKEYMACS_STATUS { STATUS_ENABLE, STATUS_DISABLE_TMP, STATUS_DISABLE_WOCQ, STATUS_DISABLE, MAX_STATUS };
enum { ON_ICON, OFF_ICON };	// alias of status

enum GOTO { GOTO_DO_NOTHING, GOTO_HOOK, GOTO_RECURSIVE, GOTO_HOOKX, GOTO_HOOK0_9, CONTINUE };
enum SETTING_STYLE { SETTING_DEFAULT, SETTING_SPECIFIC, SETTING_DISABLE, SETTING_UNDEFINED };

enum { EXTENDED_KEY = 0x01000000 };
enum { REPEATED_KEY = 0x40000000 };
enum { BEING_RELEASED = 0x80000000 };

struct KeyBind
{
	int nCommandType;
	BYTE bVk;
	int nControlID;
};

struct KeyName
{
	BYTE bVk;
	LPCTSTR name;
};

class AFX_EXT_CLASS CXkeymacsDll  
{
public:
	static void ModifyM_xTip(const TCHAR *const szPath);
	static BOOL Get326Compatible();
	void Set326Compatible(int nApplicationID, BOOL b326Compatible);
	void SetCursorData(HCURSOR hEnable, HCURSOR hDisableTMP, HCURSOR hDisableWOCQ, HICON hDisable, BOOL bEnable);
	static unsigned int GetMaxKeyInterval(void);
	static void SetKeyboardSpeed(int nKeyboardSpeed);
	static int GetAccelerate(void);
	static void SetAccelerate(int nAccelerate);
	void SetWindowText(int nApplicationID, CString szWindowText);
	void AddAllShell_NotifyIcon();
	void DeleteAllShell_NotifyIcon();
	void SetKillRingMax(int nApplicationID, int nKillRingMax);
	void CXkeymacsDll::EnableShell_NotifyIcon(ICON_TYPE icon, BOOL bEnable);
	void SetNotifyIconData(ICON_TYPE icon, NOTIFYICONDATA stNtfyIcon, HICON hEnable, HICON hDisableTMP, HICON hDisableWOCQ, HICON hDisable, BOOL bEnable);
	void SetNotifyIconData(ICON_TYPE icon, NOTIFYICONDATA stNtfyIcon, HICON hOn, HICON hOff, BOOL bEnable);
	void Clear(int nApplicationID);
	BOOL IsKeyboardHook();
	void SetCommandID(int nApplicationID, int nCommandType, int nKey, int nCommandID);
	void SetAtIbeamCursorOnly(int nApplicationID, int nCommandType, int nKey, BOOL bAtIbeamCursorOnly);
	void SetApplicationName(int nApplicationID, CString szApplicationName);
	static void ReleaseHooks();
	static void ReleaseKeyboardHook();
	void SetEnableCUA(int nApplicationID, BOOL bEnableCUA);
	void SetIgnoreUndefinedC_x(int nApplicationID, BOOL bIgnoreUndefinedC_x);
	void SetIgnoreUndefinedMetaCtrl(int nApplicationID, BOOL bIgnoreUndefinedMetaCtrl);
	static void SetHooks();
	static void SetKeyboardHook();
	void SetSettingStyle(int nApplicationID, int nSettingStyle);
	void SetUseDialogSetting(int nApplicationID, BOOL bUseDialogSetting);
	static void AddKillRing(BOOL bNewData = TRUE);
	static void CallMacro();
	static void ClearFunctionDefinition();
	static void DefiningMacro(BOOL bDefiningMacro);
	static void DepressKey(BYTE bVk, BOOL bOriginal = TRUE);
	static BOOL GetEnableCUA();
	static CClipboardSnap* GetKillRing(CClipboardSnap *pSnap, BOOL bForce = TRUE);
	static void IncreaseKillRingIndex(int nKillRing = 1);
	static BOOL IsDown(BYTE bVk, BOOL bPhysicalKey = TRUE);
	static void Kdu(BYTE bVk, DWORD n = 1, BOOL bOriginal = TRUE);
	static int ModifyShell_NotifyIcon(ICON_TYPE icon, BOOL bNewStatus, BOOL bForce = TRUE);
	static void ReleaseKey(BYTE bVk);
	static void SetFunctionDefinition(int nFunctionID, CString szDefinition);
	static void SetFunctionKey(int nFunctionID, int nApplicationID, int nCommandType, int nKey);
	static void SetKeyboardHookFlag();
	static void SetKeyboardHookFlag(BOOL bFlag);
	static BOOL Is106Keyboard();
	static void Set106Keyboard(BOOL b106Keyboard);
	CXkeymacsDll();
	virtual ~CXkeymacsDll();
private:
	static void InvokeM_x(const TCHAR* const szPath);
	static BOOL m_b326Compatible[MAX_APP];
	static void LogCallWndProcMessage(WPARAM wParam, LPARAM lParam);
	static void DoSetCursor();
	static HCURSOR m_hCurrentCursor;
	static BOOL m_bCursor;
	static HCURSOR m_hCursor[MAX_STATUS];
	static int m_nKeyboardSpeed;
	static int m_nAccelerate;
	static HHOOK m_hHookCallWndRet;
	static LRESULT CALLBACK CallWndRetProc(int nCode, WPARAM wParam, LPARAM lParam);
	static BOOL IsMatchWindowText(CString szWindowText);
	static TCHAR m_szWindowText[MAX_APP][WINDOW_TEXT_LENGTH];
	static BOOL m_bEnableKeyboardHook;
	static HHOOK m_hHookCallWnd;
	static HHOOK m_hHookGetMessage;
	static HHOOK m_hHookShell;
	static void AddShell_NotifyIcon(ICON_TYPE icon);
	void DeleteShell_NotifyIcon(ICON_TYPE icon);
	static BOOL DefiningMacro();
	static BOOL IsControl();
	static BOOL IsMeta();
	static void DoKeybd_event(BYTE bVk, DWORD dwFlags);
	static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK CallWndProc(int nCode, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK ShellProc(int nCode, WPARAM wParam, LPARAM lParam);
	static KeyBind ParseKey(const int nFunctionID, unsigned int &i);
	static BYTE a2v(TCHAR nAscii);
	static BOOL IsShift(TCHAR nAscii);
	static TCHAR m_szFunctionDefinition[MAX_FUNCTION][MAX_DEFINITION];
	static void CallFunction(int nFunctionID);
	static int m_nFunctionID[MAX_APP][MAX_COMMAND_TYPE][MAX_KEY];
	static BOOL m_bEnableCUA[MAX_APP];
	static TCHAR m_szOldApplicationName[MAX_PATH];
	static TCHAR m_szApplicationName[MAX_PATH];
	static int IsPassThrough(BYTE nKey);
	static BOOL IsDepressedShiftKeyOnly(BYTE nKey);
	static BOOL IsDepressedModifier(int Modifier(), BOOL bPhysicalKey = TRUE);
	static BOOL IsValidKey(BYTE bVk);
	static CObList m_Macro;
	static BOOL m_bDefiningMacro;
	static void Original(int nCommandType, BYTE bVk, int nOriginal);
	static int Original(int nCommandType, BYTE bVk);
	static HICON m_hIcon[MAX_ICON_TYPE][MAX_STATUS];
	static BOOL m_bUseDialogSetting[MAX_APP];
	static void InitKeyboardProc(BOOL bImeComposition);
	static BOOL m_bIgnoreUndefinedC_x[MAX_APP];
	static BOOL m_bIgnoreUndefinedMetaCtrl[MAX_APP];
	static int m_nSettingStyle[MAX_APP];
	static int m_nApplicationID;
	static int m_nOriginal[MAX_COMMAND_TYPE][MAX_KEY];
	static int m_nKillRing;
	static CList<CClipboardSnap *, CClipboardSnap *> m_oKillRing;
	static int m_nKillRingMax[MAX_APP];
	static int GetMickey(int nDifferential, int nThreshold1, int nThreshold2, int nAcceleration, int nSpeed);
	static BOOL DoShell_NotifyIcon(ICON_TYPE icon, DWORD dwMessage);
	static BOOL m_bIcon[MAX_ICON_TYPE];
	static DWORD m_dwOldMessage[MAX_ICON_TYPE];
	static NOTIFYICONDATA m_stNtfyIcon[MAX_ICON_TYPE];
	static NOTIFYICONDATA m_stOldNtfyIcon[MAX_ICON_TYPE];
	static BOOL m_bHook;
	static BOOL m_bRightShift;
	static BOOL m_bRightAlt;
	static BOOL m_bRightControl;
	static TCHAR m_szSpecialApp[MAX_APP][CLASS_NAME_LENGTH];
	static int m_nCommandID[MAX_APP][MAX_COMMAND_TYPE][MAX_KEY];
	static BOOL m_bAtIbeamCursorOnly[MAX_APP][MAX_COMMAND_TYPE][MAX_KEY];
	static BOOL m_b106Keyboard;
};


class AFX_EXT_CLASS CXkeymacsData  
{
public:
	void Set326Compatible(BOOL b326Compatible);
	BOOL Get326Compatible();
	int GetWindowTextType();
	void SetWindowTextType(int nWindowTextType);
	CString GetWindowText();
	void SetWindowText(LPCTSTR lpszWindowText);
	static int GetToolTipID(int nCommandID);
	static int GetDescriptionID(int nCommandID);
	void SetUseDialogSetting(BOOL bUseDialogSetting);
	BOOL GetUseDialogSetting();
	BOOL GetEnableCUA();
	void SetEnableCUA(BOOL bEnableCUA);
	BOOL GetIgnoreUndefinedC_x();
	void SetIgnoreUndefinedC_x(BOOL bIgnoreUndefinedC_x);
	BOOL GetIgnoreUndefinedMetaCtrl();
	void SetIgnoreUndefinedMetaCtrl(BOOL bIgnoreUndefinedMetaCtrl);
	static int GetCategoryID(int nCommandID);
	void SetSettingStyle(int nSettingStyle);
	int GetSettingStyle();
	static int GetDefaultControlID(int nCommandID, int nIndex);
	static int GetDefaultCommandKey(int nCommandID, int nIndex);
	static int GetDefaultCommandType(int nCommandID, int nIndex);
	static CString GetCommandName(int nCommandID);
	void SetKillRingMax(int nKillRingMax);
	int GetKillRingMax();
	CString GetApplicationTitle();
	void SetApplicationTitle(LPCTSTR lpszApplicationTitle);
	void ClearAll();
	int GetCommandID(int nCommandType, int nKey);
	void SetCommandID(int nCommandType, int nKey, int nCommandID);
	BOOL GetAtIbeamCursorOnly(int nCommandType, int nKey);
	void SetAtIbeamCursorOnly(int nCommandType, int nKey, BOOL bAtIbeamCursorOnly);
	CString GetApplicationName();
	void SetApplicationName(LPCTSTR lpszApplicationName);
	CXkeymacsData();
	virtual ~CXkeymacsData();

private:
	BOOL m_b326Compatible;
	int m_nWindowTextType;
	CString m_strWindowText;
	BOOL m_bEnableCUA;
	BOOL m_bUseDialogSetting;
	BOOL m_bIgnoreUndefinedC_x;
	BOOL m_bIgnoreUndefinedMetaCtrl;
	int m_nSettingStyle;
	int m_nKillRingMax;
	CString m_strApplicationTitle;
	CString m_strApplicationName;
	int m_nCommandID[MAX_COMMAND_TYPE][MAX_KEY];
	BOOL m_bAtIbeamCursorOnly[MAX_COMMAND_TYPE][MAX_KEY];
};

#endif // !defined(AFX_XKEYMACS_H__88552DEC_1233_4A0A_BE62_9EF7BC618EC6__INCLUDED_)
