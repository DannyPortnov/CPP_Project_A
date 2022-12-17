#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "Queue.h"
#define number_of_algorithms 4

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
	static const string const m_algorithm_to_string[number_of_algorithms];
	const int m_num_of_queues; // number of queues in simulation
	const int m_interval;
	const algorithm m_algorithm;
	Queue** m_simulator;		// simulator is an array of queues
<<<<<<< HEAD
	//void extract_queues_capacity(string q_structure);
	unsigned m_clients_left = 0;
	unsigned m_max_clients;
	unsigned m_current_amount_of_clients= 0;
=======
	int m_q_capacity;
	int m_clients_left = 0;
	int m_max_clients = 0;
	int m_current_amount_of_clients= 0;
>>>>>>> f09517c3fc3f8fe44ea01f7dc1968de0718a0137
public:
	Simulator(int number_of_queues, int interval, algorithm algo);
	Simulator(string queue_structure, int interval, algorithm algo);
	~Simulator();		// destructor
	Simulator& initialize_array_cells(string queue_structure);

	bool routing_clients(char client);
	bool are_all_queues_full();
	void start_simulation(int run_time_length);

<<<<<<< HEAD
	unsigned get_max_clients() const;
	unsigned get_clients_left() const;
	static string get_algorithm_name(algorithm algo);
=======
>>>>>>> f09517c3fc3f8fe44ea01f7dc1968de0718a0137
};

int extract_queues_number(string q_structure);
int extract_queues_capacity(string q_structure);

#endif		// _SIMULATOR_H_