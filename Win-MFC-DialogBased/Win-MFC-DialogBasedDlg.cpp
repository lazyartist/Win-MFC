
// Win-MFC-DialogBasedDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Win-MFC-DialogBased.h"
#include "Win-MFC-DialogBasedDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

COLORREF cBgColor = RGB(255, 255, 255);


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx {
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWinMFCDialogBasedDlg 대화 상자



CWinMFCDialogBasedDlg::CWinMFCDialogBasedDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WINMFCDIALOGBASED_DIALOG, pParent)
	, szEdit(_T("")), szEdit2(_T("")), iSelectedRadio(0) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWinMFCDialogBasedDlg::DoDataExchange(CDataExchange* pDX) {
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, szEdit);
	DDV_MaxChars(pDX, szEdit, 50);
	DDX_Control(pDX, IDC_BUTTON1, hBtnCopy);
	DDX_Text(pDX, IDC_EDIT2, szEdit2);
	DDX_Control(pDX, IDC_CHECK1, hCheck1);
	//DDX_Control(pDX, IDC_RADIO1, iSelectedRadio);
	DDX_Radio(pDX, IDC_RADIO1, iSelectedRadio);
	DDX_Control(pDX, IDC_LIST1, hList);
	DDX_Control(pDX, IDC_SCROLLBAR5, hVScrollBar);
}

BEGIN_MESSAGE_MAP(CWinMFCDialogBasedDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CWinMFCDialogBasedDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CWinMFCDialogBasedDlg::OnBnClickedSetCheck)
	ON_BN_CLICKED(IDC_BUTTON3, &CWinMFCDialogBasedDlg::OnBnClickedGetCheck)
	ON_BN_CLICKED(IDC_BUTTON4, &CWinMFCDialogBasedDlg::OnBnClickedRadio)
	ON_LBN_SELCHANGE(IDC_LIST1, &CWinMFCDialogBasedDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON5, &CWinMFCDialogBasedDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CWinMFCDialogBasedDlg::OnBnClickedButton6)
	//	ON_WM_HSCROLL()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON7, &CWinMFCDialogBasedDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CWinMFCDialogBasedDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CWinMFCDialogBasedDlg 메시지 처리기

BOOL CWinMFCDialogBasedDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr) {
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SetDlgItemText(IDC_STATIC, "hihi");

	//스크롤바 최소,최대값 지정
	//hVScrollBar.SetScrollRange(0, 100);
	//스크롤바 정보 한번에 설정
	SCROLLINFO sScrollInfo;
	sScrollInfo.cbSize = sizeof(sScrollInfo);
	sScrollInfo.fMask = SIF_ALL;
	sScrollInfo.nMin = 0;
	sScrollInfo.nMax = 100;
	sScrollInfo.nPage = 10;
	sScrollInfo.nTrackPos = 0;
	sScrollInfo.nPos = 50;
	hVScrollBar.SetScrollInfo(&sScrollInfo);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CWinMFCDialogBasedDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else {
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
void CWinMFCDialogBasedDlg::OnPaint() {
	if (IsIconic()) {
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else {
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
		CRect rect;
		GetClientRect(&rect);
		dc.FillSolidRect(rect, cBgColor);

		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CWinMFCDialogBasedDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}
void CWinMFCDialogBasedDlg::OnBnClickedButton1() {
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);//컨트롤의 값을 변수로 전송
	szEdit2 = szEdit;
	UpdateData(false);//변수의 값을 컨트롤로 전송
	TRACE("%s, %s", szEdit, szEdit2);
	//MessageBox(szEdit, "hihi");
	//UpdateData(false);
}
void CWinMFCDialogBasedDlg::OnBnClickedSetCheck() {
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	hCheck1.SetCheck(BST_CHECKED);
	//hCheck1.SetCheck(BST_UNCHECKED);
}
void CWinMFCDialogBasedDlg::OnBnClickedGetCheck() {
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (hCheck1.GetCheck() == BST_CHECKED) {
		MessageBox("hi", "");
	}
}
void CWinMFCDialogBasedDlg::OnBnClickedRadio() {
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	//char sz[10] = {};
	//sprintf_s(sz, );
	TRACE("%d\n", iSelectedRadio);
}
void CWinMFCDialogBasedDlg::OnLbnSelchangeList1() {
}
void CWinMFCDialogBasedDlg::OnBnClickedButton5() {
	hList.AddString("hi");
}
void CWinMFCDialogBasedDlg::OnBnClickedButton6() {
	hList.DeleteString(hList.GetCurSel());
}
void CWinMFCDialogBasedDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
void CWinMFCDialogBasedDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar == &hVScrollBar) {
		SCROLLINFO sScrollInfo;
		pScrollBar->GetScrollInfo(&sScrollInfo);
		switch (nSBCode) {
		case SB_PAGEUP:
		{
			sScrollInfo.nPos -= sScrollInfo.nPage;
			break;
		}
		case SB_PAGEDOWN:
		{
			sScrollInfo.nPos += sScrollInfo.nPage;
			break;
		}
		case SB_LINEUP://화살표클릭
		{
			sScrollInfo.nPos -= sScrollInfo.nPage/10;
			break;
		}
		case SB_LINEDOWN://화살표클릭
		{
			sScrollInfo.nPos += sScrollInfo.nPage/10;
			break;
		}
		case SB_THUMBPOSITION://트랙 움직이고 나서
		case SB_THUMBTRACK://트랙 움직이는 동안
		{
			sScrollInfo.nPos = sScrollInfo.nTrackPos;
			break;
		}
		default:
			break;
		}
		hVScrollBar.SetScrollPos(sScrollInfo.nPos);
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}
void CWinMFCDialogBasedDlg::OnBnClickedButton7() {
	CColorDialog cColorDialog;
	if (cColorDialog.DoModal() == IDOK) {
		cBgColor = cColorDialog.GetColor();
		CString str;
		str.Format("%u", cBgColor);
		Invalidate();
		//AfxMessageBox(str);
	}
}

void CWinMFCDialogBasedDlg::OnBnClickedButton8() {
	CFileDialog cFileDialog(true/*true:open, false:save*/, nullptr,  nullptr, OFN_HIDEREADONLY, "filetype1|*.*|filetype2|*.exe|");
	if (cFileDialog.DoModal() == IDOK) {
		CString str;
		str.Format("%s, %s, %s, %s\n", cFileDialog.GetFileName(), cFileDialog.GetFileTitle(), cFileDialog.GetFileExt(), cFileDialog.GetFolderPath());
		TRACE(str);

		CStdioFile cStdioFile;
		if (cStdioFile.Open(cFileDialog.GetPathName(), CFile::modeRead | CFile::typeText)) {
			cStdioFile.ReadString(str);
			TRACE("%s\n", str);
			cStdioFile.Close();
		}
	}
}
