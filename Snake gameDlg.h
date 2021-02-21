
// Snake gameDlg.h : header file
//

#pragma once
#include <list>
using namespace std;


// CSnakegameDlg dialog
class CSnakegameDlg : public CDialogEx
{
// Construction
public:
	CSnakegameDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNAKEGAME_DIALOG };
#endif
	bool isPressed;
	CPoint startP;
	CPoint point;
	list <CPoint> snake;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT x);
	BOOL PreTranslateMessage(MSG* pMsg); // responts to kebord events;
	void OnMove();
};
