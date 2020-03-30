
// MFC6-2View.cpp : CMFC62View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6-2.h"
#endif

#include "MFC6-2Doc.h"
#include "MFC6-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC62View

IMPLEMENT_DYNCREATE(CMFC62View, CView)

BEGIN_MESSAGE_MAP(CMFC62View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC62View 构造/析构

CMFC62View::CMFC62View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
	}
}

CMFC62View::~CMFC62View()
{
}

BOOL CMFC62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC62View 绘制

void CMFC62View::OnDraw(CDC* pDC)
{
	CMFC62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set) {
		for (int i = 0; i < N; i++) {
			SetTimer(i, rand() % 400 + 100, NULL);
			set = false;
		}

	}
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC62View 诊断

#ifdef _DEBUG
void CMFC62View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC62Doc* CMFC62View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC62Doc)));
	return (CMFC62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC62View 消息处理程序


void CMFC62View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	cr[i].top += 10;
	cr[i].bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
