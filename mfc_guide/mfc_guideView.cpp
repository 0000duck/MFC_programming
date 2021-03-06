
// mfc_guideView.cpp: CmfcguideView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mfc_guide.h"
#endif

#include "mfc_guideDoc.h"
#include "mfc_guideView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcguideView

IMPLEMENT_DYNCREATE(CmfcguideView, CView)

BEGIN_MESSAGE_MAP(CmfcguideView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CmfcguideView 构造/析构

CmfcguideView::CmfcguideView()
{
	// TODO: 在此处添加构造代码

}

CmfcguideView::~CmfcguideView()
{
}

BOOL CmfcguideView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmfcguideView 绘图

void CmfcguideView::OnDraw(CDC* pDC)
{
	CmfcguideDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(100, 100, TEXT("瓜皮"));
	// TODO: 在此处为本机数据添加绘制代码
}


// CmfcguideView 打印

BOOL CmfcguideView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmfcguideView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmfcguideView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CmfcguideView 诊断

#ifdef _DEBUG
void CmfcguideView::AssertValid() const
{
	CView::AssertValid();
}

void CmfcguideView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfcguideDoc* CmfcguideView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcguideDoc)));
	return (CmfcguideDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfcguideView 消息处理程序


void CmfcguideView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	CString str;
	str.Format(TEXT("X=%d,y=%d"), point.x, point.y);
	MessageBox(str);
}

//如果有了 OnDraw 就不要有OnPaint 同时存在的话，后者将前者覆盖
void CmfcguideView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CView::OnPaint()

	dc.TextOutW(100, 100, TEXT("1111"));
}
