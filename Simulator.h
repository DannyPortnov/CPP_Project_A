#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "Queue.h"

class Simulator {
friend int random_func(int min, int max);
friend int extract_queues_number(string q_structure);
friend int extract_queues_capacity(string q_structure);

const enum algorithm
{
	shortest,	// by default == 0
	longest,	// by default == 1
	fastest,	// by default == 2
	random		// by default == 3
};

private:
	//const int m_q_capacity;
	const int m_num_of_queues; // number of queues in simulation
	const int m_interval;
	const algorithm m_algorithm;
	
	//void extract_queues_capacity(string q_structure);
	int m_start_simulation = 0;

public:
	Simulator(string queue_structure, int interval, algorithm algo);
	~Simulator();		// deconstructor
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

int extract_queues_number(string q_structure);
int extract_queues_capacity(string q_structure);


#endif		// _SIMULATOR_H_