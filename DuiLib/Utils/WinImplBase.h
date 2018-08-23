#ifndef __WINIMPLBASE_H__
#define __WINIMPLBASE_H__

namespace DuiLib
{
	enum UILIB_RESOURCETYPE
	{
		UILIB_FILE = 1,		// 来自磁盘文件
		UILIB_ZIP,			// 来自磁盘zip压缩包
		UILIB_RESOURCE,		// 来自资源
		UILIB_ZIPRESOURCE,	// 来自资源的zip压缩包
	};

	class DUILIB_API WindowImplBase
		: public CWindowWnd
		, public CNotifyPump
		, public INotifyUI
		, public IMessageFilterUI
		, public IDialogBuilderCallback
	{
		DUI_DECLARE_MESSAGE_MAP()
	public:
		WindowImplBase() {}
		virtual ~WindowImplBase() {}

		virtual CDuiString GetSkinFolder() const;
		virtual CDuiString GetSkinFile() const = 0;

		virtual UILIB_RESOURCETYPE GetResourceType() const;
		virtual CDuiString GetZIPFileName() const;
		virtual LPCTSTR GetResourceID() const;
		virtual LONG GetStyle() const;

		//CWindowWnd
		virtual LPCTSTR GetWindowClassName(void) const override = 0;
		virtual UINT GetClassStyle() const override;
		//INotifyUI
		virtual void Notify(TNotifyUI& msg) override;
		//IMessageFilterUI
		virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled) override;
		//IDialogBuilderCallback
		virtual CControlUI* CreateControl(LPCTSTR pstrClass) override;
	
	protected:
		//CWindowWnd
		virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
		virtual void OnFinalMessage(HWND hWnd) override;

		virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);
		
		virtual void InitWindow() {};

		virtual void OnClick(TNotifyUI& msg);

		virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnLButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		#if defined(WIN32) && !defined(UNDER_CE)
		virtual LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnMouseWheel(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnMouseHover(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		#endif

	protected:
		CPaintManagerUI	m_PaintManager;
		static LPBYTE	m_lpResourceZIPBuffer;
	};
}

#endif // __WINIMPLBASE_H__
