
// pi_to_n_digitDlg.h : header file
//

#pragma once


// CpitondigitDlg dialog
class CpitondigitDlg : public CDialogEx
{
// Construction
public:
	CpitondigitDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PI_TO_N_DIGIT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:
	// Spin pointet for control min-max values
	CSpinButtonCtrl *pSpin;
	int precision; 
	CString resultText;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCalculate();
	CEdit resultWindow;
};
