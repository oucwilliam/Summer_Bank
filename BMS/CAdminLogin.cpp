// CAdminLogin.cpp: 实现文件
//

#include "stdafx.h"
#include "BMS.h"
#include "CAdminLogin.h"
#include "afxdialogex.h"
#include "CMainDialog.h"
#include "CFirstDlg.h"

// CAdminLogin 对话框

IMPLEMENT_DYNAMIC(CAdminLogin, CDialogEx)

CAdminLogin::CAdminLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_AdminLogin, pParent)
{

}

CAdminLogin::~CAdminLogin()
{
}

void CAdminLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdminLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAdminLogin::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAdminLogin::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAdminLogin 消息处理程序


void CAdminLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strName;
	CString strPwd;

	this->GetDlgItemText(IDC_EDIT1_Admin, strName);
	this->GetDlgItemText(IDC_EDIT_AdminPwd, strPwd);
	if (strName == "admin" && strPwd == "admin")
	{
		MessageBox(_T("登录成功"));
		this->ShowWindow(SW_HIDE);
		CMainDialog dlg;
		dlg.SetInfo(strName);
		dlg.DoModal();
	}
	else
	{
		MessageBox(_T("登录失败,请重试"));
		CAdminLogin CAL;
		CAL.DoModal();
	}
	
	CDialogEx::OnOK();
}


void CAdminLogin::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CFirstDlg CAL;
	CAL.DoModal();
	CDialogEx::OnCancel();
}
