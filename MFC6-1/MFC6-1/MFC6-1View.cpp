
// MFC6-1View.cpp : CMFC61View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6-1.h"
#endif

#include "MFC6-1Doc.h"
#include "MFC6-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC61View

IMPLEMENT_DYNCREATE(CMFC61View, CView)

BEGIN_MESSAGE_MAP(CMFC61View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC61View 构造/析构

CMFC61View::CMFC61View()
{
	// TODO: 在此处添加构造代码

}

CMFC61View::~CMFC61View()
{
}

BOOL CMFC61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC61View 绘制

void CMFC61View::OnDraw(CDC* /*pDC*/)
{
	CMFC61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC61View 诊断

#ifdef _DEBUG
void CMFC61View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC61Doc* CMFC61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC61Doc)));
	return (CMFC61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC61View 消息处理程序


void CMFC61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}


void CMFC61View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
}


void CMFC61View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
}
