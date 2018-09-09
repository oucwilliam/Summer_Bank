// CLost.cpp: 实现文件
//

#include "stdafx.h"
#include "BMS.h"
#include "CLost.h"
#include "afxdialogex.h"
#include "CMainDialog.h"

// CLost 对话框

IMPLEMENT_DYNAMIC(CLost, CDialogEx)

CLost::CLost(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Lost, pParent)
{

}

CLost::~CLost()
{
}

void CLost::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLost, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CLost::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLost 消息处理程序


void CLost::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CMainDialog Main;
	Main.DoModal();
	CDialogEx::OnCancel();
}
