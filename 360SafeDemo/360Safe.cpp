#include <Windows.h>
#include "C360SafeFrameWnd.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));
	CPaintManagerUI::SetResourceZip(_T("360SafeRes.zip"));

	C360SafeFrameWnd frameWnd;
	frameWnd.Create(NULL, _T("360°²È«ÎÀÊ¿"), UI_WNDSTYLE_FRAME, 0, 0, 0, 800, 572);
	frameWnd.CenterWindow();
	frameWnd.ShowWindow();

	CPaintManagerUI::MessageLoop();

	return 0;
}