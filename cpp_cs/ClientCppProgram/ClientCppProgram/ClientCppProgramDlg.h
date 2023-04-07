
// ClientCppProgramDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CClientCppProgramDlg dialog
class CClientCppProgramDlg : public CDialogEx
{
// Construction
public:
	CClientCppProgramDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CLIENTCPPPROGRAM_DIALOG };

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
	CEdit m_txtControl;
	afx_msg void OnBnClickedButtonFillstruct();
	afx_msg void OnBnClickedButtonGetastring();
};
