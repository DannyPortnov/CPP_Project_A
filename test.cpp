#include "Queue.h"
#include "Simulator.h"
#include <fstream>

#define run_length 10000
#define number_of_iterations_per_sim 100
//#define run_length 70

#define results_file_name "results.csv"

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
	/*int size_check;*/
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

// test for extract functions
void test3() {
	string s = "q10_R1_19";
	int queues_num = extract_queues_number(s);
	int capacity = extract_queues_capacity(s);
	cout << "queues num: " << queues_num << " capacity of queue is: " << capacity << endl;
}

void test4() { //works
	string s = "q10_10";
	//Simulator sim1(s,shortest); //check later
	Simulator sim2(10, 5, longest);
	sim2.initialize_array_cells(s);
}

void test5() { //testing start_simulation ^_^

	//Simulator s_shortest("q10_10", 1, shortest);
	//s_shortest.start_simulation(run_length); //works, if 70 then 60 is max and 10 left

	//Simulator s_longest("q10_10", 1, longest);
	//s_longest.start_simulation(run_length);//works, for 70 we get ~65 max and ~5 left

	//Simulator s_fastest("q10_10", 1, fastest);
	//s_fastest.start_simulation(run_length); //works, for 70 we get ~64 max and ~6 left

	Simulator s_random("q10_10", 1, random);
	s_random.start_simulation(run_length); //works, for 70 we get ~60 max and ~10 left

}

void test6() { //writing to file
	ofstream myfile;
	myfile.open(results_file_name);
	string q_struct = "q10_10";
	algorithm algo = shortest;
	int interval = 1;
	Simulator s_shortest(q_struct, interval, algo);
	s_shortest.start_simulation(run_length); //works, if 70 then 60 is max and 10 left

	myfile.close();
}

void algorithm_interval_avg(const string& q_struct, int interval, algorithm algo, ofstream& myfile)
{
	unsigned total_max_clients = 0, total_clients_left = 0;
	for (int i = 1; i <= number_of_iterations_per_sim; i++) {
		Simulator sim(q_struct, interval, algo);
		sim.start_simulation(run_length);
		total_max_clients += sim.get_max_clients();
		total_clients_left += sim.get_clients_left();
	}
	unsigned avg_max_clients = total_max_clients / number_of_iterations_per_sim;
	unsigned avg_clients_left = total_clients_left / number_of_iterations_per_sim;
	string m_algorithm_to_string[] = { "shortest", "longest","fastest","random" };
	myfile << q_struct << "," << m_algorithm_to_string[(int)algo] << "," << interval << "," << avg_clients_left << "," << avg_max_clients << "\n";
}

void algorithm_interval_gen(const string& q_struct, ofstream& myfile) {
	algorithm algo;
	for (int a = 0; a < 4; a++) {
		if (a == 0)
			algo = longest;
		else if (a == 1)
			algo = shortest;
		else if (a == 2)
			algo = fastest;
		else if (a == 3)
			algo = random;
		for (int interval = 1; interval <= 10; interval++) {
			algorithm_interval_avg(q_struct, interval, algo, myfile);
		}
	}
}


#define number_of_queue_structs 3
void test_bench() { //works!
	ofstream myfile;
	myfile.open(results_file_name);
	myfile << "q_struct,algorithm,interval,clients left,total max clients\n";
	unsigned total_max_clients = 0, total_clients_left = 0;
	string queue_structs[] = { "q10_10" ,"q100_1","q10_R1_19" };

	for (int i = 0; i < number_of_queue_structs; i++) {
		algorithm_interval_gen(queue_structs[i], myfile);
	}
	myfile.close();
}




int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test_bench();
	cout << "Memory Leaks: " << _CrtDumpMemoryLeaks() << endl;

	return 0;
}