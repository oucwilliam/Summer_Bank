#ifndef SAVER_H_INCLUDED
#define SAVER_H_INCLUDED
using namespace std;
class Saver {
   public:
     string getS_Name(){return S_Name;}
     void setS_Name(string S_Name){this->S_Name=S_Name;}
     string getG_num(){return G_num;}
     void setG_num(string G_num){this->G_num=G_num;}
   private:
     string S_Name;	//ÐÕÃû
     string G_num;	//¹¤ºÅ
};

#endif // SAVER_H_INCLUDED
