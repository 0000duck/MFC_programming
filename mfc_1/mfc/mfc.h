#pragma once
#include<afxwin.h>  //mfcͷ�ļ�

class MyApp :public CWinApp     //CWinApp Ӧ�ó�����
{
public:
	//�������
	virtual BOOL InitInstance();

};

class MyFrame :public CFrameWnd   //���ڿ����
{
public:
	MyFrame();

	//������  �ṩ��Ϣӳ�����
	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
};
