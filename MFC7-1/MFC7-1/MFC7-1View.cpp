
// MFC7-1View.cpp : CMFC71View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7-1.h"
#endif

#include "MFC7-1Doc.h"
#include "MFC7-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC71View

IMPLEMENT_DYNCREATE(CMFC71View, CView)

BEGIN_MESSAGE_MAP(CMFC71View, CView)
	ON_COMMAND(ID_showYuan, &CMFC71View::Onshowyuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC71View 构造/析构

CMFC71View::CMFC71View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(300,300, t + 100, t+100);
		cr.Add(rect);
	}


}

CMFC71View::~CMFC71View()
{
}

BOOL CMFC71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC71View 绘制

void CMFC71View::OnDraw(CDC* pDC)
{
	CMFC71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC71View 诊断

#ifdef _DEBUG
void CMFC71View::AssertValid() const
{
	CView::AssertValid();
}   

void CMFC71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC71Doc* CMFC71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC71Doc)));
	return (CMFC71Doc*)m_pDocument;
}
#endif //_DEBUG 


// CMFC71View 消息处理程序


void CMFC71View::Onshowyuan()
{
	//CRect cr(300, 300, 400, 400);
	
	if (set) {
		for (int i = 0; i < N; i++) {
			SetTimer(i, rand() % 400 + 100, NULL);
			set = false;
		}

	}
	for (int i = 0; i < N; i++)
	{
		CClientDC dc(this);
		dc.Ellipse(cr[i]);
	}
	// TODO: 在此处为本机

	// TODO: 在此添加命令处理程序代码
}


void CMFC71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//int i = nIDEvent;
	//cr[i].+= 10;
	//cr[i].bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);

}
