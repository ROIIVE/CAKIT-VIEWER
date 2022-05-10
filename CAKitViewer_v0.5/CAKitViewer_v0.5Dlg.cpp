
// CAKitViewer_v0.5Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "CAKitViewer_v0.5.h"
#include "CAKitViewer_v0.5Dlg.h"
#include "afxdialogex.h"

#include <direct.h>

int gROICENTER1 = 0;
int gROICENTER2 = 0;
int gROICENTER3 = 0;
int gROICENTER4 = 0;
int gROICT1 = 0;
int gROICT2 = 0;
int gROICT3 = 0;
int gROICT4 = 0;
int gROILT1 = 0;
int gROILT2 = 0;
int gROILT3 = 0;
int gROILT4 = 0;
int gROILB1 = 0;
int gROILB2 = 0;
int gROILB3 = 0;
int gROILB4 = 0;
int gROIRT1 = 0;
int gROIRT2 = 0;
int gROIRT3 = 0;
int gROIRT4 = 0;
int gROIRB1 = 0;
int gROIRB2 = 0;
int gROIRB3 = 0;
int gROIRB4 = 0;


int gDeviceIndex = 0;;
int gDeviceCenter = 0;
int gDeviceCT = 0;
int gDeviceLT = 0;
int gDeviceLB = 0;
int gDeviceRT = 0;
int gDeviceRB = 0;
int gDeviceGAP = 0;

int gDeviceCenter_Offset = 0;
int gDeviceCT_Offset = 0;
int gDeviceLT_Offset = 0;
int gDeviceLB_Offset = 0;
int gDeviceRT_Offset = 0;
int gDeviceRB_Offset = 0;
char gRootDir[MAX_PATH] = { 0 };

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
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

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCAKitViewerv05Dlg 대화 상자



CCAKitViewerv05Dlg::CCAKitViewerv05Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CAKITVIEWER_V05_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1); //IDR_MAINFRAME	// IDI_ICON1
}

void CCAKitViewerv05Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCAKitViewerv05Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCAKitViewerv05Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCAKitViewerv05Dlg::OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, &CCAKitViewerv05Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCAKitViewerv05Dlg 메시지 처리기

BOOL CCAKitViewerv05Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	
	SetDlgItemInt(IDC_EDIT1, 1, 1);

	bReturn = FALSE;
	bFail = FALSE;

	_getcwd(gRootDir, MAX_PATH);

	/*
	gROICENTER1 = INIReadInt("ROI_CENTER", "CENTER_1", 0);
	CString str;
	str.Format("ROICENTER_1=%d", gROICENTER1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROICENTER2 = INIReadInt("ROI_CENTER", "CENTER_2", 0);
	CString str;
	str.Format("ROICENTER_2=%d", gROICENTER2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROICENTER3 = INIReadInt("ROI_CENTER", "CENTER_3", 0);
	CString str;
	str.Format("ROICENTER_3=%d", gROICENTER3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROICENTER4 = INIReadInt("ROI_CENTER", "CENTER_4", 0);
	CString str;
	str.Format("ROICENTER_4=%d", gROICENTER4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROICT1 = INIReadInt("ROI_CT", "CT_1", 0);
	CString str;
	str.Format("ROICT_1 = %d", gROICT1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROICT2 = INIReadInt("ROI_CT", "CT_2", 0);
	CString str;
	str.Format("ROICT_2=%d", gROICT2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROICT3 = INIReadInt("ROI_CT", "CT_3", 0);
	CString str;
	str.Format("ROICT_3=%d", gROICT3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROICT4 = INIReadInt("ROI_CT", "CT_4", 0);
	CString str;
	str.Format("ROICT_4=%d", gROICT4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROILT1 = INIReadInt("ROI_LT", "LT_1", 0);
	CString str;
	str.Format("ROILT_1=%d", gROILT1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROILT2 = INIReadInt("ROI_LT", "LT_2", 0);
	CString str;
	str.Format("ROILT_2=%d", gROILT2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILT3 = INIReadInt("ROI_LT", "LT_3", 0);
	CString str;
	str.Format("ROILT_3=%d", gROILT3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILT4 = INIReadInt("ROI_LT", "LT_4", 0);
	CString str;
	str.Format("ROILT_1=%d", gROILT4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILB1 = INIReadInt("ROI_LB", "LB_1", 0);
	CString str;
	str.Format("ROILB_1=%d", gROILB1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILB2 = INIReadInt("ROI_LB", "LB_2", 0);
	CString str;
	str.Format("ROILB_2=%d", gROILB2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILB3 = INIReadInt("ROI_LB", "LB_3", 0);
	CString str;
	str.Format("ROILB_3=%d", gROILB3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILB4 = INIReadInt("ROI_LB", "LB_4", 0);
	CString str;
	str.Format("ROILB_4=%d", gROILB4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRT1 = INIReadInt("ROI_RT", "RT_1", 0);
	CString str;
	str.Format("ROIRT_1=%d", gROIRT1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRT2 = INIReadInt("ROI_RT", "RT_2", 0);
	CString str;
	str.Format("ROIRT_2=%d", gROIRT2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRT3 = INIReadInt("ROI_RT", "RT_3", 0);
	CString str;
	str.Format("ROIRT_3=%d", gROIRT3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRT4 = INIReadInt("ROI_RT", "RT_4", 0);
	CString str;
	str.Format("ROIRT_4=%d", gROIRT4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRB1 = INIReadInt("ROI_RB", "RB_1", 0);
	CString str;
	str.Format("ROIRB_1=%d", gROIRB1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRB2 = INIReadInt("ROI_RB", "RB_2", 0);
	CString str;
	str.Format("ROIRB_2=%d", gROIRB2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRB3 = INIReadInt("ROI_RB", "RB_3", 0);
	CString str;
	str.Format("ROIRB_3=%d", gROIRB3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRB4 = INIReadInt("ROI_RB", "RB_4", 0);
	CString str;
	str.Format("ROIRB_4=%d", gROIRB4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceGAP = INIReadInt("Spec", "Spec_GAP", 0);
	CString str;
	str.Format("gDeviceGAP=%d", gDeviceGAP);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceCenter = INIReadInt("Spec", "Spec_CENTER", 0);
	CString str;
	str.Format("gDeviceCenter=%d", gDeviceCenter);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceCenter_Offset = INIReadInt("Offset", "Center_Offset", 0);
	CString str;
	str.Format("gDeviceCenter_Offset=%d", gDeviceCenter_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceCT = INIReadInt("Spec", "Spec_CT", 0);
	CString str;
	str.Format("gDeviceCT=%d", gDeviceCT);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceCT_Offset = INIReadInt("Offset", "CT_Offset", 0);
	CString str;
	str.Format("gDeviceCT_Offset=%d", gDeviceCT_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceLT = INIReadInt("Spec", "Spec_LT", 0);
	CString str;
	str.Format("gDeviceLT=%d", gDeviceLT);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceLT_Offset = INIReadInt("Offset", "LT_Offset", 0);
	CString str;
	str.Format("gDeviceLT_Offset=%d", gDeviceLT_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceLB = INIReadInt("Spec", "Spec_LB", 0);
	CString str;
	str.Format("gDeviceLB=%d", gDeviceLB);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceLB_Offset = INIReadInt("Offset", "LB_Offset", 0);
	CString str;
	str.Format("gDeviceLB_Offset=%d", gDeviceLB_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceRT = INIReadInt("Spec", "Spec_RT", 0);
	CString str;
	str.Format("gDeviceRT=%d", gDeviceRT);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceRT_Offset = INIReadInt("Offset", "RT_Offset", 0);
	CString str;
	str.Format("gDeviceRT_Offset=%d", gDeviceRT_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceRB = INIReadInt("Spec", "Spec_RB", 0);
	CString str;
	str.Format("gDeviceRB=%d", gDeviceRB);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceRB_Offset = INIReadInt("Offset", "RB_Offset", 0);
	CString str;
	str.Format("gDeviceRB_Offset=%d", gDeviceRB_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);
	*/
		
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}


