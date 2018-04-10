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

	ON_WM_PAINT()    //绘图宏
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

void MyFrame::OnPaint()
{
	CPaintDC dc(this);   //CDC里找其他的能画的图形

	dc.TextOutW(100, 100, TEXT("瓜皮"));
	//画椭圆
	dc.Ellipse(10, 10, 100, 100);

	//多字节转为 宽字节
	//TEXT是由自适应编码的转换
	//TCHAR 自适应编码的转换
	//MessageBox(L"AAA");

	//统计字符串长度
	int num = 0;
	char* p ="aaa";
	num = strlen(p);

	//统计宽字节的字符串长度
	wchar_t *p2 = L"bbbb";
	num = wcslen(p2);
	
	//char* 与CString 之间的转换       C++  string .c_str()
	//char*  ->  CString
	char *p3 = "cccc";
	CString str = CString(p3);

	//CSTRING   ->  char*
	CStringA tmp;
	tmp = str;
	char *pp = tmp.GetBuffer();

}
