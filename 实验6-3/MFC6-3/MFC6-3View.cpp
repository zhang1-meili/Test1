
// MFC6-3View.cpp : CMFC63View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6-3.h"
#endif

#include "MFC6-3Doc.h"
#include "MFC6-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC63View

IMPLEMENT_DYNCREATE(CMFC63View, CView)

BEGIN_MESSAGE_MAP(CMFC63View, CView)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC63View 构造/析构

CMFC63View::CMFC63View()
{
	// TODO: 在此处添加构造代码

}

CMFC63View::~CMFC63View()
{
}

BOOL CMFC63View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC63View 绘制

void CMFC63View::OnDraw(CDC* pDC)
{
	CMFC63Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->m_tagRect);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC63View 诊断

#ifdef _DEBUG
void CMFC63View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC63View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC63Doc* CMFC63View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC63Doc)));
	return (CMFC63Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC63View 消息处理程序


void CMFC63View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC63Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_tagRect.left > 0) {
			pDoc->m_tagRect.left -= 5;
			pDoc->m_tagRect.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_tagRect.right <=(clientRec.right- clientRec.left) ){
			pDoc->m_tagRect.left += 5;
			pDoc->m_tagRect.right += 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_tagRect.bottom > 0) {
			pDoc->m_tagRect.top+= 5;
			pDoc->m_tagRect.bottom+= 5;
		}break;
	case VK_UP:
		if (pDoc->m_tagRect.top > 0) {
			pDoc->m_tagRect.top -= 5;
			pDoc->m_tagRect.bottom -= 5;
		}break;
	}
	

	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC63View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC63Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case 'L':
		if (pDoc->m_tagRect.top > 0) {
			pDoc->m_tagRect.top -= 10;
			pDoc->m_tagRect.left -=10;
			pDoc->m_tagRect.right = 350;
			pDoc->m_tagRect.bottom = 300;
		}
		break;
	case 'R':
		if (pDoc->m_tagRect.bottom > 0) {
			pDoc->m_tagRect.left = 30;
			pDoc->m_tagRect.top = 30;
			pDoc->m_tagRect.right -= 20;
			pDoc->m_tagRect.bottom -= 20;
		}
		break;
		CView::OnChar(nChar, nRepCnt, nFlags);
	}
}

	void CMFC63View::OnLButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: 在此添加消息处理程序代码和/或调用默认值
		CMFC63Doc* pDoc = GetDocument();
		pDoc->m_tagRect.left = 30;
		pDoc->m_tagRect.top = 30;
		pDoc->m_tagRect.right = 350;
		pDoc->m_tagRect.bottom = 300;
		CView::OnLButtonDown(nFlags, point);
	}
