#include "Simulator.h"

#define max_queue_size 19 //a queue cannot contain more than 19 clients

// Simulator constructor
Simulator::Simulator(string queue_structure, algorithm algo)
	: m_num_of_queues(extract_queues_number(queue_structure)), 
	m_interval(random_func(1,10)),
	m_algorithm(algo)
{
	m_simulator = new Queue*[m_num_of_queues];
	initialize_array_cells(queue_structure);
}
// Simulator constructor
Simulator::Simulator(int number_of_queues, int interval, algorithm algo)
	: m_algorithm(algo), m_interval(interval), m_num_of_queues(number_of_queues)
{
	m_simulator = new Queue * [m_num_of_queues];
}
// method that initialize the cells of the array of queues
Simulator& Simulator::initialize_array_cells(string queue_structure) {
	m_q_capacity = extract_queues_capacity(queue_structure);
	for (int i = 0; i < m_num_of_queues; i++) {
		m_simulator[i] = new Queue(m_q_capacity);
	}
	return *this;
}

// Simulator destructor
Simulator::~Simulator() {
	for (int i = 0; i < m_num_of_queues; i++) {
		delete m_simulator[i];
	}
	delete[] m_simulator;
}

void Simulator::routing_clients(char client) {

	switch (m_algorithm)
	{
	Queue* queue_to_route_client = nullptr;
	case shortest:
		int min = max_queue_size; //assume at least one queue
		for (int i = 1; i < m_num_of_queues; i++)
		{
			if (m_simulator[i]->size() < min) {
				queue_to_route_client = m_simulator[i];
				min = queue_to_route_client->size();
			}
		}
		queue_to_route_client->push(client);
		break;

	case longest:



	case fastest:


	case random:
		bool q_is_full = true;
		int random_queue;
		while (q_is_full) {
			random_queue = random_func(0, m_q_capacity - 1); //generate a random queue index and try routing a client to that queue
			q_is_full = m_simulator[random_queue]->is_queue_full();
			if (!m_simulator[random_queue]->is_queue_full())
				queue_to_route_client->push(client);
		}
	default:
		break;


	}
}
//Checks whether all queues are full or not 
bool Simulator::are_all_queues_full() {
	for (int i = 1; i < m_num_of_queues; i++)
	{
		if (!m_simulator[i]->is_queue_full()) {
			return false;
		}
	}
	return true;
}





bool Simulator::start_simulation(int run_time_length) {
	if (m_start_simulation == run_time_length)
		return false;
	else {
		m_start_simulation++;
		return true;
	}
}

// function that extracts the number of queues out of a string
int extract_queues_number(string q_structure) {
	int string_size = q_structure.length();
	int queues_number = 0;
	bool is_q = false;
	for (int i = 0; i < string_size; i++) {
		if (q_structure[i] == '_') {
			break;
		}
		if (is_q) {
			queues_number = queues_number * 10 + q_structure[i] - '0';
		}
		if (q_structure[i] == 'q')
			is_q = true;
	}
	return queues_number;
}

// function that extracts the capacity of the queues out of a string
int extract_queues_capacity(string q_structure) {
	int string_size = q_structure.length();
	int count_underscore = 0;
	bool is_random = false;		// used to check if we have random capacity or not.
	int rand_min = 0;
	int rand_max = 0;
	int queue_capacity = 0;
	for (int i = 0; i < string_size; i++) {
		if (is_random && count_underscore > 0) {
			if (count_underscore == 1 && q_structure[i] != '_')
				rand_min = rand_min * 10 + q_structure[i] - '0';
			else if (count_underscore == 2)
				rand_max = rand_max * 10 + q_structure[i] - '0';
		}
		if (q_structure[i] == 'R')		// check if the capacity must be random out of 2 numbers
			is_random = true;
		else if (!is_random && count_underscore == 1)
			queue_capacity = queue_capacity * 10 + q_structure[i] - '0';
		if (q_structure[i] == '_') {
			count_underscore++;
		}
	}
	if (is_random)
		queue_capacity = random_func(rand_min, rand_max);
	return queue_capacity;
}