void CCAKitViewerv05Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCAKitViewerv05Dlg::OnPaint()
{
	if (IsIconic())
	{
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
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCAKitViewerv05Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCAKitViewerv05Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (cap.isOpened()) {
		return;
	}

	bReturn = FALSE;
	bFail = FALSE;

	Camera_in();

}

void CCAKitViewerv05Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	bReturn = TRUE;
}

void CCAKitViewerv05Dlg::Camera_in()
{
	INT index;
	String str;

	/////////////////////////////////////////////////////////////////////////////////
	//
	
	char	tmp_buf3[64];

	Mat MatUser1, MatUser2, MatResize;


	/*
	// for HFOV 60 degree	--> 마곡...
	int Spec_CENTER = 4200;
	int Spec_CT = 3300;
	int Spec_LT = 2100;
	int Spec_LB = 2100;
	int Spec_RT = 2100;
	int Spec_RB = 2100;

	int Spec_GAP=300;

	int ROI_CENTER[4] = {857, 437, 204, 204};

	int ROI_CT[4] = {857, 0, 204, 204};
	int ROI_LT[4] = {30, 180, 204, 204};
	int ROI_LB[4] = {30, 710, 204, 204};
	int ROI_RT[4] = {1686, 180, 204, 204};
	int ROI_RB[4] = {1686, 710, 204, 204};
	*/

	/*
	// for HFOV 110 degree  --> 마곡...
	int Spec_CENTER = 9000;
	int Spec_CT = 7300;
	int Spec_LT = 5300;
	int Spec_LB = 5300;
	int Spec_RT = 5300;
	int Spec_RB = 5300;
	
	int Spec_GAP=300;
	
	int ROI_CENTER[4] = {908, 488, 102, 102};

	int ROI_CT[4] = { 908, 250, 102, 102};
	int ROI_LT[4] = {480, 340, 102, 102};
	int ROI_LB[4] = {480, 636, 102, 102};
	int ROI_RT[4] = {1338, 340, 102, 102};
	int ROI_RB[4] = {1338, 636, 102, 102};
	*/

	/*
	// for HFOV 60 degree	--> 광명...
	int Spec_CENTER = 4100;
	int Spec_CT = 3000;
	int Spec_LT = 2100;
	int Spec_LB = 2100;
	int Spec_RT = 2100;
	int Spec_RB = 2100;

	int Spec_GAP=200;

	int ROI_CENTER[4] = {857, 437, 204, 204};

	int ROI_CT[4] = {857, 0, 204, 204};
	int ROI_LT[4] = {30, 180, 204, 204};
	int ROI_LB[4] = {30, 710, 204, 204};
	int ROI_RT[4] = {1686, 180, 204, 204};
	int ROI_RB[4] = {1686, 710, 204, 204};
	*/

	/*
	// for HFOV 110 degree  --> 광명...
	int Spec_CENTER = 11000;
	int Spec_CT = 8500;
	int Spec_LT = 6800;
	int Spec_LB = 6800;
	int Spec_RT = 6800;
	int Spec_RB = 6800;

	int Spec_GAP=300;

	int ROI_CENTER[4] = {908, 488, 102, 102};

	int ROI_CT[4] = { 908, 250, 102, 102};
	int ROI_LT[4] = {480, 340, 102, 102};
	int ROI_LB[4] = {480, 636, 102, 102};
	int ROI_RT[4] = {1338, 340, 102, 102};
	int ROI_RB[4] = {1338, 636, 102, 102};
	*/

	// for HFOV 60 degree	--> R&D...
/*	int Spec_CENTER = 4100;
	int Spec_CT = 3000;
	int Spec_LT = 2100;
	int Spec_LB = 2100;
	int Spec_RT = 2100;
	int Spec_RB = 2100;

	int Spec_GAP = 200;
	*/

	// center point = 959, 539
	//int ROI_CENTER[4] = { 884, 464, 150, 150 };

	/*
	// WD=20cm
	int ROI_CT[4] = { 857, 0, 204, 204 };
	int ROI_LT[4] = { 336, 169, 204, 204 };
	int ROI_LB[4] = { 207, 783, 204, 204 };
	int ROI_RT[4] = { 1376, 169, 204, 204 };
	int ROI_RB[4] = { 1509, 783, 204, 204 };
	*/
/*
	// WD=30cm
	int ROI_CT[4] = { 857, 0, 150, 150 };
	int ROI_LT[4] = { 486, 249, 150, 150 };
	int ROI_LB[4] = { 407, 703, 160, 160 };
	int ROI_RT[4] = { 1283, 249, 150, 150 };
	int ROI_RB[4] = { 1362, 703, 160, 160 };
	*/

	int ROI_value_en = 1;

	/// Text Location
	cv::Point myPoint1, myPoint2;

	/// Font Face
	int myFontFace = 2;

	/// Font Scale
	double myFontScale = 0.8;
	double focusFontScale = 0.6;

	/////////////////////////////////////////////////////////////////////////////////////////////
	// ROI display
	int gap_value;
//;	int offset_x = 100, offset_y = 25;
	int offset_x = 70, offset_y = 25;

	int roi_cx, roi_cy, roi_cw, roi_ch;
	Mat mat_center, mat_ct, mat_lt, mat_lb, mat_rt, mat_rb;

	Mat mat_yuvinput, mat_yuvimage;
	Scalar mean_yuv;
	double var_y, var_u, var_v;

	Mat mat_center_dst, mat_ct_dst, mat_lt_dst, mat_lb_dst, mat_rt_dst, mat_rb_dst;
	Scalar mean, stddev; // 0:1st channel, 1:2nd channel and 2:3rd channel
	double var_center, var_ct, var_lt, var_lb, var_rt, var_rb;

	//
	/////////////////////////////////////////////////////////////////////////////////////////////




	index = GetDlgItemInt(IDC_EDIT1, 0, 1);

	///////////////////////////////////////////////////////////////////////////////

	
	///////////////////////////////////////////////////////////////////////////////

	cap.open(index);
	
		
	if (!cap.isOpened()) {
		cap.release();
		MessageBox(_T("CAKit not ready!"), _T("Check connect camera"), MB_OK);
		return;
	}



	Mat frame, resizeframe;
	
	gROICENTER1 = INIReadInt("ROI_CENTER", "CENTER_1", 0);
	gROICENTER2 = INIReadInt("ROI_CENTER", "CENTER_2", 0);
	gROICENTER3 = INIReadInt("ROI_CENTER", "CENTER_3", 0);
	gROICENTER4 = INIReadInt("ROI_CENTER", "CENTER_4", 0);
	gROICT1 = INIReadInt("ROI_CT", "CT_1", 0);
	gROICT2 = INIReadInt("ROI_CT", "CT_2", 0);
	gROICT3 = INIReadInt("ROI_CT", "CT_3", 0);
	gROICT4 = INIReadInt("ROI_CT", "CT_4", 0);
	gROILT1 = INIReadInt("ROI_LT", "LT_1", 0);
	gROILT2 = INIReadInt("ROI_LT", "LT_2", 0);
	gROILT3 = INIReadInt("ROI_LT", "LT_3", 0);
	gROILT4 = INIReadInt("ROI_LT", "LT_4", 0);
	gROILB1 = INIReadInt("ROI_LB", "LB_1", 0);
	gROILB2 = INIReadInt("ROI_LB", "LB_2", 0);
	gROILB3 = INIReadInt("ROI_LB", "LB_3", 0);
	gROILB4 = INIReadInt("ROI_LB", "LB_4", 0);
	gROIRT1 = INIReadInt("ROI_RT", "RT_1", 0);
	gROIRT2 = INIReadInt("ROI_RT", "RT_2", 0);
	gROIRT3 = INIReadInt("ROI_RT", "RT_3", 0);
	gROIRT4 = INIReadInt("ROI_RT", "RT_4", 0);
	gROIRB1 = INIReadInt("ROI_RB", "RB_1", 0);
	gROIRB2 = INIReadInt("ROI_RB", "RB_2", 0);
	gROIRB3 = INIReadInt("ROI_RB", "RB_3", 0);
	gROIRB4 = INIReadInt("ROI_RB", "RB_4", 0);

	gDeviceGAP = INIReadInt("Spec", "Spec_GAP", 0);

	gDeviceCenter = INIReadInt("Spec", "Spec_CENTER", 0);
	gDeviceCenter_Offset = INIReadInt("Offset", "Center_Offset", 0);

	gDeviceCT = INIReadInt("Spec", "Spec_CT", 0);
	gDeviceCT_Offset = INIReadInt("Offset", "CT_Offset", 0);

	gDeviceLT = INIReadInt("Spec", "Spec_LT", 0);
	gDeviceLT_Offset = INIReadInt("Offset", "LT_Offset", 0);

	gDeviceLB = INIReadInt("Spec", "Spec_LB", 0);
	gDeviceLB_Offset = INIReadInt("Offset", "LB_Offset", 0);

	gDeviceRT = INIReadInt("Spec", "Spec_RT", 0);
	gDeviceRT_Offset = INIReadInt("Offset", "RT_Offset", 0);

	gDeviceRB = INIReadInt("Spec", "Spec_RB", 0);
	gDeviceRB_Offset = INIReadInt("Offset", "RB_Offset", 0);

	while (true) {

		if (bFail == TRUE)
		{
			cap.open(index);
			

			if (!cap.isOpened()) {
				
				MessageBox(_T("Open-FAIL"), _T("isOpened"), MB_YESNO);
				cap.release();
				Sleep(300);
				continue;
			}
			else
			{
				MessageBox(_T("Open-PASS"), _T("isOpened"), MB_YESNO);
				bFail = FALSE;
			}
		}
		
		cap >> frame;
		if (frame.empty()) {
			MessageBox(_T("empty"), _T("empty"), MB_YESNO);

			cap.release();
			Sleep(300);
			bFail = TRUE;
			continue;
		}		

		/////////////////////////////////////////////////////////////////////////////////////////////
	// Optical center
		cv::line(frame, Point(960, 0), Point(960, 1080), Scalar(0, 0, 255), 1, LINE_AA, 0);
		cv::line(frame, Point(0, 540), Point(1920, 540), Scalar(0, 0, 255), 1, LINE_AA, 0);

		
		/////////////////////////////////////////////////////////////////////////////////////////////
		// ROI-CENTER
		roi_cx = gROICENTER1;
		roi_cy = gROICENTER2;
		roi_cw = gROICENTER1 + gROICENTER3;
		roi_ch = gROICENTER2 + gROICENTER4;
		cv::rectangle(frame, Point(roi_cx, roi_cy), Point(roi_cw, roi_ch), Scalar(0, 0, 255), 1, LINE_AA, 0);

		mat_center = frame(Rect(roi_cx, roi_cy, gROICENTER3, gROICENTER4));
		Laplacian(mat_center, mat_center_dst, CV_64F, 1, 1, 0);
		meanStdDev(mat_center_dst, mean, stddev, Mat());
		var_center = stddev.val[0] * stddev.val[0];

		// Y average display ----------------------------------------
		cvtColor(mat_center, mat_yuvinput, COLOR_BGR2YUV);
		vector<Mat> mat_yuvimage1(3);
		split(mat_yuvinput, mat_yuvimage1);
		mean_yuv = cv::mean(mat_yuvimage1[0]);
		var_y = mean_yuv.val[0];
		// Y average display ----------------------------------------

	//	imshow("Y", mat_yuvimage1[0]);  밝기 평면
	//	imshow("U", mat_yuvimage1[1]);  빨간색 색상 평면
	//	imshow("V", mat_yuvimage1[2]);  파란색 색상 평면

		
		if (ROI_value_en==1) {
			sprintf_s(tmp_buf3, "%.2f", var_center-gDeviceCenter_Offset);
			cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);

			sprintf_s(tmp_buf3, "Y=%.2f", var_y);
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y + 40), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);
		}
		

		if (gDeviceCenter <= (int)var_center) //var_center : stddev.val[0]제곱
		{
			sprintf_s(tmp_buf3, "PASS");
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 255, 0), 2);
		}
		else {

			gap_value = gDeviceCenter - gDeviceGAP; //Spec_GAP : 200;
			if (gap_value <= (int)var_center)
			{
				sprintf_s(tmp_buf3, "PASS");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 128, 255), 2);
			}
			else {
				sprintf_s(tmp_buf3, "FAIL");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 0, 255), 2);
			}
		}
	// for R&D
		/////////////////////////////////////////////////////////////////////////////////////////////
		// ROI-CT
		roi_cx = gROICT1;
		roi_cy = gROICT2;
		roi_cw = gROICT1 + gROICT3;
		roi_ch = gROICT2 + gROICT4;
		cv::rectangle(frame, Point(roi_cx, roi_cy), Point(roi_cw, roi_ch), Scalar(0, 0, 255), 1, LINE_AA, 0);

		mat_ct = frame(Rect(roi_cx, roi_cy, gROICT3, gROICT4));
		Laplacian(mat_ct, mat_ct_dst, CV_64F, 1, 1, 0);
		meanStdDev(mat_ct_dst, mean, stddev, Mat());
		var_ct = stddev.val[0] * stddev.val[0];

		// Y average display ----------------------------------------
		cvtColor(mat_ct, mat_yuvinput, COLOR_BGR2YUV);
		vector<Mat> mat_yuvimage2(3);
		split(mat_yuvinput, mat_yuvimage2);
		mean_yuv = cv::mean(mat_yuvimage2[0]);
		var_y = mean_yuv.val[0];
		// Y average display ----------------------------------------

		if (ROI_value_en == 1) {	
			sprintf_s(tmp_buf3, "%.2f", var_ct);
			cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);

			sprintf_s(tmp_buf3, "Y=%.2f", var_y);
			cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y + 40), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);
		}
		

		if (gDeviceCT <= (int)var_ct)
		{
			sprintf_s(tmp_buf3, "PASS");
			cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 255, 0), 2);
		}
		else {

			gap_value = gDeviceCT - gDeviceGAP;
			if (gap_value <= (int)var_ct)
			{
				sprintf_s(tmp_buf3, "PASS");
				cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 128, 255), 2);
			}
			else {
				sprintf_s(tmp_buf3, "FAIL");
				cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 0, 255), 2);
			}
		}


		/////////////////////////////////////////////////////////////////////////////////////////////
		// ROI-LT
		roi_cx = gROILT1;
		roi_cy = gROILT2;
		roi_cw = gROILT1 + gROILT3;
		roi_ch = gROILT2 + gROILT4;
		cv::rectangle(frame, Point(roi_cx, roi_cy), Point(roi_cw, roi_ch), Scalar(0, 0, 255), 1, LINE_AA, 0);

		mat_lt = frame(Rect(roi_cx, roi_cy, gROILT3, gROILT4));
		Laplacian(mat_lt, mat_lt_dst, CV_64F, 1, 1, 0);
		meanStdDev(mat_lt_dst, mean, stddev, Mat());
		var_lt = stddev.val[0] * stddev.val[0];

		// Y average display ----------------------------------------
		cvtColor(mat_lt, mat_yuvinput, COLOR_BGR2YUV);
		vector<Mat> mat_yuvimage3(3);
		split(mat_yuvinput, mat_yuvimage3);
		mean_yuv = cv::mean(mat_yuvimage3[0]);
		var_y = mean_yuv.val[0];
		// Y average display ----------------------------------------

		if (ROI_value_en == 1) {
			
			sprintf_s(tmp_buf3, "%.2f", var_lt+gDeviceLT_Offset);
			cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);

			sprintf_s(tmp_buf3, "Y=%.2f", var_y);
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y + 40), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);
		}
		
		

		if (gDeviceLT <= (int)var_lt)
		{
			sprintf_s(tmp_buf3, "PASS");
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 255, 0), 2);
		}
		else {
			gap_value = gDeviceLT - gDeviceGAP;
			if (gap_value <= (int)var_lt)
			{
				sprintf_s(tmp_buf3, "PASS");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 128, 255), 2);
			}
			else {
				sprintf_s(tmp_buf3, "FAIL");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 0, 255), 2);
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		// ROI-LB
		roi_cx = gROILB1;
		roi_cy = gROILB2;
		roi_cw = gROILB1 + gROILB3;
		roi_ch = gROILB2 + gROILB4;
		cv::rectangle(frame, Point(roi_cx, roi_cy), Point(roi_cw, roi_ch), Scalar(0, 0, 255), 1, LINE_AA, 0);

		mat_lb = frame(Rect(roi_cx, roi_cy, gROILB3, gROILB4));
		Laplacian(mat_lb, mat_lb_dst, CV_64F, 1, 1, 0);
		meanStdDev(mat_lb_dst, mean, stddev, Mat());
		var_lb = stddev.val[0] * stddev.val[0];

		// Y average display ----------------------------------------
		cvtColor(mat_lb, mat_yuvinput, COLOR_BGR2YUV);
		vector<Mat> mat_yuvimage4(3);
		split(mat_yuvinput, mat_yuvimage4);
		mean_yuv = cv::mean(mat_yuvimage4[0]);
		var_y = mean_yuv.val[0];
		// Y average display ----------------------------------------

		if (ROI_value_en == 1) {
			
			sprintf_s(tmp_buf3, "%.2f", var_lb- gDeviceLB_Offset);
			cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);

			sprintf_s(tmp_buf3, "Y=%.2f", var_y);
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y + 40), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);
		}
		

		if (gDeviceLB <= (int)var_lb)
		{
			sprintf_s(tmp_buf3, "PASS");
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 255, 0), 2);
		}
		else {
			gap_value = gDeviceLB - gDeviceGAP;
			if (gap_value <= (int)var_lb)
			{
				sprintf_s(tmp_buf3, "PASS");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 128, 255), 2);
			}
			else {
				sprintf_s(tmp_buf3, "FAIL");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 0, 255), 2);
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		// ROI-RT
		roi_cx = gROIRT1;
		roi_cy = gROIRT2;
		roi_cw = gROIRT1 + gROIRT3;
		roi_ch = gROIRT2 + gROIRT4;
		cv::rectangle(frame, Point(roi_cx, roi_cy), Point(roi_cw, roi_ch), Scalar(0, 0, 255), 1, LINE_AA, 0);

		mat_rt = frame(Rect(roi_cx, roi_cy, gROIRT3, gROIRT4));
		Laplacian(mat_rt, mat_rt_dst, CV_64F, 1, 1, 0);
		meanStdDev(mat_rt_dst, mean, stddev, Mat());
		var_rt = stddev.val[0] * stddev.val[0];

		// Y average display ----------------------------------------
		cvtColor(mat_rt, mat_yuvinput, COLOR_BGR2YUV);
		vector<Mat> mat_yuvimage5(3);
		split(mat_yuvinput, mat_yuvimage5);
		mean_yuv = cv::mean(mat_yuvimage5[0]);
		var_y = mean_yuv.val[0];
		// Y average display ----------------------------------------

		if (ROI_value_en == 1) {
			

			sprintf_s(tmp_buf3, "%.2f", var_rt-gDeviceRT_Offset);
			cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);

			sprintf_s(tmp_buf3, "Y=%.2f", var_y);
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y + 40), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);
		}
		

		if (gDeviceRT <= (int)var_rt)
		{
			sprintf_s(tmp_buf3, "PASS");
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 255, 0), 2);
		}
		else {

			gap_value = gDeviceRT - gDeviceGAP;
			if (gap_value <= (int)var_rt)
			{
				sprintf_s(tmp_buf3, "PASS");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 128, 255), 2);
			}
			else {
				sprintf_s(tmp_buf3, "FAIL");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 0, 255), 2);
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		// ROI-RB
		roi_cx = gROIRB1;
		roi_cy = gROIRB2;
		roi_cw = gROIRB1 + gROIRB3;
		roi_ch = gROIRB2 + gROIRB4;
		cv::rectangle(frame, Point(roi_cx, roi_cy), Point(roi_cw, roi_ch), Scalar(0, 0, 255), 1, LINE_AA, 0);

		mat_rb = frame(Rect(roi_cx, roi_cy, gROIRB3, gROIRB4));
		Laplacian(mat_rb, mat_rb_dst, CV_64F, 1, 1, 0);
		meanStdDev(mat_rb_dst, mean, stddev, Mat());
		var_rb = stddev.val[0] * stddev.val[0];

		// Y average display ----------------------------------------
		cvtColor(mat_rb, mat_yuvinput, COLOR_BGR2YUV);
		vector<Mat> mat_yuvimage6(3);
		split(mat_yuvinput, mat_yuvimage6);
		mean_yuv = cv::mean(mat_yuvimage6[0]);
		var_y = mean_yuv.val[0];
		// Y average display ----------------------------------------

		if (ROI_value_en == 1) {
			sprintf_s(tmp_buf3, "%.2f", var_rb - gDeviceRB_Offset);
			cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);
			
			sprintf_s(tmp_buf3, "Y=%.2f", var_y);
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx + offset_x, roi_ch + offset_y + 40), myFontFace, focusFontScale, Scalar(0, 255, 255), 2);
		}
		

		if (gDeviceRB <= (int)var_rb)
		{
			sprintf_s(tmp_buf3, "PASS");
		;	cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 255, 0), 2);
		}
		else {

			gap_value = gDeviceRB -gDeviceGAP;
			if (gap_value <= (int)var_rb)
			{
				sprintf_s(tmp_buf3, "PASS");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 128, 255), 2);
			}
			else {
				sprintf_s(tmp_buf3, "FAIL");
		;		cv::putText(frame, &tmp_buf3[0], Point(roi_cx, roi_ch + offset_y), myFontFace, myFontScale, Scalar(0, 0, 255), 2);
			}
		}


	//;	frame.resize(0, 0, 1280, 720);

		imshow("CAKit viewer HFOV110 210603", frame);

	//	cv::resize(frame, resizeframe, Size(1280, 720), 0, 0, INTER_LINEAR);
	//	imshow("CAKit viewer", resizeframe);

		if (waitKey(10) == 27) // ESC key 
			continue;

		if (bReturn == TRUE) break;
	}

	destroyAllWindows();
	cap.release();
}

