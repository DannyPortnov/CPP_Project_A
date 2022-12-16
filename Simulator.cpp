#include "Simulator.h"



bool Simulator::start_simulation(int run_time_length) {
	if (m_start_simulation == run_time_length)
		return false;
	else {
		m_start_simulation++;
		return true;
	}
}






