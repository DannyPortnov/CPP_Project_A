#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "Queue.h"

enum algorithm
{
	shortest,	// by default == 0
	longest,	// by default == 1
	fastest,	// by default == 2
	random		// by default == 3
};

class Simulator {
friend int random_func(int min, int max);
friend int extract_queues_number(string q_structure);
friend int extract_queues_capacity(string q_structure);


private:
	const int m_num_of_queues; // number of queues in simulation
	int m_q_capacity;
	const int m_interval;
	const algorithm m_algorithm;
	Queue** m_simulator;		// simulator is an array of queues
	//void extract_queues_capacity(string q_structure);
	int m_start_simulation = 0;

public:
	Simulator(string queue_structure, algorithm algo);
	Simulator(int number_of_queues, int interval, algorithm algo);
	~Simulator();		// destructor
	Simulator& construct_array_cells(string queue_structure);
	bool start_simulation(int run_time_length);


};


//int extract_queues_number(string q_structure);
//int extract_queues_capacity(string q_structure);


#endif		// _SIMULATOR_H_