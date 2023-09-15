#include "Date.h"
#include <iostream>
using namespace std;
Date::Date()
{
	this->year = this->month = this->day = 0;
}
bool Date::check_day()
{
	if (this->day < 1 || this->day>31)
		return false;
	if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
	{
		if (this->day > 30)
			return false;
	}
	else if (this->month == 2)
	{
		if (this->day > 28)
			return false;
	}
	return true;
}
bool Date::check_month()
{
	if (this->month < 1 || this->month>12)
		return false;
	return true;
}
Date::Date(int year)
{
	this->year = year;
}
Date::Date(int year, int month) :Date(year)
{
	this->month = month;
	if (check_month() == 0)
	{
		cout << "Your month isn`t correct" << endl;
		Date();
	}
}
Date::Date(int year, int month, int day) :Date(year,month)
{
	this->day = day;
	if (check_day() == 0)
	{
		cout << "Your day isn`t correct" << endl;
		Date();
	}
}
void Date::init(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	if (check_month() == 0)
	{
		cout << "Your month isn`t correct" << endl;
		Date();
	}
	this->day = day;
	if (check_day() == 0)
	{
		cout << "Your day isn`t correct" << endl;
		Date();
	}
}
void Date:: print()const
{
	cout << "Year: " << this->year << endl;
	cout << "Month: " << this->month << endl;
	cout << "Day: " << this->day << endl;
}
int Date:: get_year()const
{
	return this->year;
}
int Date:: get_month()const
{
	return this->month;
}
int Date:: get_day()const
{
	return this->day;
}
void Date:: set_year(int year)
{
	this->year = year;
}
void Date::set_month(int month)
{
	this->month = month;
	if (!(check_month()))
	{
		cout << "Error. Your month isn`t correct" << endl;
		this->month = 0;
	}
}
void Date::set_day(int day)
{
	this->day = day;
	if (!(check_day()))
	{
		cout << "Error. Your day isn`t correct" << endl;
		this->day = 0;
	}
}
Date& Date:: operator++()
{
	this->day += 1;
	if (this->day > 31 && (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12))
	{
		this->day = 1;
		if (this->month == 12)
		{
			this->month = 1;
			this->year++;
		}
		else
			this->month += 1;
	}
	else if (this->day > 30 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 1))
	{
		this->day = 1;
		this->month++;
	}
	else if(this->day>28&&this->month==2)
	{
		this->day = 1;
		this->month++;
	}
	return *this;
}
Date Date:: operator++(int)
{
	Date tmp(this->year, this->month, this->day);
	this->day += 1;
	if (this->day > 31 && (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12))
	{
		this->day = 1;
		if (this->month == 12)
		{
			this->month = 1;
			this->year++;
		}
		else
			this->month += 1;
	}
	else if (this->day > 30 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 1))
	{
		this->day = 1;
		this->month++;
	}
	else if (this->day > 28 && this->month == 2)
	{
		this->day = 1;
		this->month++;
	}
	return tmp;
}
Date& Date::operator--()
{
	this->day--;
	if (this->day < 1 && ( this->month == 5 || this->month == 7  || this->month == 10))
	{
		this->month--;
		this->day=30;
	}
	else if (this->day < 1 && this->month == 1)
	{
		this->month = 12;
		this->year--;
		this->day = 31;
	}
	else if (this->day < 1 && this->month == 3)
	{
		this->month--;
		this->day = 28;
	}
	else if (this->day < 1 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11||this->month==2))
	{
		this->month--;
		this->day=31;
	}
	else if (this->day < 1 && this->month == 12)
	{
		this->month = 1;
		this->day = 31;
		this->year--;
	}
	return *this;
}
Date Date::operator--(int)
{
	Date tmp(this->year, this->month, this->day);
	this->day--;
	if (this->day < 1 && (this->month == 5 || this->month == 7 || this->month == 10))
	{
		this->month--;
		this->day = 30;
	}
	else if (this->day < 1 && this->month == 1)
	{
		this->month = 12;
		this->year--;
		this->day = 31;
	}
	else if (this->day < 1 && this->month == 3)
	{
		this->month--;
		this->day = 28;
	}
	else if (this->day < 1 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11||this->month ==2))
	{
		this->month--;
		this->day = 31;
	}
	else if (this->day < 1 && this->month == 12)
	{
		this->month = 1;
		this->day = 31;
		this->year--;
	}
	return tmp;
}
Date Date:: operator + (int days)
{
	Date newObj(this->year, this->month, this->day);
	for (int i = days; i>0; --i)
	{
		newObj.day++;
		if (newObj.day > 31 && (newObj.month == 1 || newObj.month == 3 || newObj.month == 5 || newObj.month == 7 || newObj.month == 8 || newObj.month == 10 || newObj.month == 12))
		{
			newObj.day = 1;
			if (newObj.month == 12)
			{
				newObj.month = 1;
				newObj.year++;
			}
			else
				newObj.month += 1;
		}
		else if (newObj.day > 30 && (newObj.month == 4 || newObj.month == 6 || newObj.month == 9 || newObj.month == 1))
		{
			newObj.day = 1;
			newObj.month++;
		}
		else if (newObj.day > 28 && newObj.month == 2)
		{
			newObj.day = 1;
			newObj.month++;
		}
	}
	return newObj;
}
Date Date:: operator - (int days)
{
	Date newObj(this->year,this->month,this->day);
	for (int i = days; i > 0; i--)
	{
		newObj.day--;
		if (newObj.day < 1 && (newObj.month == 5 || newObj.month == 7 || newObj.month == 10))
		{
			newObj.month--;
			newObj.day = 30;
		}
		else if (newObj.day < 1 && newObj.month == 1)
		{
			newObj.month = 12;
			newObj.year--;
			newObj.day = 31;
		}
		else if (newObj.day < 1 && newObj.month == 3)
		{
			newObj.month--;
			newObj.day = 28;
		}
		else if (newObj.day < 1 && (newObj.month == 4 || newObj.month == 6 || newObj.month == 9 || newObj.month == 11||newObj.month==2))
		{
			newObj.month--;
			newObj.day = 31;
		}
		else if (newObj.day < 1 && newObj.month == 12)
		{
			newObj.month = 1;
			newObj.day = 31;
			newObj.year--;
		}
	}
	return newObj;
}
Date Date:: operator - (Date& b)
{
	Date newObj(this->year, this->month, this->day);
	for (int i = b.day; i > 0; i--)
	{
		newObj.day--;
		if (newObj.day < 1 && (newObj.month == 5 || newObj.month == 7 || newObj.month == 10))
		{
			newObj.month--;
			newObj.day = 30;
		}
		else if (newObj.day < 1 && newObj.month == 1)
		{
			newObj.month = 12;
			newObj.year--;
			newObj.day = 31;
		}
		else if (newObj.day < 1 && newObj.month == 3)
		{
			newObj.month--;
			newObj.day = 28;
		}
		else if (newObj.day < 1 && (newObj.month == 4 || newObj.month == 6 || newObj.month == 9 || newObj.month == 11||this->month ==2))
		{
			newObj.month--;
			newObj.day = 31;
		}
		else if (newObj.day < 1 && newObj.month == 12)
		{
			newObj.month = 1;
			newObj.day = 31;
			newObj.year--;
		}
	}
	return newObj;
}
Date& Date:: operator +=(int days)
{
	for (int i = days; i > 0; --i)
	{
		this->day++;
		if (this->day > 31 && (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12))
		{
			this->day = 1;
			if (this->month == 12)
			{
				this->month = 1;
				this->year++;
			}
			else
				this->month += 1;
		}
		else if (this->day > 30 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 1))
		{
			this->day = 1;
			this->month++;
		}
		else if (this->day > 28 && this->month == 2)
		{
			this->day = 1;
			this->month++;
		}
	}
	return *this;
}
Date& Date:: operator -=(int days)
{
	for (int i = days; i > 0; i--)
	{
		this->day--;
		if (this->day < 1 && (this->month == 5 || this->month == 7 || this->month == 10))
		{
			this->month--;
			this->day = 30;
		}
		else if (this->day < 1 && this->month == 1)
		{
			this->month = 12;
			this->year--;
			this->day = 31;
		}
		else if (this->day < 1 && this->month == 3)
		{
			this->month--;
			this->day = 28;
		}
		else if (this->day < 1 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11||this->month))
		{
			this->month--;
			this->day = 31;
		}
		else if (this->day < 1 && this->month == 12)
		{
			this->month = 1;
			this->day = 31;
			this->year--;
		}
	}
	return *this;
}
bool Date:: operator > (Date& b)
{
	if (this->year > b.year)
		return true;
	else if (this->year == b.year && this->month > b.month)
		return true;
	else if (this->year == b.year && this->month == b.month && this->day > b.day)
		return true;
	return false;
}
bool Date:: operator < (Date& b)
{
	if (this->year < b.year)
		return true;
	else if (this->year == b.year && this->month < b.month)
		return true;
	else if (this->year == b.year && this->month == b.month && this->day < b.day)
		return true;
	return false;
}
bool Date:: operator >= (Date& b)
{
	if (this->year > b.year)
		return true;
	else if (this->year == b.year && this->month > b.month)
		return true;
	else if (this->year == b.year && this->month == b.month && this->day >= b.day)
		return true;
	return false;
}
bool Date:: operator <= (Date& b)
{
	if (this->year < b.year)
		return true;
	else if (this->year == b.year && this->month < b.month)
		return true;
	else if (this->year == b.year && this->month == b.month && this->day <= b.day)
		return true;
	return false;
}
bool Date:: operator == (Date& b)
{
	if (this->year == b.year && this->month == b.month && this->day == b.day)
		return true;
	return false;
}
bool Date:: operator != (Date& b)
{
	if (!(this->year == b.year && this->month == b.month && this->day == b.day))
		return true;
	return false;
}






