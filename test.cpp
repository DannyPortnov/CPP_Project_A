#include "Queue.h"



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
	Queue queue1(10);
	for (char i = 'a'; i < 'e'; i++)
	{
		queue1.push(i); //push a to d
	}
	queue1.pop();//pop a
	queue1.pop();//pop b
	for (char i = 'e'; i < 'l'; i++)
	{
		queue1.push(i); //push e to k
	}
}

void print_queue(Queue q) { //move inside the class after niv finishes with front()
	//while (!q.is_queue_empty()) {
	//	cout<
	//}
}

int main() {
	test1();
	test2();
	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;

	return 0;
}