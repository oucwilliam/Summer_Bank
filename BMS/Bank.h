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
    //void Ar_User();	//�����û���Ϣ
    //void Ar_Saver();	//������Ա��Ϣ
    bool Check_ID(bool sit);	//��֤���
    void Output();	//ȡ��
    //void Input();	//���
    //void Lost_C();	//����
    void Set_New_user();
    double interest_cout();	//������Ϣ
    void Foot();	//ҵ������¼
    void Out_Show();//����ȡ��Ľ��棻
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
