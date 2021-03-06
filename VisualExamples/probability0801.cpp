#include <random>
#include <iostream>


int main(int argc, char* argv[])
{
	// This is used to seed the generator
	std::random_device rd;

	// We seed the Mersenne twister 
	std::mt19937 gen(rd()); 

	

	{
		// Example of use of random numbers

		// Replace these ones below with whatever distribution you are using
		// There are many distributions......see std documentation 
		std::uniform_real_distribution<> dis1(0, 1);
		std::uniform_int_distribution<> dis2(0, 10);

		// Use your generators as this:<br />
		std::cout << dis1(gen) << std::endl;
		std::cout << dis2(gen) << std::endl;

	}

	{
		// Calculate the the probability of at least two sixes when we roll 4 dice

		// Setup of random number generator.
		std::uniform_int_distribution<> diceroll(1, 6);
		auto rnd = [&]() { return diceroll(gen); };		

		int numRuns = 1000;
		int hits = 0;
		for (int i = 0; i < numRuns; i++) {
			// draw a sample and count sixes
			int count = 0;
			for (int j = 0; j < 4; j++) {
				if (rnd() == 6) count++;
			}

			// test for hit
			if (count > 1) hits += 1;
		}
		std::cout << "Approx. probability is " << (float) hits / (float) numRuns << " after " << numRuns << " runs. " << std::endl;

	}
}



