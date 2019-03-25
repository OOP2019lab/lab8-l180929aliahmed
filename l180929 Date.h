#include <iostream>
#include <string>
using namespace std;


class Date{
private:
	static string monthNames[13];
	int day;
	int month;
	int year;

public:
	Date(int,int,int);
	Date();
	~Date();
	friend ostream& operator<<(ostream& out, const Date& x);
	friend istream& operator>>(istream& in, Date& x);
	bool operator==(const Date&);
	const Date& operator=(const Date& x);
	Date operator+(const int& );
	Date& operator--(); //pre decrement
	Date operator--(int); //post decrement
	int operator[](const int&);
};
