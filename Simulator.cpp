#include "Simulator.h"

//#define max_queue_size 19 //a queue cannot contain more than 19 clients

// Simulator constructor
Simulator::Simulator(string queue_structure, int interval, algorithm algo)
	: m_num_of_queues(extract_queues_number(queue_structure)),
	m_interval(interval),
	m_algorithm(algo), m_max_clients(0), m_q_capacity(0)
{
	m_simulator = new Queue*[m_num_of_queues];
	initialize_array_cells(queue_structure);
}
// Simulator constructor
Simulator::Simulator(int number_of_queues, int interval, algorithm algo)
	: m_algorithm(algo), m_interval(interval), m_num_of_queues(number_of_queues), m_max_clients(0), m_q_capacity(0)
{
	m_simulator = new Queue*[m_num_of_queues];
}
// method that initialize the cells of the array of queues
Simulator& Simulator::initialize_array_cells(const string queue_structure) {
	m_q_capacity = extract_queues_capacity(queue_structure);
	for (int i = 0; i < m_num_of_queues; i++) {
		m_simulator[i] = new Queue(m_q_capacity);
		//m_max_clients += m_q_capacity;
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

const unsigned Simulator::get_max_clients() const {
	return m_max_clients;
}

const unsigned Simulator::get_clients_left() const {
	return m_clients_left;
}

//Route a client to a queue based on the algorithm chosen.
//returns whether the routing was succesfull (client added to queue) or not
const bool Simulator::routing_clients(const char client) const {
	if (are_all_queues_full()) {
		return false;
	}
	Queue* queue_to_route_client = m_simulator[0];
	switch (m_algorithm)
	{
	case shortest:
	{
		int min = queue_to_route_client->size();
		for (int i = 1; i < m_num_of_queues; i++)
		{
			if (m_simulator[i]->size() < min) {
				queue_to_route_client = m_simulator[i];
				min = queue_to_route_client->size();
			}
		}
		break;
	}
	case longest:
	{
		int max = -1;
		for (int i = 0; i < m_num_of_queues; i++)
		{
			if (m_simulator[i]->size() > max && !m_simulator[i]->is_queue_full()) {
				queue_to_route_client = m_simulator[i];
				max = queue_to_route_client->size();
			}
		}
		break;
	}
	case fastest: //client joins a queue with the minimum service time and that isn't full
	{
		int min_service_time = MAX_SERVICE_TIME + 1;
		for (int i = 0; i < m_num_of_queues; i++)
		{
			if (m_simulator[i]->get_service_time() < min_service_time && !m_simulator[i]->is_queue_full()) {
				queue_to_route_client = m_simulator[i];
				min_service_time = queue_to_route_client->get_service_time();
			}
		}
		break;
	}
	case random:		// cilent joins a queue randomly.
	{
		bool q_is_full = true;
		int random_queue;
		while (q_is_full) {
			random_queue = random_func(0, m_num_of_queues - 1); //generate a random queue index and try routing a client to that queue
			q_is_full = m_simulator[random_queue]->is_queue_full();
		}
		queue_to_route_client = m_simulator[random_queue];
		break;
	}
	default:	// this is for when another algorithm is defined, and the function will not support it.
		cout << "algorithm  " << m_algorithm << " isn't currently supported by routing_clients method" << endl;
		return false;
	}
	queue_to_route_client->push(client);
	return true;
}


//Checks whether all queues are full or not 
const bool Simulator::are_all_queues_full() const {
	for (int i = 1; i < m_num_of_queues; i++)
	{
		if (!m_simulator[i]->is_queue_full()) {
			return false;
		}
	}
	return true;
}

void Simulator::start_simulation(const int run_time_length) {
	char client = 'A';//start pushing upper case
	unsigned max_clients_allowed = m_num_of_queues * m_q_capacity;
	for (int i = 1; i <= run_time_length; i++)
	{
		for (int j = 0; j < m_num_of_queues; j++)
		{
			bool is_time_a_period_of_service_time = !(i % m_simulator[j]->get_service_time());
			if (is_time_a_period_of_service_time) {
				if (m_simulator[j]->pop()) { //executes pop!
					if (m_current_amount_of_clients)
						m_current_amount_of_clients--;
				}
			}
		}
		if (i % m_interval == 0) { //push a client to a queue every interval time units
			if (routing_clients(client)) {
				m_current_amount_of_clients++;
			}
			else {
				m_clients_left++;
			}
		}
		if (m_current_amount_of_clients > m_max_clients) { //if reached a new max, update
			if(m_current_amount_of_clients<=max_clients_allowed+1)
				m_max_clients = m_current_amount_of_clients;
		}
		client++;
		if (client == 'Z' + 1) { //start pushing lower case
			client = 'a';
		}
		if (client == 'z' + 1) {//start pushing upper case
			client = 'A';
		}
	}
}

// function that extracts the number of queues out of a string
const int extract_queues_number(const string q_structure) {
	int string_size = (int)q_structure.length();
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
const int extract_queues_capacity(const string q_structure) {
	int string_size = (int)q_structure.length();
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




