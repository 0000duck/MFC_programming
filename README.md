# MFC_programming
Learn to program MFC

> blog:[MFC notes](http://chanchan.me/2018/03/14/mfc/)

## 底层实现以窗口

- sdk api 句柄
- 消息处理机制
- 头文件 windows.h
- 程序入口　winMain

## 具体步骤
1. 设计窗口 WNDCLASS wc
2. 注册窗口 RegisterClass
3. 创建窗口 createWindow
4. 显示和更新 showWindow updataWindow
5. 通过循环取消息 MSG msg
- 写循环while(1)
- GetMessage==false 退出循环
- 翻译消息
- 分发消息
6. 窗口过程
- LRESULT CALLBACK WindowsProc
- 返回默认处理
- return DefWindowProc(hwnd,uMsg,wParam,lParam)
- 点击叉子 WM_CLOSE destroy
- WM_DESTROY postQuitMessage(0)
- 鼠标左键按下
- 键盘按下
- 绘图 文字

## 利用mfc创建创窗口

1. mfc头文件 afxwin.h
2. 自定义类 继承与 cwinApp 应用程序类 MyApp app 应用程序对象，有且仅有一个
3. InitINstance
4. 入口里 创建窗口
5. 窗口类 MyFrame 继承于CFrmaeWnd
6. MyFrame 构造中 Create(NULL,标题名)
7. 创建窗口对象
8. 显示和更新   
9. m_pMainWnd=frame   //保存指向应用程序的主窗口的指针
10. return TRUE
11. 对项目进行配置 （在dll中共享MFC ）


## 消息映射机制
1. 声明宏  写到.h中
2. 分界宏 写到.cpp
3. 找消息宏  写到分界宏 中间
4. 把函数原型声明写到.h中
5. 函数的实现写到.cpp中
6. 鼠标，键盘，绘图

## window 字符集
1. 多字节 字符串 转宽字节 L
2. 声明宽字节字符 wchar_t
3. 统计宽字节字符串 wcslen
4. TEXT做了自适应编码转换
5. char* CString

## 利用向导创建mfc
1. view 视类 类似相片 MainFrame类 类似相框
2. OnCreate Create WM_Create 联系
3. OnPaint 覆盖 OnPaint

## 基于对话框学习控件
1. 对话框 模态非模态
2. 按钮 两个
- caption 修改内容  
- 直接输入内容
3. 点击触发事件  
- 右侧属性 闪电图标
- 右键按钮，添加事件处理程序
- 双击按钮
4. 插入窗口 窗口 右键 添加类
5. 模态窗口创建 CDlgExec dlg
- dlg.DoModal()
6. 非模态创建
- CDlgShow dlg 写到.h 做成员
- dlg.Create 写到初始化oninitDialog 保证创建一次
- dlg.showWindow()

tips:
1. 在资源视图之中去找dialog
2. ctrl+a 全选 delete  删除默认控件

## CStaticText 静态文本
1. 添加变量  以STATIC为结尾的ID是不可添加变量的，要改
2. 设置内容setWindowTextW
3. 获取内容 getWindowTextW
4. 利用静态文本显示图片
- bmp图片
5. 如何禁用按钮

## 编辑框的使用
1. EditCtrl属性
- multiline多行
- want return
- 滚动条 无限横向纵向的输入
2. getWindowText setWindowText设置和获取值
3. 默认小bug 单行点回车就退出
- 重写OnOk 注释掉里面的代码
4. 退出当前对话框
- CDialog::OnOk() OnCancel()
5. 添加变量的时候  选择value
6. 本身关联的变量，就是那个值
7. UpdateData(True)
- 将控件的内容 同步到变量


---

## DoDataExchage()绑定变量

``DDX_Control(pDX,IDC_EDIT1,m_edit1);``

``DDX_Text(pDX,IDC_EDIT3,m_text);``

---

## 下拉框iam CCombox
1. 属性中加入数据data   ;进行分割
2. 默认排序 sort 修改false 不排序了
3. type类型 DropList不可以编辑
4. 添加AddString
5. 删除 DeleteString
6. 插入 InsertString
7. 设置默认选项 setCurSel
8. 获取当前索引 getCurSel
9. 根据索引获取内容 getLBText(索引，CString str)
10. 控件事件 OnCbnSelchangeCombol

## ListControl 列表控件
1. view 报表模式 report
2. 添加表头 InsertCol
3. 添加正文 从0索引
4. 添加第一行第一列 InsertItem(0,"chanchan");
5. 添加第一行其他列 setItemText(行，列，具体内容)
6. 设置风格 整行选中 网格显示

## CTreeCtrl 树控件

1. 设置属性 设置线，按钮
2. 设置图片集合
- setImageList(CImageList* list,正常显示的宏)
- list 准备 create(30,30,32位色,4,4)
- add(HICON)
3. 添加节点
- InsertItem(节点名称) 显示图片 选中后现实的图片
4. 设置默认节点
- selectItem  
5. 节点间切换触发事件 OnTvnSelchangedTree1
- 获取当前项 item=getSelectItem
- CString str=getItemText(item)

>reference: [黑马程序员](http://www.itheima.com/)

[B站视频](https://www.bilibili.com/video/av20005978?from=search&seid=6434021606735753697)

