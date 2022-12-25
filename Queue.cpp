#include "Queue.h"


unsigned Queue::queue_number = 1; //number of queues instances created
mt19937 Queue::m_gen((random_device())()); // Only used once to initialize Random-number (seed) engine (Mersenne-Twister in this case)

//Constructor
Queue::Queue(int capacity) 
	: m_service_time(random_func(MIN_SERVICE_TIME, MAX_SERVICE_TIME))
	,m_capacity(capacity), m_head(nullptr)	
{
	initialize_queue();
}
//Copy Constructor
Queue::Queue(const Queue& d) 
	: m_service_time(random_func(MIN_SERVICE_TIME, MAX_SERVICE_TIME))
	, m_capacity(d.m_capacity), m_head(nullptr)	
{
	initialize_queue();
}

//Initializes the quere as char array and m_tail as first element, and increments queue_number
Queue& Queue::initialize_queue() {
	m_queue = new char[m_capacity];
	m_tail = &m_queue[0];
	queue_number++;
	return *this;
}

Queue::~Queue() {
	queue_number--;
	delete[] m_queue;
}

//Pushes if possible a client into the queue.
void Queue::push(const char new_client) {
	if (!is_queue_full()) {
		*m_tail = new_client;
		increment_pointer(m_tail);
		m_variables_count++;
	}
	else {
		return;
	}
	if (is_queue_empty()) { //checks if m_head is nullptr, not really empty because a client was pushed.
		if (m_tail == &m_queue[0]) {
			m_head = &m_queue[m_capacity - 1];
		}
		else {
			m_head = (m_tail - 1);
		}
	}
}
//increments pointer in a 'cyclic manner', so if it's pointing to the last element it will point to the first one.
//Else, points simply to the next one.
void Queue::increment_pointer(char*& pointer) {
	if (pointer == &m_queue[m_capacity - 1]) {
		pointer = &m_queue[0];
	}
	else {
		pointer++;
	}
}
//returns service time
const int Queue::get_service_time() const {
	return m_service_time;
}

//remove a client from the head of the queue
//returns whether the removal was succesful or not
const bool Queue::pop() {
	if (is_queue_empty()) {
		return false;
	}
	*m_head = NULL; //remove client
	increment_pointer(m_head);
	if (m_tail == m_head) {
		m_head = nullptr;
	}
	m_variables_count--;
	
	return true;
}

//Checks if queue is full
const bool Queue::is_queue_full() const {
	return m_tail == m_head;
}

//Checks if queue is empty
const bool Queue::is_queue_empty() const {
	return m_head == nullptr;
}


// function that returns the first variable in queue.
const char Queue::front() const {
	if (!is_queue_empty())
		return *m_head;
	cout << "The Queue Is Empty!" << endl;
}

// function that returns the number of variables in queue
const int Queue::size() const {
	return m_variables_count;
}

//returns random number generator
mt19937& Queue::get_random_num_gen() {
	return m_gen;
}

// random number initiallization function
const int random_func(const int min, const int max) { 
	uniform_int_distribution<int> distr(min, max); // Guaranteed unbiased
	int rand_num = distr(Queue::get_random_num_gen());
	return rand_num;
}












