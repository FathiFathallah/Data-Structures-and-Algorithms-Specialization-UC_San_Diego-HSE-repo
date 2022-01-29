#include <iostream>
#include <math.h>

long long fibonacci_sum_squares_optimized(long long n) {
	n = n % 60;
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;
	long long sum = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous % 10;
		previous = current % 10;
		current = tmp_previous + current;
		sum += (long long)pow(current, 2) % 10;
	}
	return sum % 10;
}


int main() {
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci_sum_squares_optimized(n);
}
