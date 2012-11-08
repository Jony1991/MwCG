// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// MwCGView.h : interface of the CMwCGView class
//

#pragma once
#include "MwGLRenderer.h"
#include "MainFrm.h"

using namespace mw;

class CMwCGView : public CView
{
protected: // create from serialization only
	CMwCGView();
	DECLARE_DYNCREATE(CMwCGView)

// Attributes
public:
	CMwCGDoc* GetDocument() const;
protected:
	GlRenderer m_render;
	HDC m_hDC;
	CPoint m_ptMouse;
	Vector2 mouse_xy_, mouse_down_xy_;
	int zoom_level_;
	bool m_bMouseDown;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMwCGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnUpdateClearColor(CCmdUI *pCmdUI);
	virtual void OnInitialUpdate();
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
//	afx_msg void OnCanvasHeight();
//	afx_msg void OnCanvasWidth();
//	afx_msg void OnCanvasHeight();
	afx_msg void OnUpdateCanvasWidth(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCanvasHeight(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeGallery(CCmdUI *pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnUpdateIdsStatusPos(CCmdUI *pCmdUI);
	afx_msg void OnUpdateIdsStatusZoom(CCmdUI *pCmdUI);
//	afx_msg void OnIdsStatusZoomSlider();
	afx_msg void OnUpdateIdsStatusZoomSlider(CCmdUI *pCmdUI);
	afx_msg void OnIdsStatusZoomSlider();
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MwCGView.cpp
inline CMwCGDoc* CMwCGView::GetDocument() const
   { return reinterpret_cast<CMwCGDoc*>(m_pDocument); }
#endif

