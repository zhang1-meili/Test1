
// MFC8-2View.h : CMFC82View 类的接口
//

#pragma once


class CMFC82View : public CView
{
protected: // 仅从序列化创建
	CMFC82View();
	DECLARE_DYNCREATE(CMFC82View)

// 特性
public:
	CMFC82Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	   int m_nWidth;
	   int m_nHeight;


// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onshowbitmap();
};

#ifndef _DEBUG  // MFC8-2View.cpp 中的调试版本
inline CMFC82Doc* CMFC82View::GetDocument() const
   { return reinterpret_cast<CMFC82Doc*>(m_pDocument); }
#endif

