#include "Queue.h"



unsigned Queue::queue_number = 1;

Queue::Queue(int capacity) 
	: service_time(random(MIN_SERVICE_TIME, MAX_SERVICE_TIME))
	,m_capacity(capacity)		//Constructor
{
	initialize_queue();
}

Queue::Queue(const Queue& d) 
	: service_time(random(MIN_SERVICE_TIME, MAX_SERVICE_TIME))
	, m_capacity(d.m_capacity)
{
	initialize_queue();
}

//Queue::Queue() { //default ctor
//}

Queue& Queue::initialize_queue() {
	m_queue = new char[m_capacity];
	m_tail = &m_queue[0];
	m_head = nullptr;
	queue_number += sizeof(Queue) + m_capacity * sizeof(char);
	return *this;
}

Queue::~Queue() {
	queue_number-= sizeof(Queue) + m_capacity * sizeof(char);
	delete[] m_queue;
}

// random number initiallization function
int random(int min, int max) { //consider moving this another class later
	uniform_int_distribution<int> distr(min, max); // Guaranteed unbiased
	int rand_num = distr(Queue::m_mt);
	return rand_num;
}

//auto random_integer = distr(rng);
//
//std::random_device rd; // obtain a random number from hardware
//std::mt19937 gen(rd()); // seed the generator
//std::uniform_int_distribution<> distr(25, 63); // define the range

//for (int n = 0; n < 40; ++n)
//	std::cout << distr(gen) << ' '; // generate numbers
//


void Queue::push(char* new_client) {



}








