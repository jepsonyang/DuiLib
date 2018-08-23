#include "stdafx.h"
#include <Uilib.h>
#include "main_frame.hpp"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
    CPaintManagerUI::SetInstance(hInstance);
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	MainFrame frame;
	frame.Create(NULL, _T("QQ2011"), UI_WNDSTYLE_FRAME, WS_EX_STATICEDGE | WS_EX_APPWINDOW, 0, 0, 600, 800);
	frame.CenterWindow();
	frame.ShowWindow();

	CPaintManagerUI::MessageLoop();
	CPaintManagerUI::Term();

	return 0;
}