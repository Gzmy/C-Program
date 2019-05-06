#include <iostream>
#include <string>
#include <vector>
#include <math.h>

int day_of_week(int year, int month, int day) {
	if(month == 1 || month == 2) {
		month += 12;
		year -= 1;
	}

	int century = year / 100;
	year = year % 100;
	int week = year + (year/4) + (century/4) - 2 * century + 26 * (month + 1)/10 + day - 1;
	week = (week % 7 + 7) % 7;
	if(week == 0) {
		week = 7;
	}

	return week;
}

int day_of_demand(int year, int month, int count, int d_of_week) {
	int week = day_of_week(year, month, 1);
	int day = 1 + (count-1) * 7 + ((7-week) + d_of_week) % 7;
	return day;
}

// 元旦
void new_year_day(int year) {
	std::cout << year << "-01-01" << std::endl;
}

// 马丁路德金
void martin_luther_king_day(int year) {
	std::cout << year << "-02-%02d" << day_of_demand(year, 2, 3, 1) << std::endl;
}

// 总统
void president_day(int year) {
	std::cout << year << "-02-%02d" << day_of_demand(year, 2, 3, 1) << std::endl;
}

// 阵亡将士
void memorial_day(int year) {
	int week = day_of_week(year, 6, 1);
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	std::cout << year << "-05-%02d" << day << std::endl;
}

// 国庆
void independence_day(int year) {
	std::cout << year << "-07-04" << std::endl;
}

// 劳动节
void labor_day(int year) {
	std::cout << year << "-09-%02d" << day_of_demand(year, 9, 1, 1) << std::endl;
}

// 感恩节
void thanks_giving_day(int year) {
	std::cout << year << "-11-%02d" << day_of_demand(year, 11, 4, 4) << std::endl;
}

// 圣诞节
void christmas(int year) {
	std::cout << year << "-12-25" << std::endl;
}

void holiday_of_usa(int year) {
	new_year_day(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas(year);
}

void americanHoliday() {
	int year;
	while(std::cin >> year) {
		holiday_of_usa(year);
		std::cout << std::endl;
	}
}
	
void separFactor() {
	unsigned int n;
	while(std::cin >> n) {
		for(unsigned int i = 2; i <= sqrt(n); i++) {
			while(n != i && n % i == 0) {
				std::cout << i;
				n /= i;
			}
		}
	}
}

int main()
{
	americanHoliday();
	return 0;
}
