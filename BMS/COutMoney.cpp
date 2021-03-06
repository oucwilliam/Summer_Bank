// COutMoney.cpp: 实现文件
//
#include <sstream>
#include <cstdio>
#include "stdafx.h"
#include "BMS.h"
#include "COutMoney.h"
#include "afxdialogex.h"
#include "CMainDialog.h"
#include "Bank.h"
#include "User.h"
#include<string>
// COutMoney 对话框
using namespace std;
IMPLEMENT_DYNAMIC(COutMoney, CDialogEx)

COutMoney::COutMoney(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_OutMoney, pParent)
{

}

COutMoney::~COutMoney()
{
}

void COutMoney::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COutMoney, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &COutMoney::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &COutMoney::OnBnClickedButtonSure)
END_MESSAGE_MAP()


// COutMoney 消息处理程序


void COutMoney::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CMainDialog Main;
	Main.DoModal();
	CDialogEx::OnCancel();
}


BOOL COutMoney::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void COutMoney::OnBnClickedButtonSure()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strID;
	CString strNum;
	this->GetDlgItemText(IDC_EDIT_SaveID, strID);
	this->GetDlgItemText(IDC_EDIT_Num, strNum);
	User user;
	double i = 0;
	
	int p = 0;
	bool judge = 1;
	string pas[3];
	string m0,Account,Pwd;
	CString m1;
	int mm;
	double money = user.getMoney_self();
	/*
	cout << "您一共有" << toa + 1 << "笔存款";
	cout << "存款的总金额是" << getMoney_self() + getinterest() << endl;
	cout << "目前账户拥有存款单如下:" << endl;
	for (int l = 0; l <= toa; l++) {
		cout << Md[l] << endl;
	}
	cout << "请选择将要操作的取款单" << endl;*/
	mm = _ttoi(strID);
Sr:
	for (int l = 0; l <= toa; l++) {
		if (Md[l] == mm) {
			judge = 0;
			break;
		}
	}
	if (judge) {
		MessageBox(_T("输入的流水单号不存在，请重新输入"));
		judge = 0;
		goto Sr;
	}
	m1.Format(_T("%04x"),mm);
	m0 = (CStringA)m1;
	Account = (CStringA)m_strUser;
	Pwd = (CStringA)m_strPwd;

	/*cout << "存款单" << mm << "拥有的存款总额为: " << getmdMoney(m0);
	cout << "请输入取款金额" << endl;
	cin >> i;

	cout << "你的取款金额为" << i << "元。" << "请确认取款金额(请输入1)。" << endl;
	cin >> j;*/
	i = _ttoi(strNum);


	if (money - i >= 0) {
		money = money - i;
		//cout << "交易正在处理,交易成功。" << endl;

		setMoney_self(money);
		pas[0] = "\\" + Account + ".txt";
		pas[1] = "\\" + Pwd + ".txt";
		pas[2] = "\\MD\\" + m0 + ".txt";
		/*CString p0(pas[0].c_str());
		CString p1(pas[1].c_str());
		CString p2(pas[2].c_str());*/
		//cout<<pas[2];
		Bank bank;
		bank.change(2, pas[0], money, 0, i);
		bank.change(4, pas[1], money, 1, i);
		bank.change(3, pas[2], money, 2, i);

	}
	else if (money - i < 0) {
		MessageBox(_T("超出了此存款单的余额上限，请输入正确的金额"))  ;
	}
	else 
	{
		MessageBox(_T("交易金额未确认，交易失败。")); 
	}
}
