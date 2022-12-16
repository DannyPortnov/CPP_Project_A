#include "Queue.h"


unsigned Queue::queue_number = 1;
mt19937 Queue::m_gen((random_device())()); // Only used once to initialize Random-number (seed) engine (Mersenne-Twister in this case)


Queue::Queue(int capacity) 
	: m_service_time(random(MIN_SERVICE_TIME, MAX_SERVICE_TIME))
	,m_capacity(capacity)		//Constructor
{
	initialize_queue();
}

Queue::Queue(const Queue& d) 
	: m_service_time(random(MIN_SERVICE_TIME, MAX_SERVICE_TIME))
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
	/*queue_number += sizeof(Queue) + m_capacity * sizeof(char);*/
	queue_number++;
	return *this;
}

Queue::~Queue() {
	/*queue_number-= sizeof(Queue) + m_capacity * sizeof(char);*/
	queue_number--;
	delete[] m_queue;
}

void Queue::push(char new_client) {
	if (!is_queue_full()) {
		*m_tail = new_client;
		if (m_tail == &m_queue[m_capacity - 1]) {
			m_tail = &m_queue[0];
		}
		else {
			m_tail++;
		}
	}
	else {
		cout << "queue is full, unable to push another client" << endl;
		return;
	}
	if (m_head == nullptr) {
		m_head = &m_queue[0];
	}
	
}

bool Queue::is_queue_full() {
	return m_tail == m_head;
}


// function that returns the first variable in queue.
const char Queue::front() {
	if (m_head != nullptr)
		return *m_head;
	cout << "The Queue Is Empty!" << endl;
}

// function that returns the number of variables in queue
int Queue::size() {

}

// random number initiallization function
int random(int min, int max) { //consider moving this another class later
	uniform_int_distribution<int> distr(min, max); // Guaranteed unbiased
	int rand_num = distr(Queue::m_gen);
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











