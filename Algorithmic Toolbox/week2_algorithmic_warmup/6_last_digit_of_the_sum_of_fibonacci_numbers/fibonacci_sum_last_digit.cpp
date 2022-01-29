#include <iostream>
#include <math.h>

//THIS WILL GIVE ME THE LAST DIGIT FOR A VERY HUGE NUMBER
long long get_fibonacci_huge_FAST(long long n) {
	//Pisano Period of 10 is 60
	n = n % 60;
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = ((tmp_previous % 100) + (current % 100)) % 100;
	}
	return current;
}


//BASED ON SOME ANALYSIS => Febonacci_Sum(n) = F(n+2) - 1 
long long fibonacci_sum_FAST(long long n) {
	if (n <= 1)
		return n;

	long long sum = get_fibonacci_huge_FAST(n + 2) - 1;
	return sum % 10;
}

int main() {
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci_sum_FAST(n);
}




