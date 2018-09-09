// SaveMoney.cpp: 实现文件
//

#include "stdafx.h"
#include "BMS.h"
#include "SaveMoney.h"
#include "afxdialogex.h"
#include "CMainDialog.h"

// SaveMoney 对话框

IMPLEMENT_DYNAMIC(SaveMoney, CDialogEx)

SaveMoney::SaveMoney(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SaveMoney, pParent)
{

}

SaveMoney::~SaveMoney()
{
}

void SaveMoney::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SaveMoney, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &SaveMoney::OnBnClickedCancel)
END_MESSAGE_MAP()


// SaveMoney 消息处理程序


void SaveMoney::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CMainDialog Main;
	Main.DoModal();
	CDialogEx::OnCancel();
}
