#include "Queue.h"
#include "Simulator.h"


void test1() { //works
	Queue queue1(3);
	queue1.push('a');
	queue1.push('b');
	queue1.push('c');
	queue1.push('e');
	queue1.pop();
	queue1.pop();
	queue1.pop();
	queue1.pop();
}


void test2() {
	int size_check;
	Queue queue1(10);
	for (char i = 'a'; i < 'e'; i++)
	{
		queue1.push(i); //push a to d
	}
	cout << "front is: " << queue1.front() << endl;
	cout << "queue 1 after push a to d: " << queue1.size() << endl;
	queue1.pop();//pop a
	queue1.pop();//pop b
	cout << "front is: " << queue1.front() << endl;
	cout << "queue 1 after pop a, b: " << queue1.size() << endl;
	for (char i = 'e'; i < 'l'; i++)
	{
		queue1.push(i); //push e to k
	}
	cout << "front is: " << queue1.front() << endl;
	cout << "queue 1 after push e to k: " << queue1.size() << endl;
}

void print_queue(Queue q) { //move inside the class after niv finishes with front()
	//while (!q.is_queue_empty()) {
	//	cout<
	//}
}



int main() {

	test1();
	test2();
	string s = "q10_R1_19";
	int queues_num = extract_queues_number(s);
	int capacity = extract_queues_capacity(s);
	cout << "queues num: " << queues_num << " capacity of queue is: " << capacity << endl;
	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;

	return 0;
}