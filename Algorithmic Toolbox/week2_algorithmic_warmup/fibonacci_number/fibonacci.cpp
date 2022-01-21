#include <iostream>
#include <cassert>

// T(100) ≈ 1.77 · 10^21 (1.77 sextillion) => Takes 56, 000 years at 1GHz !!!!!!
int fibonacci_naive(int n) {
	if (n <= 1)
		return n;

	return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}


int fibonacci_fast(int n) {
	// write your code here
	if (n <= 1)
		return n;
	int* Array = new int[n];
	Array[0] = 0;
	Array[1] = 1;
	for (int i = 2;i < n;i++) {
		Array[i] = Array[i - 2] + Array[i - 1];
	}
	return Array[n - 1] + Array[n - 2];
}

void test_solution() {
	assert(fibonacci_fast(3) == 2);
	assert(fibonacci_fast(10) == 55);
	for (int n = 0; n < 20; ++n)
		assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
	int n = 0;
	std::cin >> n;

	std::cout << fibonacci_fast(n) << '\n';
	//test_solution();
	//std::cout << fibonacci_fast(n) << '\n';
	return 0;
}
