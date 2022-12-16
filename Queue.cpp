#include "Queue.h"


unsigned Queue::queue_number = 1;
mt19937 Queue::m_gen((random_device())()); // Only used once to initialize Random-number (seed) engine (Mersenne-Twister in this case)


Queue::Queue(int capacity) 
	: m_service_time(random_func(MIN_SERVICE_TIME, MAX_SERVICE_TIME))
	,m_capacity(capacity)		//Constructor
{
	initialize_queue();
}

Queue::Queue(const Queue& d) 
	: m_service_time(random_func(MIN_SERVICE_TIME, MAX_SERVICE_TIME))
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
	queue_number++;
	return *this;
}

Queue::~Queue() {
	queue_number--;
	delete[] m_queue;
}

void Queue::push(char new_client) {
	if (!is_queue_full()) {
		*m_tail = new_client;
		increment_pointer(m_tail);
		m_variables_count++;
	}
	else {
		cout << "queue is full, unable to push another client" << endl;
		return;
	}
	if (is_queue_empty()) {
		m_head = &m_queue[0];
	}
}

void Queue::increment_pointer(char*& pointer) {
	if (pointer == &m_queue[m_capacity - 1]) {
		pointer = &m_queue[0];
	}
	else {
		pointer++;
	}
}

void Queue::pop() {
	if (is_queue_empty()) {
		cout << "queue is empty, unable to pop client" << endl;
		return;
	}
	*m_head = NULL; //remove client
	increment_pointer(m_head);
	if (m_tail == m_head) {
		m_head = nullptr;
	}
	m_variables_count--;
}

bool Queue::is_queue_full() {
	return m_tail == m_head;
}

bool Queue::is_queue_empty() {
	return m_head == nullptr;
}


// function that returns the first variable in queue.
const char Queue::front() {
	if (m_head != nullptr)
		return *m_head;
	cout << "The Queue Is Empty!" << endl;
}

// function that returns the number of variables in queue
int Queue::size() {
	return m_variables_count;
}

// random number initiallization function
int random_func(int min, int max) { //consider moving this another class later
	uniform_int_distribution<int> distr(min, max); // Guaranteed unbiased
	int rand_num = distr(Queue::m_gen);
	return rand_num;
}












