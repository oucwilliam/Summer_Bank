#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include <iostream>
#include "User.h"
#include <fstream>
#include "Saver.h"
#include "Time.h"
#include<string>

class Bank:public User{
  public:
    //void Ar_User();	//管理用户信息
    //void Ar_Saver();	//管理储蓄员信息
    bool Check_ID(bool sit);	//验证身份
    void Output();	//取款
    //void Input();	//存款
    //void Lost_C();	//丢卡
    void Set_New_user();
    double interest_cout();	//计算利息
    void Foot();	//业务办理记录
    void Out_Show();//调出取款的界面；
    //void interest_cout();
    void change(int i,string road,double money,int judge,double k);
    double Interest_costing(double Money_Self, int days, double fax, int kind);
    double getmdMoney(string m0);
    void NotfindUser();
    void findUser();
	BOOL Login(string pAccount, string pPassword);
  private:
    bool checking;

};

#endif // BANK_H_INCLUDED
