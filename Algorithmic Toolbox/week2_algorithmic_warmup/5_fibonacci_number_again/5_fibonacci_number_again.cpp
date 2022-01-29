#include <iostream>
#include <math.h>
long long pisanoFun(long long m)
{
	long long previous = 0;
	long long current = 1;
	long long pisano = 0;

	for (long long i = 0; i < m * m; i++){
		long long tmp = 0;
		tmp = current;
		current = (previous + current) % m;
		previous = tmp;

		if (previous == 0 && current == 1)
			pisano = i + 1;
	}
	return pisano;
}

long long get_fibonacci_huge_FAST(long long n, long long m) {

	if (m >= 2) {
		int pisanoPeriod = pisanoFun(m);
		n = n % pisanoPeriod;
	}

	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = ((tmp_previous % m) + (current % m)) % m;
	}
	return current;


}

int main() {
	long long n, m;
	std::cin >> n >> m;
	std::cout << get_fibonacci_huge_FAST(n, m) << '\n';
}
