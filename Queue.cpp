#include "Queue.h"



// random number initiallization function
int random(int min, int max) {
	random_device rd;     // Only used once to initialise (seed) engine
	mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
	uniform_int_distribution<int> distr(min, max); // Guaranteed unbiased
	int rand_num = distr(rng);
	return rand_num;
}




auto random_integer = distr(rng);






std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(25, 63); // define the range

for (int n = 0; n < 40; ++n)
	std::cout << distr(gen) << ' '; // generate numbers



void Queue::push(char* new_client) {



}








