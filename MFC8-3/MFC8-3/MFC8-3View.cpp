
// MFC8-3View.cpp : CMFC83View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC8-3.h"
#endif

#include "MFC8-3Doc.h"
#include "MFC8-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC83View

IMPLEMENT_DYNCREATE(CMFC83View, CView)

BEGIN_MESSAGE_MAP(CMFC83View, CView)
	ON_COMMAND(ID_zhixian, &CMFC83View::Onzhixian)
	ON_COMMAND(ID_juxing, &CMFC83View::Onjuxing)
	ON_COMMAND(ID_tuoyuan, &CMFC83View::Ontuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC83View 构造/析构

CMFC83View::CMFC83View()
{
	// TODO: 在此处添加构造代码
	m_nd = 0;
	m_pt = 0;
}

CMFC83View::~CMFC83View()
{
}

BOOL CMFC83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC83View 绘制

void CMFC83View::OnDraw(CDC* /*pDC*/)
{
	CMFC83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC83View 诊断

#ifdef _DEBUG
void CMFC83View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC83Doc* CMFC83View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC83Doc)));
	return (CMFC83Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC83View 消息处理程序


void CMFC83View::Onzhixian()
{
	m_nd = 1;
	// TODO: 在此添加命令处理程序代码
}


void CMFC83View::Onjuxing()
{
	m_nd = 2;
	// TODO: 在此添加命令处理程序代码
}


void CMFC83View::Ontuoyuan()
{
	m_nd = 3;
	// TODO: 在此添加命令处理程序代码
}


void CMFC83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pt = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC83View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	switch (m_nd)
	{case 1:
		dc.MoveTo(m_pt);
		dc.LineTo(point);
		break;
	case 2:
		dc.Rectangle(CRect(m_pt, point));
		break;
	case 3:
		dc.Ellipse(CRect(m_pt, point));
		break;
	default:
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}
