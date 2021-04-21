
// pi_to_n_digitDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "pi_to_n_digit.h"
#include "pi_to_n_digitDlg.h"
#include "afxdialogex.h"
#include "piCalc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//macro for CString.Format() 
#define macro .precision

// CpitondigitDlg dialog
CpitondigitDlg::CpitondigitDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PI_TO_N_DIGIT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CpitondigitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, resultWindow);
}

BEGIN_MESSAGE_MAP(CpitondigitDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CpitondigitDlg::OnBnClickedButtonCalculate)
END_MESSAGE_MAP()


// CpitondigitDlg message handlers

BOOL CpitondigitDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	pSpin = static_cast<CSpinButtonCtrl*>(GetDlgItem(IDC_SPIN1));
	pSpin->SetRange(0, 15);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CpitondigitDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CpitondigitDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CpitondigitDlg::OnBnClickedButtonCalculate()
{
	precision = pSpin->GetPos();
	//precision specifier 17 becouse max precision 15 plus 2 chars (3.)
	resultText.Format(_T("%.17F"), piCalc(precision));
	//Use Left method for precision control
	resultWindow.SetWindowTextW(resultText.Left(2+precision));

}
