#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "Queue.h"

class Simulator {
friend int random(int min, int max);
private:
	const int m_num_of_queues;
	const int m_interval;
	const enum algorithm
	{
		shortest,	// by default == 0
		longest,	// by default == 1
		fastest,	// by default == 2
		random		// by default == 3
	};
	int m_start_simulation = 0;

public:
	bool start_simulation(int run_time_length);
	///*Queue(char* m_queue, char* m_head, char* m_tail);*/
	//Queue(int capacity);
	//Queue(const Queue&);
	//~Queue();		// deconstructor
	//void push(char new_client); //plain char as of right now, consider support for const/&/* etc...
	//void pop();
	//bool is_queue_full();
	//bool is_queue_empty();
	//const char front();
	//int size();

};



#endif		// _SIMULATOR_H_