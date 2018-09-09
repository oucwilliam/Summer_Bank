#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
class Time{
  public:
    Time(int year, int month, int day):year(year),month(month),day(day){}
    Time(){}
    int daysTo(const Time &c2);

    void setyear(int year){this->year = year;}
    int getyear(){return year;}
    void setmonth(int month){this->month = month;}
    int getmonth(){return month;}
    void setday(int day){this->day=day;}
    int getday(){return day;}
    // void setnowtimeA();
    void setnowtime();
    int get_Now_Time_year(){return now_year;}
    int get_Now_Time_day(){return now_day;}
    int get_Now_Time_month(){return now_month;}



    ~Time(){}
  private:
    int year;
    int month;
    int day;
    int now_year;
    int now_day;
    int now_month;



};


#endif // TIME_H_INCLUDED
