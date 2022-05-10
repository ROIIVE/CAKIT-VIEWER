
// CAKitViewer_v0.5Dlg.h: 헤더 파일
//

#pragma once

#include "opencv2/opencv.hpp"
#include <iostream>



using namespace cv;
using namespace std;



// CCAKitViewerv05Dlg 대화 상자
class CCAKitViewerv05Dlg : public CDialogEx
{
// 생성입니다.
public:
	CCAKitViewerv05Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	void Update();
	unsigned int INIReadInt(LPCTSTR lpAppName, LPCTSTR lpKey, INT nDefault);
	void Camera_in();
	BOOL bReturn;
	BOOL bFail;
	
	VideoCapture cap;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAKITVIEWER_V05_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
//	unsigned int INIReadInt();
//	unsigned int INIReadInt(LPCTSTR lpAppName, LPCTSTR lpKey, INT nDefault);
//	unsigned int INIReadInt(const char* lpAppName, const char* lpKey, INT nDefault);
//	unsigned int INIReadInt(LPCTSTR lpAppName, LPCTSTR lpKey, INT nDefault);
	afx_msg void OnBnClickedButton3();
};
