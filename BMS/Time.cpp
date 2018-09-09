#include "Time.h"
#include <time.h>
#include <iostream>
#include "stdafx.h"
using namespace std;


void Time::setnowtime(){
    time_t t = time(0);    //获取时间戳
    char tmp[64];
    strftime(tmp,sizeof(tmp),"%Y/%m/%d %X %A",localtime(&t));  //将时间戳转换成日期
    now_year = (tmp[0]-48)*1000+(tmp[1]-48)*100+(tmp[2]-48)*10+(tmp[3]-48)*1;
    now_month = (tmp[5]-48)*10+(tmp[6]-48)*1;
    now_day = (tmp[8]-48)*10+(tmp[9]-48)*1;
}



int Time::daysTo(const Time &c2){//天数计算所用
	int allmonths[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int number = 0;
	int alldays = 0;
	int i;
	if ( c2.year < year) {

		for (i = c2.year + 1; i < year ; i ++)

			if ((i%400 == 0)||((i%4 == 0) && (i%100!=0)))

				number = number + 1;


			alldays = alldays + (year - c2.year - 1)*365 + number;


			for (i = month; i > 1; i--) {

			alldays = alldays + allmonths[i - 2];
			}

		alldays = alldays + day ;

		for (i = c2.month; i < 12; i ++) {

			alldays = alldays +allmonths[i];


		alldays = alldays +allmonths[c2.month -1] - c2.day;


		if ((c2.year%400 == 0 || (c2.month%4 == 0 && c2.month%100 != 0))&&( c2.month < 2))

			alldays++;

		if((year%400 == 0 || (year%4 == 0 && year%100 != 0))&&( month >2))

			alldays++;

		alldays = -alldays;
		}
	}
	else if ( c2.year > year)
	{
		for (i = year + 1; i < c2.year ; i ++)

			if (i%400 == 0 || (i%4 == 0 && i%100!=0))
				number ++;
			alldays = alldays + (c2.year - year - 1)*365 + number;

			for (i = month; i < 12; i++)

			alldays = alldays + allmonths[i];

		alldays = alldays + allmonths[month - 1] - day ;


		for (i = c2.month; i > 1; i--){

			alldays = alldays +allmonths[i - 2];
		}

		alldays = alldays +allmonths[c2.day - 1] - c2.day;


		if ((year%400 == 0 || (year%4 == 0 && year%100 != 0))&&( month < 2))
			alldays++;
		if((c2.year%400 == 0 || (c2.year%4 == 0 && c2.year%100 != 0))&&( c2.month >2))

			alldays++;
	}
	else {
		if ( c2.month < month) {

		 for ( i = c2.month - 1 ; i < month; i ++ )

			 alldays = alldays + allmonths[i] ;

		 alldays = alldays - c2.day;

		 alldays = alldays - ( allmonths[month - 1] - day) ;

		alldays = -alldays;

		}

		else if ( c2.month > month ) {

		for ( i = month - 1 ; i < c2.month; i ++ )

			alldays = alldays + allmonths[i];

		alldays = alldays - day;

		alldays = alldays - ( allmonths[c2.month  -1 ] - c2.day );
		}

	else

			alldays = c2.day - day;
	}
	return alldays;
}
