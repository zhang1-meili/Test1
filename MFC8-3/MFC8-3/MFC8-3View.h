
// MFC8-3View.h : CMFC83View 类的接口
//

#pragma once


class CMFC83View : public CView
{
protected: // 仅从序列化创建
	CMFC83View();
	DECLARE_DYNCREATE(CMFC83View)

// 特性
public:
	CMFC83Doc* GetDocument() const;

// 操作
public:
	CPoint m_pt;
	UINT m_nd;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC83View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onzhixian();
	afx_msg void Onjuxing();
	afx_msg void Ontuoyuan();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC8-3View.cpp 中的调试版本
inline CMFC83Doc* CMFC83View::GetDocument() const
   { return reinterpret_cast<CMFC83Doc*>(m_pDocument); }
#endif

