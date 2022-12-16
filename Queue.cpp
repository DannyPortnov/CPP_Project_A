#include "Queue.h"

Queue::Queue(char d, char m, int y) //Constructor
{
	init(d, m, y);
}

Queue::Queue(unsigned long n) {
	set_day_month_year(n);
	leap_year = is_leap_year(m_year);
}

Queue::Queue(const Queue& d) {
	init(d.m_day, d.m_month, d.m_year);
}

Queue::Queue() {
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	init(newtime.tm_mday, newtime.tm_mon + 1, newtime.tm_year + 1900);
}

Queue& Queue::init(char d, char m, int y) {
	m_day = d; m_month = m; m_year = y;
	set_day_number(m_day, m_month, m_year);
	leap_year = is_leap_year(m_year);
	return *this;
}

void Queue::show(void) const
{
	cout << (int)m_day << "/" << (int)m_month << "/" << m_year << endl;
}
//
//unsigned Queue::get_day_number(void)const
//{
//	return m_day_number;
//}
///// <summary>
///// set m_day_number according to d/m/y
///// </summary>
///// <param name="d"></param>
///// <param name="m"></param>
///// <param name="y"></param>
//void Queue::set_day_number(char d, char m, int y)
//{
//	m_day_number = 0;
//	for (int i = 0; i < y; i++)
//		m_day_number += NUM_DAYS_YEAR + is_leap_year(i);
//	for (int i = 1; i < m; i++)
//		m_day_number += num_days_month(i, y);
//	m_day_number += d - 1; //was m_day
//}
//
///// <summary>
///// UpQueues the current instance
///// </summary>
//void Queue::set_day_number() {
//	set_day_number(m_day, m_month, m_year);
//}
//
///// <summary>
///// set m_day/m_month/m_year according to m_day_number
///// </summary>
///// <param name="n"></param>
//void Queue::set_day_month_year(unsigned n)
//{
//	m_day_number = n;
//	for (m_year = 0; n >= NUM_DAYS_YEAR; m_year++)
//		n -= NUM_DAYS_YEAR + is_leap_year(m_year);
//	for (m_month = 1; n >= num_days_month(m_month, m_year); m_month++)
//		n -= num_days_month(m_month, m_year);
//	m_day = n + 1;
//}
///// <summary>
///// UpQueues instance
///// </summary>
///// <returns></returns>
//void Queue::set_day_month_year()
//{
//	set_day_month_year(m_day_number);
//}
//
//char Queue::get_day() const {
//	return m_day;
//}
//
//char Queue::get_month() const {
//	return m_month;
//}
//
//int Queue::get_year() const {
//	return m_year;
//}
//
//bool Queue::valiQueue_before_set(char day, char month, int year) {
//	char max_day = days_in_each_month(is_leap_year(year))[month];
//	if (day > max_day) {
//		cout << "Queue's day cannot be greater than " << int(max_day) << endl;
//		return false;
//	}
//	return true;
//}
//
//
//void Queue::set_day(char d) {
//	if (d <= 0 || !valiQueue_before_set(d, m_month, m_year)) {
//		return;
//	}
//	init(d, m_month, m_year); //if reached here, passed all tests so upQueue the object's parameters
//}
//
//void Queue::set_month(char m) {
//	if (m <= 0 || !valiQueue_before_set(m_day, m, m_year)) {
//		return;
//	}
//	init(m_day, m, m_year); //if reached here, passed all tests so upQueue the object's parameters
//}
//
///// <summary>
///// 
///// </summary>
///// <param name="y"></param>
//void Queue::set_year(int y) {
//	if (y < 0 || !valiQueue_before_set(m_day, m_month, y)) {
//		return;
//	}
//	m_year = y;
//}
//
///// <summary>
///// Checks if the given year is leap year
///// </summary>
///// <param name="year"></param>
///// <returns>True if year is leap year, False otherwise</returns>
//bool is_leap_year(int year) {
//	// Return true if year is a multiple
//	// 0f 4 and not multiple of 100.
//	// OR year is multiple of 400.
//	return (year >= 0 && (((year % 4 == 0) && (year % 100 != 0)) ||
//		(year % 400 == 0)));
//}
///// <summary>
///// 
///// </summary>
///// <param name="month"></param>
///// <param name="year"></param>
///// <returns>number of days in month (year is provided to check leap year)</returns>
//int num_days_month(int month, int year) {
//	if (month > 0 && month < 13 && year >= 0) {
//		return days_in_each_month(is_leap_year(year))[month];
//	}
//	cout << month << " or " << year << " aren't invalid number for month or year" << endl;
//	return -1;
//}
///// <summary>
///// Array is shifted to the right by 1, so index 0 is invalid
///// </summary>
///// <returns></returns>
//int* days_in_each_month(bool is_leap_year) { //todo: change to one function
//	int array_of_days[] = { NULL, 31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31,30, 31, 30, 31 };
//	return array_of_days;
//}
//
//
//Queue from_day_number(unsigned long n) {
//	return Queue(n);
//}
//
///// <summary>
///// Adds or subtracts n days from the current Queue
///// </summary>
///// <param name="n"></param>
//void Queue::add(int n) {
//	//todo: fix overflows 
//	int final_day_number = m_day_number + n; //variable is used to avoid underflows
//	if (final_day_number < 0) {
//		cout << "Cannot subtract " << n * -1 << " days" << endl; //mulpiling by -1 because it's always subraction in this case
//		return;
//	}
//	m_day_number += n;
//	set_day_month_year();
//}
///// <summary>
///// Compares the current Queue and the Queue received. 
///// </summary>
///// <param name="d">The Queue to compare with</param>
///// <returns>0 if are the same, a negative value if the received Queue is before current,
///// and a positive value if the current's Queue is before the received</returns>
//int Queue::compare(const Queue& d) const {
//	return d.get_day_number() - m_day_number;
//}

