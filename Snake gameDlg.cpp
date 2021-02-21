
// Snake gameDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Snake game.h"
#include "Snake gameDlg.h"
#include "afxdialogex.h"
#include <list>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSnakegameDlg dialog



CSnakegameDlg::CSnakegameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SNAKEGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSnakegameDlg::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSnakegameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSnakegameDlg::OnBnClickedButton1)
	

END_MESSAGE_MAP()


// CSnakegameDlg message handlers

BOOL CSnakegameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSnakegameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSnakegameDlg::OnPaint()
{
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSnakegameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSnakegameDlg::OnBnClickedButton1()
{
	
	CClientDC dc(this); //dc is object and this represent my screen.
	CPoint point(0, 0); //point is my veribal 
	//dc.Rectangle(point.x, point.y, point.x + 25, point.y + 15);
	//dc.Rectangle(point.x+25, point.y, point.x + 50, point.y + 15);
	int temp, temp2, colorr;
	for (int i = 0, temp2 = 0; i < 25; i++) {
		for (int j = 0, temp = 0; j < 35; j++) {
			CRect rec(point.x + temp, point.y + temp2, point.x + 16 + temp, point.y + 16 + temp2);
			dc.FillSolidRect(rec, colorr = 199999);
			temp += 16;
		}
		temp2 += 16;
	}
	startP.x = startP.y = 0;
	dc.FillSolidRect(0, 0, 16, 16, 10);
}
BOOL CSnakegameDlg::PreTranslateMessage(MSG* pMsg) {
	static double color = 20;
	CClientDC dc(this);
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == VK_UP) {
			startP.y -= 16;
		}
		if (pMsg->wParam == VK_DOWN) {
			startP.y += 16;
		}
		if (pMsg->wParam == VK_LEFT) {
			startP.x -= 16;
		}
		if (pMsg->wParam == VK_RIGHT) {
			startP.x += 16;
		}
		CRect rec(startP.x, startP.y, startP.x + 16, startP.y + 16);
		dc.FillSolidRect(rec, color+=100);
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CSnakegameDlg::OnMove() {
	




}