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

	ON_WM_PAINT()    //��ͼ��
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

void MyFrame::OnPaint()
{
	CPaintDC dc(this);   //CDC�����������ܻ���ͼ��

	dc.TextOutW(100, 100, TEXT("��Ƥ"));
	//����Բ
	dc.Ellipse(10, 10, 100, 100);

	//���ֽ�תΪ ���ֽ�
	//TEXT��������Ӧ�����ת��
	//TCHAR ����Ӧ�����ת��
	//MessageBox(L"AAA");

	//ͳ���ַ�������
	int num = 0;
	char* p ="aaa";
	num = strlen(p);

	//ͳ�ƿ��ֽڵ��ַ�������
	wchar_t *p2 = L"bbbb";
	num = wcslen(p2);
	
	//char* ��CString ֮���ת��       C++  string .c_str()
	//char*  ->  CString
	char *p3 = "cccc";
	CString str = CString(p3);

	//CSTRING   ->  char*
	CStringA tmp;
	tmp = str;
	char *pp = tmp.GetBuffer();

}
