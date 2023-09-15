#pragma once
class Date
{
private:
	int year, month, day;
public:
	Date();
	Date(int year);
	Date(int year, int month);
	Date(int year, int month, int day);
	void init(int year, int month, int day);
	void print()const;
	int get_year()const;
	int get_month()const;
	int get_day()const;
	void set_year(int year);
	void set_month(int month);
	void set_day(int day);
	bool check_day();
	bool check_month();
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	Date operator + (int days);
	Date operator - (int days);
	Date operator - (Date&b);
	Date& operator +=(int days);
	Date& operator -=(int days);
	bool operator > (Date& b);
	bool operator < (Date& b);
	bool operator >= (Date& b);
	bool operator <= (Date& b);
	bool operator == (Date& b);
	bool operator != (Date& b);
};

