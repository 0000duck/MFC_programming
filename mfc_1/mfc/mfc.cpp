#include "mfc.h"

MyApp app; //全局应用程序对象，有且仅有一个

BOOL MyApp::InitInstance()
{
	//创建窗口
	MyFrame * frame = new MyFrame;
	//显示和更新
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	m_pMainWnd = frame;    //保存指向应用程序的主窗口的指针

	return TRUE;      //返回正常初始化
	
}

//分界宏

BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
	
	ON_WM_LBUTTONDOWN()  //鼠标左键按下

	ON_WM_CHAR()   //键盘

END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	Create(NULL, TEXT("mfc"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{
	/*
	TCHAR buf[1024];

	wsprintf(buf, TEXT("x=%d,y=%d"), point.x, point.y);

	MessageBox(buf);
	*/
	//MFC中的字符串 CString

	CString str;
	str.Format(TEXT("X=%d,,,,,y=%d"),point.x,point.y);
	MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT)
{
	CString str;
	str.Format(TEXT("按下了%c键 "), key);

	MessageBox(str);
}
