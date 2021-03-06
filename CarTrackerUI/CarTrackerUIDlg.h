#pragma once
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <iostream>
#include <time.h>
#include <direct.h>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2\opencv.hpp>

#include <fstream>
#include "Blob.h"

using namespace std;
using namespace cv;

// const global variables
const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);
const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
const cv::Scalar SCALAR_YELLOW = cv::Scalar(0.0, 255.0, 255.0);
const cv::Scalar SCALAR_GREEN = cv::Scalar(0.0, 200.0, 0.0);
const cv::Scalar SCALAR_RED = cv::Scalar(0.0, 0.0, 255.0);



// CCarTrackerUIDlg dialog
class CCarTrackerUIDlg : public CDialogEx
{
	// Construction
public:
	CCarTrackerUIDlg(CWnd* pParent = NULL);	// standard constructor

												// Dialog Data
	enum { IDD = IDD_CARTRACKERUI_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


	Mat m_oriMat;
	Mat m_workMat;


	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()



	//LRESULT LeftCameraShow(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedButtonopen();
	char* WideCharToMultiByteMy(LPCTSTR pwszUnicode);
	afx_msg void OnBnClickedButtondetect();
	void ShowMatImgToWnd(CWnd* pWnd, cv::Mat img);
	CString m_csFilePath;

	// function prototypes
	void matchCurrentFrameBlobsToExistingBlobs(std::vector<Blob> &existingBlobs, std::vector<Blob> &currentFrameBlobs);
	void addBlobToExistingBlobs(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs, int &intIndex);
	void addNewBlob(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs);
	double distanceBetweenPoints(cv::Point point1, cv::Point point2);
	Mat drawAndShowContours(cv::Size imageSize, std::vector<std::vector<cv::Point> > contours, std::string strImageName);
	Mat drawAndShowContours(cv::Size imageSize, std::vector<Blob> blobs, std::string strImageName);
	bool checkIfBlobsCrossedTheLineRight(std::vector<Blob> &blobs, int &intHorizontalLinePosition, int &carCountRight);
	bool checkIfBlobsCrossedTheLineLeft(std::vector<Blob> &blobs, int &intHorizontalLinePositionLeft, int &carCountLeft);
	void drawBlobInfoOnImage(std::vector<Blob> &blobs, cv::Mat &drawFrame);
	void drawCarCountOnImage(int &carCountRight, cv::Mat &drawFrame);
};
