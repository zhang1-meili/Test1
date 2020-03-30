
// MFC4View.cpp : CMFC4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4.h"
#endif

#include "MFC4Doc.h"
#include "MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4View

IMPLEMENT_DYNCREATE(CMFC4View, CView)

BEGIN_MESSAGE_MAP(CMFC4View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC4View 构造/析构

CMFC4View::CMFC4View()
{
	// TODO: 在此处添加构造代码

}

CMFC4View::~CMFC4View()
{
}

BOOL CMFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4View 绘制

void CMFC4View::OnDraw(CDC* pDC)
{
	CMFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// CMFC4View 诊断

#ifdef _DEBUG
void CMFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4Doc* CMFC4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4Doc)));
	return (CMFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4View 消息处理程序


void CMFC4View::OnLButtonDown(UINT nFlags, CPoint point)
{ 
	CClientDC dc(this);
	CString S;
	S.Format(_T("左键正被按下"));
	dc.TextOutW(200, 500, S);


	CView::OnLButtonDown(nFlags, point);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
}


void CMFC4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CClientDC dc(this);
	CString S;
	S.Format(_T("左键正在弹起"));
	dc.TextOutW(500, 500, S);

	CView::OnLButtonUp(nFlags, point);
}