void CCAKitViewerv05Dlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	bReturn = TRUE;

	CDialogEx::OnClose();
}


//HRESULT CCAKitViewerv05Dlg::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//
//	return CDialogEx::accDoDefaultAction(varChild);
//}


//unsigned int CCAKitViewerv05Dlg::INIReadInt(LPCTSTR lpAppName, LPCTSTR lpKey, INT nDefault)
//{
//	// TODO: 여기에 구현 코드 추가
//	char filedir[MAX_PATH] = { 0 };
//
//	//_getcwd(rootdir, MAX_PATH);  //프로그램 수행시의 절대경로여야 한다. 파일저장 후 현재경로는 바뀌므로 사용불가
//	wsprintf(filedir, "%s\\Ref\\CAKit_OPTION.ini", gRootDir);
//	return GetPrivateProfileInt(lpAppName, lpKey, nDefault, filedir);
//}
void CCAKitViewerv05Dlg::Update() {

	gROICENTER1 = INIReadInt("ROI_CENTER", "CENTER_1", 0);
	gROICENTER2 = INIReadInt("ROI_CENTER", "CENTER_2", 0);
	gROICENTER3 = INIReadInt("ROI_CENTER", "CENTER_3", 0);
	gROICENTER4 = INIReadInt("ROI_CENTER", "CENTER_4", 0);
	gROICT1 = INIReadInt("ROI_CT", "CT_1", 0);
	gROICT2 = INIReadInt("ROI_CT", "CT_2", 0);
	gROICT3 = INIReadInt("ROI_CT", "CT_3", 0);
	gROICT4 = INIReadInt("ROI_CT", "CT_4", 0);
	gROILT1 = INIReadInt("ROI_LT", "LT_1", 0);
	gROILT2 = INIReadInt("ROI_LT", "LT_2", 0);
	gROILT3 = INIReadInt("ROI_LT", "LT_3", 0);
	gROILT4 = INIReadInt("ROI_LT", "LT_4", 0);
	gROILB1 = INIReadInt("ROI_LB", "LB_1", 0);
	gROILB2 = INIReadInt("ROI_LB", "LB_2", 0);
	gROILB3 = INIReadInt("ROI_LB", "LB_3", 0);
	gROILB4 = INIReadInt("ROI_LB", "LB_4", 0);
	gROIRT1 = INIReadInt("ROI_RT", "RT_1", 0);
	gROIRT2 = INIReadInt("ROI_RT", "RT_2", 0);
	gROIRT3 = INIReadInt("ROI_RT", "RT_3", 0);
	gROIRT4 = INIReadInt("ROI_RT", "RT_4", 0);
	gROIRB1 = INIReadInt("ROI_RB", "RB_1", 0);
	gROIRB2 = INIReadInt("ROI_RB", "RB_2", 0);
	gROIRB3 = INIReadInt("ROI_RB", "RB_3", 0);
	gROIRB4 = INIReadInt("ROI_RB", "RB_4", 0);

	gDeviceGAP = INIReadInt("Spec", "Spec_GAP", 0);

	gDeviceCenter = INIReadInt("Spec", "Spec_CENTER", 0);
	gDeviceCenter_Offset = INIReadInt("Offset", "Center_Offset", 0);

	gDeviceCT = INIReadInt("Spec", "Spec_CT", 0);
	gDeviceCT_Offset = INIReadInt("Offset", "CT_Offset", 0);

	gDeviceLT = INIReadInt("Spec", "Spec_LT", 0);
	gDeviceLT_Offset = INIReadInt("Offset", "LT_Offset", 0);

	gDeviceLB = INIReadInt("Spec", "Spec_LB", 0);
	gDeviceLB_Offset = INIReadInt("Offset", "LB_Offset", 0);

	gDeviceRT = INIReadInt("Spec", "Spec_RT", 0);
	gDeviceRT_Offset = INIReadInt("Offset", "RT_Offset", 0);

	gDeviceRB = INIReadInt("Spec", "Spec_RB", 0);
	gDeviceRB_Offset = INIReadInt("Offset", "RB_Offset", 0);

}
unsigned int CCAKitViewerv05Dlg::INIReadInt(LPCTSTR lpAppName, LPCTSTR lpKey, INT nDefault)
{
	// TODO: 여기에 구현 코드 추가
	char filedir[MAX_PATH] = { 0 };

	//_getcwd(rootdir, MAX_PATH);  //프로그램 수행시의 절대경로여야 한다. 파일저장 후 현재경로는 바뀌므로 사용불가
	wsprintf(filedir, "%s\\Ref\\CAKit_OPTION.ini", gRootDir);
	return GetPrivateProfileInt(lpAppName, lpKey, nDefault, filedir);
}

