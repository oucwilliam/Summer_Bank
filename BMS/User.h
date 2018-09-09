#pragma once
#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "Time.h"
#include "stdafx.h"
#include<string>
using namespace std;
class User:public Time {
   public:
    int *Md=0;
    int toa;
	User();
    string getAccount(){return Account;}
    void setAccount(string Account){this->Account=Account;}
    string getName(){return Name;}
    void setName(string Name){this->Name=Name;}
    string getID(){return ID;}
    void setID(string ID){this->ID=ID;}
    string getPword(){return Pword;}
    void setPword(string Pword){this->Pword=Pword;}
    string getAdd(){return Add;}
    void setAdd(string Add){this->Add=Add;}
    int getKind(){return Kind;}
    void setKind(int kind){this->Kind=kind;}
    double getMoney_self(){return Money_self;}
    void setMoney_self(double Money_self){this->Money_self=Money_self;}
    void setTime_on(string Time_on){this->Time_on = Time_on;}
    string getTime_on(){return Time_on;}
    double getinterest(){return interest;}
    void setinterest(double interest){this->interest=interest;}
    void ShowInformation();
    ~User();
   private:
    string Account;	//�˺�
    string Name;	//����
    string Pword;	//����
    string Add;	//��ַ
    string ID;	//���֤��
    int Kind;	//����
    double Money_self;	//����
    string Time_on;//��������
    int lost;	//�Ƿ��ʧ�ı�׼ //��ʧ����
    double interest;
public:
	CString m_strUser;
	CString m_strPwd;
public:
	void SetUser(CString strUser);
	void SetPwd(CString strPwd);
};

#endif // USER_H_INCLUDED
