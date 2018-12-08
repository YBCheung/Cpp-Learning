#include "stdafx.h"  
#include "Draw.h"  
  
#include "DrawDoc.h"  
#include "DrawView.h"  
  
#ifdef _DEBUG  
#define new DEBUG_NEW  
#undef THIS_FILE  
static char THIS_FILE[] = __FILE__;  
#endif  
  
/////////////////////////////////////////////////////////////////////////////  
// CDrawView  
  
IMPLEMENT_DYNCREATE(CDrawView, CView)  
  
BEGIN_MESSAGE_MAP(CDrawView, CView)  
    //{{AFX_MSG_MAP(CDrawView)  
    ON_WM_LBUTTONDOWN()  
    ON_WM_LBUTTONUP()  
    //}}AFX_MSG_MAP  
    // Standard printing commands  
    ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)  
    ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)  
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)  
END_MESSAGE_MAP()  
  
/////////////////////////////////////////////////////////////////////////////  
// CDrawView construction/destruction  
  
CDrawView::CDrawView()  
{  
    // TODO: add construction code here  
m_ptOrigin=0;  
}  
  
CDrawView::~CDrawView()  
{  
}  
  
BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)  
{  
    // TODO: Modify the Window class or styles here by modifying  
    //  the CREATESTRUCT cs  
  
    return CView::PreCreateWindow(cs);  
}  
  
/////////////////////////////////////////////////////////////////////////////  
// CDrawView drawing  
  
void CDrawView::OnDraw(CDC* pDC)  
{  
    CDrawDoc* pDoc = GetDocument();  
    ASSERT_VALID(pDoc);  
    // TODO: add draw code for native data here  
}  
  
/////////////////////////////////////////////////////////////////////////////  
// CDrawView printing  
  
BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)  
{  
    // default preparation  
    return DoPreparePrinting(pInfo);  
}  
  
void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)  
{  
    // TODO: add extra initialization before printing  
}  
  
void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)  
{  
    // TODO: add cleanup after printing  
}  
  
/////////////////////////////////////////////////////////////////////////////  
// CDrawView diagnostics  
  
#ifdef _DEBUG  
void CDrawView::AssertValid() const  
{  
    CView::AssertValid();  
}  
  
void CDrawView::Dump(CDumpContext& dc) const  
{  
    CView::Dump(dc);  
}  
  
CDrawDoc* CDrawView::GetDocument() // non-debug version is inline  
{  
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));  
    return (CDrawDoc*)m_pDocument;  
}  
#endif //_DEBUG  
  
/////////////////////////////////////////////////////////////////////////////  
// CDrawView message handlers  
  
//DEL void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)   
//DEL {  
//DEL   // TODO: Add your message handler code here and/or call default  
//DEL   MessageBox("view clicked");  
//DEL   CView::OnLButtonDown(nFlags, point);  
//DEL }  
  
void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)   
{  
    // TODO: Add your message handler code here and/or call default  
//  MessageBox("view clicked");  
    m_ptOrigin=point;  
    CView::OnLButtonDown(nFlags, point);  
}  
  
void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)   
{  
    // TODO: Add your message handler code here and/or call default  
  
    /* »­Í¼ */  
    /*  
    HDC hdc; 
    hdc=::GetDC(m_hWnd); 
    MoveToEx(hdc,m_ptOrigin.x,m_ptOrigin.y,NULL); 
    LineTo(hdc,point.x,point.y); 
    ::ReleaseDC(m_hWnd,hdc); 
    */  
    /* 
    CDC *pDC=GetDC(); 
    pDC->MoveTo(m_ptOrigin); 
    pDC->LineTo(point); 
    ReleaseDC(pDC); 
    */  
  
    //CClientDC dc(this);  
  
    /*CClientDC dc(GetParent()); 
 
    dc.MoveTo(m_ptOrigin); 
    dc.LineTo(point); 
    */  
  
    //  CWindowDC dc(GetParent());  
    /*   
    CWindowDC dc(GetDesktopWindow()); 
    dc.MoveTo(m_ptOrigin); 
    dc.LineTo(point); 
    */  
  
    /*ÑÕÉ«ÏßÌõ*/  
    /* 
    CPen pen(PS_DASH,1,RGB(255,0,0)); 
    CClientDC dc(this); 
    CPen *pOldPen=dc.SelectObject(&pen); 
    dc.MoveTo(m_ptOrigin); 
    dc.LineTo(point); 
    */  
    CBrush brush(RGB(255,0,0));  
    CClientDC dc(this);  
    dc.FillRect(CRect(m_ptOrigin,point),&brush);  
  
    CView::OnLButtonUp(nFlags, point);  
}  