void CCAKitViewerv05Dlg::OnBnClickedButton3()
{
	Update();
	//gROILT1 = INIReadInt("ROI_LT", "LT_1", 0);
//	CString str;
	//str.Format("ROILT1=%d", gROILT1);
	//MessageBox(str, _T("CAKit not ready!"), MB_OK);
	
	/*
	gROICENTER2 = INIReadInt("ROI_CENTER", "CENTER_2", 0);
	CString str;
	str.Format("ROICENTER_2=%d", gROICENTER2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROICENTER3 = INIReadInt("ROI_CENTER", "CENTER_3", 0);
	CString str;
	str.Format("ROICENTER_3=%d", gROICENTER3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROICENTER4 = INIReadInt("ROI_CENTER", "CENTER_4", 0);
	CString str;
	str.Format("ROICENTER_4=%d", gROICENTER4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROICT1 = INIReadInt("ROI_CT", "CT_1", 0);
	CString str;
	str.Format("ROICT_1 = %d", gROICT1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROICT2 = INIReadInt("ROI_CT", "CT_2", 0);
	CString str;
	str.Format("ROICT_2=%d", gROICT2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROICT3 = INIReadInt("ROI_CT", "CT_3", 0);
	CString str;
	str.Format("ROICT_3=%d", gROICT3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROICT4 = INIReadInt("ROI_CT", "CT_4", 0);
	CString str;
	str.Format("ROICT_4=%d", gROICT4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROILT1 = INIReadInt("ROI_LT", "LT_1", 0);
	CString str;
	str.Format("ROILT_1=%d", gROILT1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);


	gROILT2 = INIReadInt("ROI_LT", "LT_2", 0);
	CString str;
	str.Format("ROILT_2=%d", gROILT2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILT3 = INIReadInt("ROI_LT", "LT_3", 0);
	CString str;
	str.Format("ROILT_3=%d", gROILT3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILT4 = INIReadInt("ROI_LT", "LT_4", 0);
	CString str;
	str.Format("ROILT_1=%d", gROILT4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILB1 = INIReadInt("ROI_LB", "LB_1", 0);
	CString str;
	str.Format("ROILB_1=%d", gROILB1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILB2 = INIReadInt("ROI_LB", "LB_2", 0);
	CString str;
	str.Format("ROILB_2=%d", gROILB2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILB3 = INIReadInt("ROI_LB", "LB_3", 0);
	CString str;
	str.Format("ROILB_3=%d", gROILB3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROILB4 = INIReadInt("ROI_LB", "LB_4", 0);
	CString str;
	str.Format("ROILB_4=%d", gROILB4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRT1 = INIReadInt("ROI_RT", "RT_1", 0);
	CString str;
	str.Format("ROIRT_1=%d", gROIRT1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRT2 = INIReadInt("ROI_RT", "RT_2", 0);
	CString str;
	str.Format("ROIRT_2=%d", gROIRT2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRT3 = INIReadInt("ROI_RT", "RT_3", 0);
	CString str;
	str.Format("ROIRT_3=%d", gROIRT3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRT4 = INIReadInt("ROI_RT", "RT_4", 0);
	CString str;
	str.Format("ROIRT_4=%d", gROIRT4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRB1 = INIReadInt("ROI_RB", "RB_1", 0);
	CString str;
	str.Format("ROIRB_1=%d", gROIRB1);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRB2 = INIReadInt("ROI_RB", "RB_2", 0);
	CString str;
	str.Format("ROIRB_2=%d", gROIRB2);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRB3 = INIReadInt("ROI_RB", "RB_3", 0);
	CString str;
	str.Format("ROIRB_3=%d", gROIRB3);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gROIRB4 = INIReadInt("ROI_RB", "RB_4", 0);
	CString str;
	str.Format("ROIRB_4=%d", gROIRB4);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceGAP = INIReadInt("Spec", "Spec_GAP", 0);
	CString str;
	str.Format("gDeviceGAP=%d", gDeviceGAP);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceCenter = INIReadInt("Spec", "Spec_CENTER", 0);
	CString str;
	str.Format("gDeviceCenter=%d", gDeviceCenter);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceCenter_Offset = INIReadInt("Offset", "Center_Offset", 0);
	CString str;
	str.Format("gDeviceCenter_Offset=%d", gDeviceCenter_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceCT = INIReadInt("Spec", "Spec_CT", 0);
	CString str;
	str.Format("gDeviceCT=%d", gDeviceCT);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceCT_Offset = INIReadInt("Offset", "CT_Offset", 0);
	CString str;
	str.Format("gDeviceCT_Offset=%d", gDeviceCT_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceLT = INIReadInt("Spec", "Spec_LT", 0);
	CString str;
	str.Format("gDeviceLT=%d", gDeviceLT);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceLT_Offset = INIReadInt("Offset", "LT_Offset", 0);
	CString str;
	str.Format("gDeviceLT_Offset=%d", gDeviceLT_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceLB = INIReadInt("Spec", "Spec_LB", 0);
	CString str;
	str.Format("gDeviceLB=%d", gDeviceLB);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceLB_Offset = INIReadInt("Offset", "LB_Offset", 0);
	CString str;
	str.Format("gDeviceLB_Offset=%d", gDeviceLB_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceRT = INIReadInt("Spec", "Spec_RT", 0);
	CString str;
	str.Format("gDeviceRT=%d", gDeviceRT);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceRT_Offset = INIReadInt("Offset", "RT_Offset", 0);
	CString str;
	str.Format("gDeviceRT_Offset=%d", gDeviceRT_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceRB = INIReadInt("Spec", "Spec_RB", 0);
	CString str;
	str.Format("gDeviceRB=%d", gDeviceRB);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);

	gDeviceRB_Offset = INIReadInt("Offset", "RB_Offset", 0);
	CString str;
	str.Format("gDeviceRB_Offset=%d", gDeviceRB_Offset);
	MessageBox(str, _T("CAKit not ready!"), MB_OK);
	*/
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
