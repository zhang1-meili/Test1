
// MFC5View.cpp : CMFC5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5.h"
#endif

#include "MFC5Doc.h"
#include "MFC5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5View

IMPLEMENT_DYNCREATE(CMFC5View, CView)

BEGIN_MESSAGE_MAP(CMFC5View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC5View 构造/析构

CMFC5View::CMFC5View()
{
	// TODO: 在此处添加构造代码

}

CMFC5View::~CMFC5View()
{
}

BOOL CMFC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC5View 绘制

void CMFC5View::OnDraw(CDC* pDC)
{
	CMFC5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CRect c1(400, 400, 500, 500);
	CRect c2(500, 500, 600, 600);
	CRect c3(300, 300, 400, 400);
	pDC->Rectangle(&c1);
	pDC->Rectangle(&c2);
	pDC->Rectangle(&c3);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC5View 诊断

#ifdef _DEBUG
void CMFC5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5Doc* CMFC5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5Doc)));
	return (CMFC5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5View 消息处理程序


void CMFC5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	
	int t = rand() % 100;
	CString s;
	s.Format(_T("%d"), t);
	CString ss;
	ss.Format(_T("%d"),a+b);
	if (point.x > 400 && point.x < 500 && point.y>400 && point.y < 500)
	{
		dc.TextOutW(point.x, point.y, s);
		a = t;
	}
	else if (point.x > 500 && point.x < 600 && point.y>500 && point.y < 600)
	{
		dc.TextOutW(point.x, point.y, s);
		b = t;
	}
	else if (point.x > 300 && point.x < 400 && point.y>300 && point.y <400)
		dc.TextOutW(point.x, point.y, ss);
	else 
	{ 
		CString s1; 
		s1.Format(_T("无效"));
		dc.TextOutW(point.x, point.y, s1);
	}
	CView::OnLButtonDown(nFlags, point);
	
}
