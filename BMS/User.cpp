#include "stdafx.h"

#include "Bank.h"
#include "Time.h"
#include "afxdialogex.h"
#include "BMS.h"
#include "User.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#define Flag
#endif

User::User()
{
}


User::~User()
{
}
void User::ShowInformation(){
     string file_pass,acc,pass,time_on,aID,User,Pwd;
     double interest;
     double money_self;
     int time_day,time_month,time_year,temp=-1,md5;
	 User = (CStringA)m_strUser;
	 Pwd = (CStringA)m_strPwd;
	 file_pass =  "Account\\" + User +"\\"+ User + ".txt";
	 ifstream Information;
     Information.open(file_pass,ios::in);
     Information>>acc;
	 Information >> pass;
     Information>>aID;
     //cout<<acc<<endl;
     //Information_A>>kind;
     Information>>money_self;
     Information>>time_on;
     Information>>interest;//这里一定要按数据储存的次序来；下面给类中的数据赋值的就不需要了；
     while(Information>>md5){
       temp++;
       Md = new int[1];
       Md[temp]=md5;
     }
     toa = temp;
     //setKind(kind);
	 setPword(pass);
     setTime_on(time_on);
     setID(aID);
     setMoney_self(money_self);
     setinterest(interest);
     //time_year =(time_on[0]-48)*1000+(time_on[1]-48)*100+(time_on[2]-48)*10+(time_on[3]-48)*1;
     //time_month = (time_on[4]-48)*10+(time_on[5]-48);
     //time_day = (time_on[6]-48)*1000+(time_on[7]-48);
	/* Cstring strMsg;
	 strMsg.Format("%c",time_on[0]);
	 SetDlgItemText(IDC_STATIC1, strMsg);
	 */
	 time_year = 1;
	 time_month = 1;
	 time_day = 1;
     setyear(time_year);
     setmonth(time_month);
     setday(time_day);
     Information.close();
     //cout<<acc<<endl<<kind<<endl<<money_self<<endl<<time_on<<endl<<interest;
}
void User::SetUser(CString strUser)
{
	m_strUser = strUser;
}

void User::SetPwd(CString strPwd)
{
	m_strPwd = strPwd;
}
