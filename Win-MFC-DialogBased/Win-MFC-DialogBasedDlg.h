
// Win-MFC-DialogBasedDlg.h: 헤더 파일
//

#pragma once


// CWinMFCDialogBasedDlg 대화 상자
class CWinMFCDialogBasedDlg : public CDialogEx
{
// 생성입니다.
public:
	CWinMFCDialogBasedDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINMFCDIALOGBASED_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString szEdit;
	CButton hBtnCopy;
	afx_msg void OnBnClickedButton1();
	CString szEdit2;
	afx_msg void OnBnClickedSetCheck();
	CButton hCheck1;
	afx_msg void OnBnClickedGetCheck();
	afx_msg void OnBnClickedRadio();
	int iSelectedRadio;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton5();
	CListBox hList;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnThemechangedScrollbar4(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar hVScrollBar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
