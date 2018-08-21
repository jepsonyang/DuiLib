#pragma once

#include <UIlib.h>
using namespace DuiLib;

class C360SafeFrameWnd : public CWindowWnd, public INotifyUI
{
private:
	//override CWindowWnd
	LPCTSTR GetWindowClassName() const override;
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

	//override INotifyUI
	void Notify(TNotifyUI& msg) override;

private:
	LRESULT _OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT _OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	void _Init();
	void _OnPrepare();
	
private:
	CPaintManagerUI m_pm;

	CButtonUI * m_pCloseBtn = nullptr;
	CButtonUI* m_pMaxBtn = nullptr;
	CButtonUI* m_pRestoreBtn = nullptr;
	CButtonUI* m_pMinBtn = nullptr;
};
