#pragma once


// CAdminLogin 对话框

class CAdminLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CAdminLogin)

public:
	CAdminLogin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAdminLogin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_AdminLogin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
