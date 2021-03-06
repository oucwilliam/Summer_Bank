#pragma once

#include "User.h"

// COutMoney 对话框

class COutMoney :public User,public CDialogEx
{
	DECLARE_DYNAMIC(COutMoney)

public:
	COutMoney(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~COutMoney();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OutMoney };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSure();


};
