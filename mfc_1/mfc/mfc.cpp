#include "mfc.h"

MyApp app; //ȫ��Ӧ�ó���������ҽ���һ��

BOOL MyApp::InitInstance()
{
	//��������
	MyFrame * frame = new MyFrame;
	//��ʾ�͸���
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	m_pMainWnd = frame;    //����ָ��Ӧ�ó���������ڵ�ָ��

	return TRUE;      //����������ʼ��
	
}

//�ֽ��

BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
	
	ON_WM_LBUTTONDOWN()  //����������

	ON_WM_CHAR()   //����

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
	//MFC�е��ַ��� CString

	CString str;
	str.Format(TEXT("X=%d,,,,,y=%d"),point.x,point.y);
	MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT)
{
	CString str;
	str.Format(TEXT("������%c�� "), key);

	MessageBox(str);
}
