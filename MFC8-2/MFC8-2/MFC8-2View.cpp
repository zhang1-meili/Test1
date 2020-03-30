
// MFC8-2View.cpp : CMFC82View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC8-2.h"
#endif

#include "MFC8-2Doc.h"
#include "MFC8-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC82View

IMPLEMENT_DYNCREATE(CMFC82View, CView)

BEGIN_MESSAGE_MAP(CMFC82View, CView)
	ON_COMMAND(ID_showbitmap, &CMFC82View::Onshowbitmap)
END_MESSAGE_MAP()

// CMFC82View 构造/析构

CMFC82View::CMFC82View()
{
	// TODO: 在此处添加构造代码
	BITMAP bm;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&bm);
	m_nWidth = bm.bmWidth;
	m_nHeight = bm.bmHeight;


}

CMFC82View::~CMFC82View()
{
}

BOOL CMFC82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC82View 绘制

void CMFC82View::OnDraw(CDC* pDC)
{
	CMFC82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	//CClientDC dc(this);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC82View 诊断

#ifdef _DEBUG
void CMFC82View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC82Doc* CMFC82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC82Doc)));
	return (CMFC82Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC82View 消息处理程序


void CMFC82View::Onshowbitmap()
{
	

	// TODO: 在此添加命令处理程序代码
}
