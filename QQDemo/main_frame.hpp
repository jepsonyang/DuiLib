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
	virtual CDuiString GetSkinFile() const override;
	virtual UILIB_RESOURCETYPE GetResourceType() const override;
	virtual LPCTSTR GetResourceID() const override;
	virtual CControlUI* CreateControl(LPCTSTR pstrClass) override;

	DWORD GetBkColor();
	void SetBkColor(DWORD dwBackColor);

protected:
	virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam) override;
	
	virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;

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