#include <iostream>
#include <sstream>
#include <cstdio>
#include "stdafx.h"
#include "Bank.h"
using namespace std;

/*void Bank::NotfindUser(){
	if(Check_ID(0)){
        string checked_ID;
        string new_pwd;
        //cout<<"������ID"<<endl;
        cin>>checked_ID;
        string filename = "Account\\"+getAccount()+"\\power.txt";
        const char* p = filename.data();
        if(checked_ID==getID()){
             if(!remove( p)){
                //cout<<"��ʧ�ɹ�"<<endl;
             }
        }
        else{
           // cout<<"�����Ǳ��ˣ��뱾��ǰ��"<<endl;
        }
     }
}*/
/*void Bank::findUser(){
     if(Check_ID(0)){
        string checked_ID;
        string new_pwd;
        cout<<"������ID"<<endl;
        cin>>checked_ID;
        string filename = "Account\\"+getAccount()+"\\power.txt";
        ofstream File;
        File.open(filename);
        if(checked_ID==getID()){
                cout<<"�����ʧ�ɹ�"<<endl;
        }
        else{
            cout<<"�����Ǳ��ˣ��뱾��ǰ��"<<endl;
        }
        File.close();
     }
}*/
/*bool  Bank::Check_ID(bool sit){
    string infile_Account,infile_password,Account1,password,file_power;
    int Again0=1;
   // cout<<"s"<<endl;
    cout << "�������˺�" << endl;
    cin >> Account1;
    if(sit){
       cout << "����������" << endl;
       cin >> password;
    }
    infile_Account = "Account\\"+Account1+"\\"+Account1+".txt";
    ifstream Account;
    Account.open(infile_Account,ios::in);
    if (!Account){
		cout << "������˺Ų�����." << endl;
		return 0;
	}
	else if(sit){
        setAccount(Account1);
        Account.close();
            file_power="Account\\"+Account1+"\\power.txt";
            Account.open(file_power);
            if(!Account){
                cout<<"�˻��ѱ�����"<<endl;
                Account.close();
                return 0;
            }
        psdjudge:
            infile_password =  "Account\\"+Account1+"\\"+password+".txt";//����·������account�������ļ��е����������˻����������ļ���
            Account.open(infile_password,ios::in);
            if (!Account){//Ҳ���Ǵ�����ļ���·���ǲ����ڵģ�Ҳ�������������˻��ǲ����ڵ�
                cout << "������������." << endl;
                Account.close();
                if(++Again0<=3){
                     goto Again;
                }
                else {
                    cout<<"����������󣬽���Ļ������꣬����������"<<endl;
                }
                return 0;
            }
            else{
              setPword(password);
              ShowInformation();
	          return 1;
            }

	}

	else{
            setAccount(Account1);
            Account.close();
            ShowInformation();
            return 1;
     }
	Again:
	    cout<<"���ٴ���������"<<endl;
	    cin >> password;
	    goto psdjudge;
 };*/



/*void Bank::Output(){

    double i;
	int j;
	int p=0;
	bool judge=1;
	string pas[3];
    string m0;
    int mm;
	double money =getMoney_self();

    cout << "��һ����"<<toa+1<<"�ʴ��";
    cout << "�����ܽ����"<<getMoney_self()+getinterest()<<endl;
    cout << "Ŀǰ�˻�ӵ�д�����:"<<endl;
    for(int l = 0;l<=toa;l++){
        cout << Md[l] <<endl;
    }
    cout<<"��ѡ��Ҫ������ȡ�"<<endl;

   Sr:
    cin>>mm;
    for(int l = 0;l<=toa;l++){
       if(Md[l]==mm){
        judge = 0;
        break;
       }
    }
    if(judge){
        cout<<"�������ˮ���Ų����ڣ�����������"<<endl;
        judge=0;
        goto Sr;
       }

    stringstream stream;
    stream << mm; //��int������
    stream >> m0; //��stream�г�ȡǰ������int

    cout<<"��"<<mm<<"ӵ�еĴ���ܶ�Ϊ: "<<getmdMoney(m0);
	cout << "������ȡ����"<<endl;
	cin >>i;

	cout << "���ȡ����Ϊ"<<i<<"Ԫ��"<<"��ȷ��ȡ����(������1)��"<<endl;
	cin >> j;



	if ( j == 1 &&money - i>=0) {
        money = money - i;
		cout << "�������ڴ���,���׳ɹ���"<<endl;

		setMoney_self(money);
        pas[0]= "\\"+getAccount()+".txt";
        pas[1]="\\"+getPword()+".txt";
        pas[2]="\\MD\\" + m0 + ".txt";
        //cout<<pas[2];
        change(2,pas[0],money,0,i);
        change(4,pas[1],money,1,i);
        change(3,pas[2],money,2,i);

	}
	else if(money - i<0){
        cout<<"�����˴˴���������ޣ���������ȷ�Ľ��"<<endl;
    }
    else {cout << "���׽��δȷ�ϣ�����ʧ�ܡ�"<<endl;}
}*/

