// CAdd.cpp: 实现文件
//

#include "stdafx.h"
#include "BMS.h"
#include "CAdd.h"
#include "afxdialogex.h"
#include "CMainDialog.h"

// CAdd 对话框

IMPLEMENT_DYNAMIC(CAdd, CDialogEx)

CAdd::CAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Add, pParent)
{

}

CAdd::~CAdd()
{
}

void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdd, CDialogEx)
	ON_BN_CLICKED(IDBack, &CAdd::OnBnClickedBack)
END_MESSAGE_MAP()


// CAdd 消息处理程序


void CAdd::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CMainDialog Main;
	Main.DoModal();
}
