#include "Simulator.h"


Simulator::Simulator(int number_of_queues, int interval, algorithm algo) 
	: m_algorithm(algo), m_interval(interval), m_num_of_queues(number_of_queues)
{
	/*queues_array = new Queue[number_of_queues];
	for (int i = 0; i < number_of_queues; i++)
	{

	}*/
}


bool Simulator::start_simulation(int run_time_length) {
	if (m_start_simulation == run_time_length)
		return false;
	else {
		m_start_simulation++;
		return true;
	}
}






