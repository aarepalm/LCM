#include <map>
#include <math.h>

#include "utils.h"

namespace
{
	bool isPrime(int integer)
	{
		for (int i = 2; i < integer; ++i)
		{
			if (!(integer % i))
				return false;
		}
		return true;
	}

	int getNextPrime(int integer)
	{
		if (integer < 3)
			return ++integer;

		while (!isPrime(++integer))
		{
			// do nothing here
		}
		return integer;
	}

	std::map<int, int> findFactors(int integer)
	{
		// The result is histogram of primes. For example, the 20 is factored to primes 2 * 2 * 5.
		// This will make a histogram like that:
		// ____________
		// key | value
		// ------------
		//  2  | 2      because there are two 2s
		//  5  | 1      because there is one 5
		std::map<int, int> result;

		if (integer == 0)
			return result;

		int prime = 2;
		while (integer != 1)
		{
			if (!(integer % prime))
			{
				integer /= prime;
				++result[prime];
			}
			else
			{
				prime = getNextPrime(prime);
			}
		}
		return result;
	}

	double getLowestCommonMultiple(const std::vector<int> integers)
	{
		// First factor all the numbers to primes
		std::vector<std::map<int, int>> factoredIntegers;
		for (int i : integers)
		{
			factoredIntegers.push_back(findFactors(i));
		}

		// Find all the common factors
		std::map<int, int> commonFactors;
		for (const auto & map : factoredIntegers)
		{
			for (const auto &pair : map)
			{
				int key = pair.first;
				int value = pair.second;
				if (commonFactors[key] < value)
					commonFactors[key] = value;
			}
		}

		// Multiply all the common factors to get the Lowest Common Multiplier
		double result = 1;
		for (const auto &pair : commonFactors)
		{
			int key = pair.first;
			int value = pair.second;
			result *= pow(static_cast<int>(key), static_cast<int>(value));
		}

		return result;
	}
}

double CalculateLCM(const std::vector<int> numbers)
{
	return getLowestCommonMultiple(numbers);
}
