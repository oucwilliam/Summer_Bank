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
        //cout<<"请输入ID"<<endl;
        cin>>checked_ID;
        string filename = "Account\\"+getAccount()+"\\power.txt";
        const char* p = filename.data();
        if(checked_ID==getID()){
             if(!remove( p)){
                //cout<<"挂失成功"<<endl;
             }
        }
        else{
           // cout<<"您不是本人，请本人前来"<<endl;
        }
     }
}*/
/*void Bank::findUser(){
     if(Check_ID(0)){
        string checked_ID;
        string new_pwd;
        cout<<"请输入ID"<<endl;
        cin>>checked_ID;
        string filename = "Account\\"+getAccount()+"\\power.txt";
        ofstream File;
        File.open(filename);
        if(checked_ID==getID()){
                cout<<"解除挂失成功"<<endl;
        }
        else{
            cout<<"您不是本人，请本人前来"<<endl;
        }
        File.close();
     }
}*/
/*bool  Bank::Check_ID(bool sit){
    string infile_Account,infile_password,Account1,password,file_power;
    int Again0=1;
   // cout<<"s"<<endl;
    cout << "请输入账号" << endl;
    cin >> Account1;
    if(sit){
       cout << "请输入密码" << endl;
       cin >> password;
    }
    infile_Account = "Account\\"+Account1+"\\"+Account1+".txt";
    ifstream Account;
    Account.open(infile_Account,ios::in);
    if (!Account){
		cout << "输入的账号不存在." << endl;
		return 0;
	}
	else if(sit){
        setAccount(Account1);
        Account.close();
            file_power="Account\\"+Account1+"\\power.txt";
            Account.open(file_power);
            if(!Account){
                cout<<"账户已被冻结"<<endl;
                Account.close();
                return 0;
            }
        psdjudge:
            infile_password =  "Account\\"+Account1+"\\"+password+".txt";//构造路径，在account这个大的文件夹的下面有以账户命名的子文件夹
            Account.open(infile_password,ios::in);
            if (!Account){//也就是打开这个文件的路径是不存在的，也就是这个输入的账户是不存在的
                cout << "输入的密码错误." << endl;
                Account.close();
                if(++Again0<=3){
                     goto Again;
                }
                else {
                    cout<<"三次输入错误，今天的机会用完，请明天再来"<<endl;
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
	    cout<<"请再次输入密码"<<endl;
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

    cout << "您一共有"<<toa+1<<"笔存款";
    cout << "存款的总金额是"<<getMoney_self()+getinterest()<<endl;
    cout << "目前账户拥有存款单如下:"<<endl;
    for(int l = 0;l<=toa;l++){
        cout << Md[l] <<endl;
    }
    cout<<"请选择将要操作的取款单"<<endl;

   Sr:
    cin>>mm;
    for(int l = 0;l<=toa;l++){
       if(Md[l]==mm){
        judge = 0;
        break;
       }
    }
    if(judge){
        cout<<"输入的流水单号不存在，请重新输入"<<endl;
        judge=0;
        goto Sr;
       }

    stringstream stream;
    stream << mm; //将int输入流
    stream >> m0; //从stream中抽取前面插入的int

    cout<<"存款单"<<mm<<"拥有的存款总额为: "<<getmdMoney(m0);
	cout << "请输入取款金额"<<endl;
	cin >>i;

	cout << "你的取款金额为"<<i<<"元。"<<"请确认取款金额(请输入1)。"<<endl;
	cin >> j;



	if ( j == 1 &&money - i>=0) {
        money = money - i;
		cout << "交易正在处理,交易成功。"<<endl;

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
        cout<<"超出了此存款单的余额上限，请输入正确的金额"<<endl;
    }
    else {cout << "交易金额未确认，交易失败。"<<endl;}
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
    stream << money; //将int输入流
    stream >> mm; //从stream中抽取前面插入的int*/
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
        //File2<<"\n操作员：admin  操作金额："<<k<<" 操作时间: "<<get_Now_Time_year();
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
        //File2<<"  操作金额："<<k;
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
     Information_A>>interest;//这里一定要按数据储存的次序来；下面给类中的数据赋值的就不需要了；
     Information_A.close();
     return money_self+interest;


}*/




/*
void Bank::Input() {
	int i;
	int j;
	double money =getMoney_self();

	cout << "请将存款放入存钞口"<<endl;
	cin >>i;

	cout << "你的存款金额为"<<i<<"元。"<<"请确认存款金额(请输入1)。"<<endl;
	cin >> j;

	if ( j == 1) {

		cout << "交易正在处理,交易成功。"<<endl;
		money = money + i;
		setMoney_self(money);
	}

	else
		cout << "交易金额未确认，交易失败。"<<endl;

}


double Bank::interest_cout() {

	double Interest;
	double Money_Self;

	Time nowtime(2018,9,4);
	Time Inputtime(1999,10,1);

	int day = Inputtime.daysTo(nowtime);
	Money_Self = getMoney_self();

	if (getKind() == 1) //三个月定期存款
		Interest = Interest_costing(Money_Self,day,0.011,90);

	else if(getKind() == 2) //半年定期存款
		Interest = Interest_costing(Money_Self,day,0.013,180);

	else if(getKind() == 3) //一年定期存款
       	Interest = Interest_costing(Money_Self,day,0.015,365);

	else if(getKind() ==4) //两年定期存款
		Interest = Interest_costing(Money_Self,day,0.021,730);

	else if(getKind() == 5) //三年定期存款
		Interest = Interest_costing(Money_Self,day,0.0275,1095);

	else if(getKind() == 6){ //活期存款
	   Interest = Money_Self;
	   int i;

	   for ( i = 1; i <= (day - 90); i ++)
	       Interest = 1.0035 * Interest;

	   Interest = Interest - Money_Self;
	   }

	return Interest;
}



double Bank::Interest_costing(double Money_Self, int days, double fax, int kind){ // Money_Self--本金  days--存款天数  fax--利率  kind--定期时长

	double Interest;

	if (days >= kind) {
 	   Interest = (1 + fax) * Money_Self;//定期利息加本金

	   if( day > kind){ // 计算剩下活期利息
		  int i;
    	  for ( i = 1; i <= (day - kind); i ++)
			  Interest = 1.0035 * Interest;}
		}

	else { //未到期取款的利息加本金

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
	//这是一个创建文件夹的操作，需要的头文件是windows.h同样的dirname是文件夹的路径，但是用户输入的dirname就是文件夹的名字
