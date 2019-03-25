#include "l180929 Date.h"
#include <iostream>
#include <string>
using namespace std;

//Static array initialization
string Date::monthNames[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//Default constructor
Date::Date(){
	day=1;
	month=1;
	year=2000;
}

//Overloaded constructor
Date::Date(int y, int x, int z){
	if(x>=1 && x<=30)
		day=x;
	else{
		day=1;
		month=1;
		year=2000;
	}
	if(y>=1 && y<=12)
		month=y;
	else{
		day=1;
		month=1;
		year=2000;
	}
	if(z>=1000 && z<=9999)
		year=z;
	else{
		day=1;
		month=1;
		year=2000;
	}
}

//Destructor
Date::~Date(){
	day=1;
	month=1;
	year=2000;
}

//Insertion operator overloading
ostream& operator<<(ostream& out, const Date& x){
	out<< x.monthNames[x.month];
	out<<" "<<x.day<<",";
	out<<x.year;
	return out;
}

//Extraction operator overloading
istream& operator>>(istream& in, Date& x){
	char t;
	in>>x.day;
	in>>t;
	in>>x.month;
	in>>t;
	in>>x.year;
	return in;
}

//equality check operator overload
bool Date::operator==(const Date& x){
	if(day==x.day && month==x.month && year==x.year)
		return true;
	else 
		return false;
}

//Assignment operator overloading
const Date& Date::operator=(const Date& x){
	day=x.day;
	month=x.month;
	year=x.year;
	return *this;
}

//Days increment operator
Date Date::operator+(const int& days){
	for(int i=1; i<=days; i++){
		day++;
		if(day==31){
			day=1;
			month++;
		}
		if(month==13){
			month=1;
			year++;
		}
	}
	return *this;
}

//pre decrement operator
Date& Date::operator--(){
	day--;
	if(day<1){
		day=30;
		month--;
	}
	if(month<1){
		month=12;
		year--;
	}
	return *this;
}

//post decrement operator
Date Date::operator--(int u){
	Date temp=*this;
	day--;
	if(day<1){
		day=30;
		month--;
	}
	if(month<1){
		month=12;
		year--;
	}
	return temp;
}

//Deferencing operator overloading
int Date::operator[](const int& index){
	if(index>=0 && index <= 2){
		if(index==0)
			return day;
		else if(index==1)
			return month;
		else if(index==2)
			return year;
	}
	else{
		cout<<"Index can only be 0, 1 or 2."<<endl;
		return 0;
	}
}
