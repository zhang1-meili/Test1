
// MFC8-1View.h : CMFC81View 类的接口
//

#pragma once


class CMFC81View : public CView
{
protected: // 仅从序列化创建
	CMFC81View();
	DECLARE_DYNCREATE(CMFC81View)

// 特性
public:
	CMFC81Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFC8-1View.cpp 中的调试版本
inline CMFC81Doc* CMFC81View::GetDocument() const
   { return reinterpret_cast<CMFC81Doc*>(m_pDocument); }
#endif

