
// MFC7-1View.cpp : CMFC71View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC71View ����/����

CMFC71View::CMFC71View()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC71View ����

void CMFC71View::OnDraw(CDC* pDC)
{
	CMFC71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC71View ���

#ifdef _DEBUG
void CMFC71View::AssertValid() const
{
	CView::AssertValid();
}   

void CMFC71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC71Doc* CMFC71View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC71Doc)));
	return (CMFC71Doc*)m_pDocument;
}
#endif //_DEBUG 


// CMFC71View ��Ϣ�������


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
	// TODO: �ڴ˴�Ϊ����

	// TODO: �ڴ���������������
}


void CMFC71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//int i = nIDEvent;
	//cr[i].+= 10;
	//cr[i].bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);

}
