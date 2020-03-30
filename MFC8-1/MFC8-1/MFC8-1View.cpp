
// MFC8-1View.cpp : CMFC81View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC8-1.h"
#endif

#include "MFC8-1Doc.h"
#include "MFC8-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC81View

IMPLEMENT_DYNCREATE(CMFC81View, CView)

BEGIN_MESSAGE_MAP(CMFC81View, CView)
	ON_COMMAND(ID_SHOWNAME, &CMFC81View::OnShowname)
END_MESSAGE_MAP()

// CMFC81View 构造/析构

CMFC81View::CMFC81View()
{
	// TODO: 在此处添加构造代码

}

CMFC81View::~CMFC81View()
{
}

BOOL CMFC81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC81View 绘制

void CMFC81View::OnDraw(CDC* /*pDC*/)
{
	CMFC81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC81View 诊断

#ifdef _DEBUG
void CMFC81View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC81Doc* CMFC81View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC81Doc)));
	return (CMFC81Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC81View 消息处理程序


void CMFC81View::OnShowname()
{
	CString s = _T("张思敏");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);
	// TODO: 在此添加命令处理程序代码

}