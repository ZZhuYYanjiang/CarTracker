
// CarTrackerUI.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCarTrackerUIApp:
// See CarTrackerUI.cpp for the implementation of this class
//

class CCarTrackerUIApp : public CWinApp
{
public:
	CCarTrackerUIApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCarTrackerUIApp theApp;
