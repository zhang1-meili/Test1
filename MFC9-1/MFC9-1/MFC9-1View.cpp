
// MFC9-1View.cpp : CMFC91View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC9-1.h"
#endif

#include "MFC9-1Doc.h"
#include "MFC9-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC91View

IMPLEMENT_DYNCREATE(CMFC91View, CView)

BEGIN_MESSAGE_MAP(CMFC91View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMFC91View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC91View 构造/析构

CMFC91View::CMFC91View()
{
	// TODO: 在此处添加构造代码

}

CMFC91View::~CMFC91View()
{
}

BOOL CMFC91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC91View 绘制

void CMFC91View::OnDraw(CDC* /*pDC*/)
{
	CMFC91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC91View 打印

BOOL CMFC91View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC91View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC91View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC91View 诊断

#ifdef _DEBUG
void CMFC91View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC91Doc* CMFC91View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC91Doc)));
	return (CMFC91Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC91View 消息处理程序


void CMFC91View::OnFileOpen()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r = IDOK)
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}
	// TODO: 在此添加命令处理程序代码
}
