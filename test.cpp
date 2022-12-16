#include "Queue.h"

mt19937 Queue::m_mt((random_device())());

int main() {
	Queue queue1(3);
	queue1.push('a');
	queue1.push('b');
	queue1.push('c');
	queue1.push('e');
	return 0;
}