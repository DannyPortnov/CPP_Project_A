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

private:
	const int m_num_of_queues; // number of queues in simulation
	const int m_interval;
	const algorithm m_algorithm;
	Queue** m_simulator;		// simulator is an array of queues
	int m_q_capacity;
	unsigned m_clients_left = 0;
	unsigned m_max_clients;
	unsigned m_current_amount_of_clients= 0;
public:
	Simulator(const int number_of_queues, const int interval, const algorithm algo);
	Simulator(const string& queue_structure, const int interval, const algorithm algo);
	~Simulator();		// destructor
	Simulator& initialize_array_cells(const string& queue_structure);
	const bool routing_clients(const char client) const;
	const bool are_all_queues_full() const;
	void start_simulation(const int run_time_length);

	const unsigned get_max_clients() const;
	const unsigned get_clients_left() const;
	static string get_algorithm_name(algorithm algo);
};

const int extract_queues_number(const string q_structure);
const int extract_queues_capacity(const string q_structure);

#endif		// _SIMULATOR_H_