
// MFC6View.cpp : CMFC6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6.h"
#endif

#include "MFC6Doc.h"
#include "MFC6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC6View

IMPLEMENT_DYNCREATE(CMFC6View, CView)

BEGIN_MESSAGE_MAP(CMFC6View, CView)
END_MESSAGE_MAP()

// CMFC6View 构造/析构

CMFC6View::CMFC6View()
{
	// TODO: 在此处添加构造代码

}

CMFC6View::~CMFC6View()
{
}

BOOL CMFC6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC6View 绘制

void CMFC6View::OnDraw(CDC* pDC)
{
	CMFC6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString S;
	S.Format(_T("我是张思敏"));
	pDC->TextOutW(100, 200, S);
	int A = 20;
	CString s;
	s.Format(_T("%d"), A);
	pDC->TextOutW(100, 300, s);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC6View 诊断

#ifdef _DEBUG
void CMFC6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC6Doc* CMFC6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC6Doc)));
	return (CMFC6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC6View 消息处理程序
