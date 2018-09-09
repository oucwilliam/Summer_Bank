// CFirstDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "BMS.h"
#include "CFirstDlg.h"
#include "afxdialogex.h"
#include "BMSDlg.h"
#include "CAdminLogin.h"

// CFirstDlg 对话框

IMPLEMENT_DYNAMIC(CFirstDlg, CDialogEx)

CFirstDlg::CFirstDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FirstDialog, pParent)
{

}

CFirstDlg::~CFirstDlg()
{
}

void CFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirstDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_login, &CFirstDlg::OnBnClickedButtonlogin)
	ON_BN_CLICKED(IDOK, &CFirstDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_Add, &CFirstDlg::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CFirstDlg 消息处理程序


void CFirstDlg::OnBnClickedButtonlogin()
{
	this->ShowWindow(SW_HIDE);
	CAdminLogin Dlg;
	Dlg.DoModal();
}


void CFirstDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CFirstDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
}
