#include<Windows.h>  //底层实现窗口的头文件

//6.处理窗口程序  
//CALLBACK  代表了_stdcall  代表了参数的传递顺序，从右到左依次入栈，并且在函数返回前 清空堆栈
LRESULT CALLBACK WindowProc(
	HWND hwnd,  //消息所属的窗口句柄
	UINT uMsg,    //具体的消息名称     WM_XXXX消息名称
	WPARAM wParam,  //键盘附加消息
	LPARAM lParam    //鼠标附加消息
)
{
	//所有以xxxWindow为结尾的方法，都不会进入消息队列中，而是直接执行
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);  //发送另一个消息 WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:   //鼠标左键按下
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);

		char buf[1024];
		wsprintf(buf,TEXT("x=%d,y=%d"), xPos, yPos);
		MessageBox(hwnd,buf, TEXT("瓜皮"), MB_OK);
		break;
	}
	case WM_KEYDOWN:  //键盘
		MessageBox(hwnd, TEXT("hello"), TEXT("world"), MB_OK);
		break;

	case WM_PAINT:    //绘图
	{
		PAINTSTRUCT ps;  //绘图结构体
		HDC hdc=BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, TEXT("hello"), strlen("HELLO"));
		EndPaint(hwnd, &ps);
		break;
	}
		
	}


	//返回值用默认处理方式
	return DefWindowProc(hwnd,uMsg,wParam,lParam);
}


//程序入门函数

//WINAPI 代表了_stdcall  代表了参数的传递顺序，从右到左依次入栈，并且在函数返回前 清空堆栈
int WINAPI WinMain(
	HINSTANCE hInstance,  //h代表句柄，hInstance代表应用程序的实例句柄
	HINSTANCE hPrevInstance,   //上一个的应用程序句柄，在win32环境下一般都为NULL，不起作用
	LPSTR lpCmdLine,   //char* argv[]
	int nShowCmd )     //显示的命令 最大化，最小化，正常     
{
    //创建窗口
	//1.设计窗口
	//2.注册窗口
	//3.创建窗口
	//4.显示和更新
	//5.通过循环取消息
	//6.处理消息(窗口过程)

	//1.设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0;   //类的额外的内存
	wc.cbWndExtra = 0;   //窗口额外的内存
	wc.hbrBackground =(HBRUSH) GetStockObject(WHITE_BRUSH);  //设置背景
	wc.hCursor = LoadCursor(NULL,IDC_HAND);                //设置光标,如果第一个参数为NULL，代表系统提供的光标
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);                          //图标，如果为NULL，即为系统默认
	wc.hInstance = hInstance;   //应用程序的实例句柄，传入WinMain中的形参即可
	wc.lpfnWndProc = WindowProc;           //回调函数  窗口函数
	wc.lpszClassName = TEXT("WIN");//指定窗口的类名称
	wc.lpszMenuName = NULL; //菜单名称
	wc.style = 0;    //显示风格，0代表默风格


	//2.注册窗口
	RegisterClass(&wc);

	//3.创建窗口
	/*
	parameters:
	(lpClassName,  类名 
	lpWindowName,  标题名
	dwStyle,     常用WS_OVERLAPPEDWINDOW 风格（混合风格）
	x,     显示坐标
	y,
	nWidth,                CW_USEDEFAULT  默认值
	nHeight,  宽高
	hWndParent,     父窗口  NULL
	hMenu,           菜单  NULL
	hInstance,    实例句柄  hInstance
	lpParam)    附加值  NULL
	*/
   	HWND hwnd=CreateWindow(wc.lpszClassName,TEXT("WINDOW"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	//4.显示和更新
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	//5.通过循环去取消息
	/*
	MSG:
	typedef struct tagMSG {
	HWND        hwnd;     主窗口句柄
	UINT        message;    具体的消息名称
	WPARAM      wParam;    附加消息  键盘消息
	LPARAM      lParam;    附加消息  鼠标消息  判断左右键
	DWORD       time;      消息产生的时间
	POINT       pt;        附加消息  鼠标   x,y
	*/
	MSG msg;

	while (1)
	{
		/*
		GetMessage parameters:
		_Out_ LPMSG lpMsg,   消息
		_In_opt_ HWND hWnd,   捕获窗口   填NULL代表捕获所有的窗口
		_In_ UINT wMsgFilterMin,   最小和最大的过滤的消息  一般填入0
		_In_ UINT wMsgFilterMax     填0代表捕获所有的消息
		*/
		if (GetMessage(&msg, NULL, 0,0)==FALSE)
		{
			break;
		}
		//翻译消息
		TranslateMessage(&msg);
		//不为false
		//分发消息
		DispatchMessage(&msg);
	}

	//6.处理窗口过程
	
	
	
	return 0;
}

