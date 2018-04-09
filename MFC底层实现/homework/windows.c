#include<Windows.h>  //�ײ�ʵ�ִ��ڵ�ͷ�ļ�

//6.�����ڳ���  
//CALLBACK  ������_stdcall  �����˲����Ĵ���˳�򣬴��ҵ���������ջ�������ں�������ǰ ��ն�ջ
LRESULT CALLBACK WindowProc(
	HWND hwnd,  //��Ϣ�����Ĵ��ھ��
	UINT uMsg,    //�������Ϣ����     WM_XXXX��Ϣ����
	WPARAM wParam,  //���̸�����Ϣ
	LPARAM lParam    //��긽����Ϣ
)
{
	//������xxxWindowΪ��β�ķ����������������Ϣ�����У�����ֱ��ִ��
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);  //������һ����Ϣ WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:   //����������
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);

		char buf[1024];
		wsprintf(buf,TEXT("x=%d,y=%d"), xPos, yPos);
		MessageBox(hwnd,buf, TEXT("��Ƥ"), MB_OK);
		break;
	}
	case WM_KEYDOWN:  //����
		MessageBox(hwnd, TEXT("hello"), TEXT("world"), MB_OK);
		break;

	case WM_PAINT:    //��ͼ
	{
		PAINTSTRUCT ps;  //��ͼ�ṹ��
		HDC hdc=BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, TEXT("hello"), strlen("HELLO"));
		EndPaint(hwnd, &ps);
		break;
	}
		
	}


	//����ֵ��Ĭ�ϴ���ʽ
	return DefWindowProc(hwnd,uMsg,wParam,lParam);
}


//�������ź���

//WINAPI ������_stdcall  �����˲����Ĵ���˳�򣬴��ҵ���������ջ�������ں�������ǰ ��ն�ջ
int WINAPI WinMain(
	HINSTANCE hInstance,  //h��������hInstance����Ӧ�ó����ʵ�����
	HINSTANCE hPrevInstance,   //��һ����Ӧ�ó���������win32������һ�㶼ΪNULL����������
	LPSTR lpCmdLine,   //char* argv[]
	int nShowCmd )     //��ʾ������ ��󻯣���С��������     
{
    //��������
	//1.��ƴ���
	//2.ע�ᴰ��
	//3.��������
	//4.��ʾ�͸���
	//5.ͨ��ѭ��ȡ��Ϣ
	//6.������Ϣ(���ڹ���)

	//1.��ƴ���
	WNDCLASS wc;
	wc.cbClsExtra = 0;   //��Ķ�����ڴ�
	wc.cbWndExtra = 0;   //���ڶ�����ڴ�
	wc.hbrBackground =(HBRUSH) GetStockObject(WHITE_BRUSH);  //���ñ���
	wc.hCursor = LoadCursor(NULL,IDC_HAND);                //���ù��,�����һ������ΪNULL������ϵͳ�ṩ�Ĺ��
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);                          //ͼ�꣬���ΪNULL����ΪϵͳĬ��
	wc.hInstance = hInstance;   //Ӧ�ó����ʵ�����������WinMain�е��βμ���
	wc.lpfnWndProc = WindowProc;           //�ص�����  ���ں���
	wc.lpszClassName = TEXT("WIN");//ָ�����ڵ�������
	wc.lpszMenuName = NULL; //�˵�����
	wc.style = 0;    //��ʾ���0����Ĭ���


	//2.ע�ᴰ��
	RegisterClass(&wc);

	//3.��������
	/*
	parameters:
	(lpClassName,  ���� 
	lpWindowName,  ������
	dwStyle,     ����WS_OVERLAPPEDWINDOW ��񣨻�Ϸ��
	x,     ��ʾ����
	y,
	nWidth,                CW_USEDEFAULT  Ĭ��ֵ
	nHeight,  ���
	hWndParent,     ������  NULL
	hMenu,           �˵�  NULL
	hInstance,    ʵ�����  hInstance
	lpParam)    ����ֵ  NULL
	*/
   	HWND hwnd=CreateWindow(wc.lpszClassName,TEXT("WINDOW"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	//4.��ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	//5.ͨ��ѭ��ȥȡ��Ϣ
	/*
	MSG:
	typedef struct tagMSG {
	HWND        hwnd;     �����ھ��
	UINT        message;    �������Ϣ����
	WPARAM      wParam;    ������Ϣ  ������Ϣ
	LPARAM      lParam;    ������Ϣ  �����Ϣ  �ж����Ҽ�
	DWORD       time;      ��Ϣ������ʱ��
	POINT       pt;        ������Ϣ  ���   x,y
	*/
	MSG msg;

	while (1)
	{
		/*
		GetMessage parameters:
		_Out_ LPMSG lpMsg,   ��Ϣ
		_In_opt_ HWND hWnd,   ���񴰿�   ��NULL���������еĴ���
		_In_ UINT wMsgFilterMin,   ��С�����Ĺ��˵���Ϣ  һ������0
		_In_ UINT wMsgFilterMax     ��0���������е���Ϣ
		*/
		if (GetMessage(&msg, NULL, 0,0)==FALSE)
		{
			break;
		}
		//������Ϣ
		TranslateMessage(&msg);
		//��Ϊfalse
		//�ַ���Ϣ
		DispatchMessage(&msg);
	}

	//6.�����ڹ���
	
	
	
	return 0;
}

