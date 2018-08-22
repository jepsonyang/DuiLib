#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include "skin_change_event.hpp"
#include "UIFriends.hpp"

class MainFrame : public WindowImplBase
{
public:
	MainFrame();
	~MainFrame();

public:
	LPCTSTR GetWindowClassName() const override;	
	virtual void OnFinalMessage(HWND hWnd) override;
	virtual void InitWindow() override;
	virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam) override;
	virtual CDuiString GetSkinFile() override;
	virtual CDuiString GetSkinFolder() override;
	virtual UILIB_RESOURCETYPE GetResourceType() const override;
	virtual CControlUI* CreateControl(LPCTSTR pstrClass) override;
	virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual LPCTSTR GetResourceID() const override;

    DWORD GetBkColor();
    void SetBkColor(DWORD dwBackColor);

protected:
	void Notify(TNotifyUI& msg) override;

	void OnPrepare(TNotifyUI& msg);
	void OnExit(TNotifyUI& msg);
	void OnTimer(TNotifyUI& msg);

private:
	void UpdateFriendsList();

	void UpdateGroupsList();

	void UpdateMicroBlogList();

private:
	int bk_image_index_;

	FriendListItemInfo myself_info_;
	std::vector<FriendListItemInfo> friends_;

	SkinChangedObserver skin_changed_observer_;
};

#endif // MAINFRAME_HPP