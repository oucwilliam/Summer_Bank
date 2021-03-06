// CMainDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "BMS.h"
#include "CMainDialog.h"
#include "afxdialogex.h"
#include "CAdd.h"
#include "SaveMoney.h"
#include "BMSDlg.h"
#include "Clost.h"
#include "COutMoney.h"
// CMainDialog 对话框

IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Main_Dialog, pParent)
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC_Text, &CMainDialog::OnStnClickedStaticText)
	ON_BN_CLICKED(IDOK, &CMainDialog::OnBnClickedOk)
	ON_BN_CLICKED(ID_BtnAdd, &CMainDialog::OnBnClickedBtnadd)
	ON_BN_CLICKED(IDC_BUTTON_Save, &CMainDialog::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_OutMoney, &CMainDialog::OnBnClickedButtonOutmoney)
	ON_BN_CLICKED(IDC_BUTTON_Lost, &CMainDialog::OnBnClickedButtonLost)
	ON_BN_CLICKED(IDC_BUTTON_UserLgn, &CMainDialog::OnBnClickedButtonUserlgn)
END_MESSAGE_MAP()


// CMainDialog 消息处理程序


void CMainDialog::OnStnClickedStaticText()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMainDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

void CMainDialog::SetInfo(CString strInfo)
{
	m_strInfo = strInfo;
}

BOOL CMainDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	this->SetDlgItemText(IDC_STATIC_Text, m_strInfo);

	// TODO:  在此添加额外的初始化
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}




void CMainDialog::OnBnClickedBtnadd()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CAdd Add;
	Add.DoModal();
}




void CMainDialog::OnBnClickedButtonSave()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	SaveMoney Save;
	Save.DoModal();
}



void CMainDialog::OnBnClickedButtonOutmoney()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	COutMoney COM;
	COM.DoModal();
}


void CMainDialog::OnBnClickedButtonLost()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CLost Lost;
	Lost.DoModal();
}







void CMainDialog::OnBnClickedButtonUserlgn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CBMSDlg CBD;
	CBD.DoModal();
}
