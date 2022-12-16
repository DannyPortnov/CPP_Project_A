#ifndef _QUEUE_H_
#define _QUEUE_H_

#define   _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <stdbool.h>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

class Queue {

private:
	char* m_queue;	//queue array pointer
	char* m_head;
	char* m_tail;
	const int service_time;
	const int m_capacity;
	static unsigned queue_number;

	Queue& initialize_queue();
public:
	/*Queue(char* m_queue, char* m_head, char* m_tail);*/
	Queue(int capacity);
	Queue(const Queue&);
	~Queue();		// deconstructor



//	friend bool operator==(const Safe_Array& a, const Safe_Array& b);
//	friend ostream& operator<<(ostream& os, const Safe_Array& a); //returns true if the arrays are identical, otherwise false.
//private:
//	int* m_data;
//	unsigned m_capacity;
//	const int m_max_tries;
//	int m_count_max_tries = 0;
//	Safe_Array& init(unsigned capacity, int* array = nullptr);
//	int& failed_to_get_element(int index) const;//if [] operator has invalid index, returns -1 as the value requested.
//	// also checks if requested the value more than allowed, and if so prints a message.
//	void destroy_safe_array(); //frees m_data array and updates score
//	static unsigned score;
//public:
//	Safe_Array(unsigned capacity = 0, const unsigned max_tries = 0);
//	Safe_Array(const Safe_Array&);
//	~Safe_Array();		// deconstructor
//	void show(void) const;	// print array
//
//	unsigned get_capacity() const;	//return the size of the array
//	static unsigned get_score();
//	bool insert(int value, unsigned index);	// inserts a value to a place in the array
//	// check if index is valid, if valid return true, else return false
//	bool get(unsigned index, int& value) const; // return the value of the array index that was sent,
//	// check if index is valid, if valid return true, else return false
//	bool search(int value, unsigned& index) const; // search for value in array, if exist return true, else return false
//	Safe_Array& assign(const Safe_Array&); // assign one object to another
//	void resize(unsigned size); // change array's size, if new size is bigger then the old one- add zeros, if smaller: cut last numbers
//	Safe_Array& operator=(const Safe_Array& otherArr);
//	int& operator[](int index);// returns the value of the array index that was sent,
//	// check if index is valid, if valid return the value, else return -1 and counts failed attempts 
//	int operator[](int index) const; //same as the above but for const instances only
//	//doesn't count failed attempts
//
//	Safe_Array sub(int index1, int index2);
};


//ostream& operator<<(ostream& os, const Safe_Array& arr);
//bool operator==(const Safe_Array& a, const Safe_Array& b); //returns true if the arrays are identical, otherwise false.
//int min(int a, int b);
//int max(int a, int b);
//int abs(int a, int b);

#endif		// _SAFEARRAY_H_