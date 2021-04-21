
// pi_to_n_digit.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CpitondigitApp:
// See pi_to_n_digit.cpp for the implementation of this class
//

class CpitondigitApp : public CWinApp
{
public:
	CpitondigitApp();
	int precision;

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CpitondigitApp theApp;
