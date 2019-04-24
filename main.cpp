#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "utils.h"

int main(int argc, char *argv[])
{
	std::cout << "Enter integers for LCM calculation, separated with spaces. End with 0." << std::endl;
	std::string line;
	std::getline(std::cin, line);
	std::istringstream stream(line);
	int number;
	std::vector<int> numbers;
	while (stream >> number)
		numbers.push_back(number);

	std::cout << "The least common multiplier is " << CalculateLCM(numbers) << std::endl;

	return 0;
}