BOOL Bank::Login(string Account1, string password)
{
	string infile_Account, infile_password;
	infile_Account = "Account\\" + Account1 + "\\" + Account1 + ".txt";
	ifstream Account;
	Account.open(infile_Account, ios::in);
	if (!Account) {
		Account.close();
		return 0;
	}
	else {
		ShowInformation();	
		if (password != getPword()) {
			Account.close();
			return 0;
		}
		else {
			Account.close();
			return 1;
		}

	}
};

void  Bank::change(int i,string road,double money,int judge,double k){

    ifstream File;
    string pas;
    string mm;
    string ko[100];
    int p=0;
    pas = "Account\\"+getAccount() + road;
    File.open(pas,ios::in);
    while(File>>mm){
      ko[p] = mm;
      p++;
    }
    /*stringstream stream;
    stream << money; //��int������
    stream >> mm; //��stream�г�ȡǰ������int*/
	mm = to_string(money);
    ko[i] = mm;
    File.close();
    ofstream File2;
    File2.open(pas);
    for(int h=0;h<p;h++){
        File2<<ko[h];
        File2<<" ";
    }
    //setnowtime();
    if(judge == 2){
        //File2<<"\n����Ա��admin  ������"<<k<<" ����ʱ��: "<<get_Now_Time_year();
        if(get_Now_Time_month()<10){
            File2<<"0"<<get_Now_Time_month();
        }
        else{
            File2<<"0"<<get_Now_Time_month();
        }
        if(get_Now_Time_day()<10){
            File2<<"0"<<get_Now_Time_day();
        }
        else{
            File2<<get_Now_Time_day();
        }
        //File2<<"  ������"<<k;
    }
    File2.close();
}





/*double Bank::getmdMoney(string m0){
     ifstream Information_A;
     string file_pass,acc,time_on;
     double interest;
     double money_self;
     int kind,time_day,time_month,time_year;
     file_pass =  "Account\\"+getAccount()+"\\MD\\" + m0 + ".txt";
     Information_A.open(file_pass,ios::in);
     Information_A>>acc;
     Information_A>>time_on;
     Information_A>>kind;
     Information_A>>money_self;
     Information_A>>interest;//����һ��Ҫ�����ݴ���Ĵ���������������е����ݸ�ֵ�ľͲ���Ҫ�ˣ�
     Information_A.close();
     return money_self+interest;


}*/




/*
void Bank::Input() {
	int i;
	int j;
	double money =getMoney_self();

	cout << "�뽫������泮��"<<endl;
	cin >>i;

	cout << "��Ĵ����Ϊ"<<i<<"Ԫ��"<<"��ȷ�ϴ����(������1)��"<<endl;
	cin >> j;

	if ( j == 1) {

		cout << "�������ڴ���,���׳ɹ���"<<endl;
		money = money + i;
		setMoney_self(money);
	}

	else
		cout << "���׽��δȷ�ϣ�����ʧ�ܡ�"<<endl;

}


double Bank::interest_cout() {

	double Interest;
	double Money_Self;

	Time nowtime(2018,9,4);
	Time Inputtime(1999,10,1);

	int day = Inputtime.daysTo(nowtime);
	Money_Self = getMoney_self();

	if (getKind() == 1) //�����¶��ڴ��
		Interest = Interest_costing(Money_Self,day,0.011,90);

	else if(getKind() == 2) //���궨�ڴ��
		Interest = Interest_costing(Money_Self,day,0.013,180);

	else if(getKind() == 3) //һ�궨�ڴ��
       	Interest = Interest_costing(Money_Self,day,0.015,365);

	else if(getKind() ==4) //���궨�ڴ��
		Interest = Interest_costing(Money_Self,day,0.021,730);

	else if(getKind() == 5) //���궨�ڴ��
		Interest = Interest_costing(Money_Self,day,0.0275,1095);

	else if(getKind() == 6){ //���ڴ��
	   Interest = Money_Self;
	   int i;

	   for ( i = 1; i <= (day - 90); i ++)
	       Interest = 1.0035 * Interest;

	   Interest = Interest - Money_Self;
	   }

	return Interest;
}



double Bank::Interest_costing(double Money_Self, int days, double fax, int kind){ // Money_Self--����  days--�������  fax--����  kind--����ʱ��

	double Interest;

	if (days >= kind) {
 	   Interest = (1 + fax) * Money_Self;//������Ϣ�ӱ���

	   if( day > kind){ // ����ʣ�»�����Ϣ
		  int i;
    	  for ( i = 1; i <= (day - kind); i ++)
			  Interest = 1.0035 * Interest;}
		}

	else { //δ����ȡ�����Ϣ�ӱ���

	   Interest = Money_Self;
	   int i;

	   for ( i = 1; i <= (day - 90); i ++)
	       Interest = 1.0035 * Interest;
	}

	Interest = Interest - Money_Self;

	return Interest;
}
*/
 /*infile_password = ""
	else{
        cout << "ok" << endl;
        cin >> dirName;
        dirName = "Account\\"+dirName;
        bool flag = CreateDirectory(dirName.c_str(), NULL);
        if(flag){
            cout<<"wudi"<<endl;
        }
        return 1;*/
	//����һ�������ļ��еĲ�������Ҫ��ͷ�ļ���windows.hͬ����dirname���ļ��е�·���������û������dirname�����ļ��е�����
