//WORKS WITH BIG NUMBERS LIKE get_fibonacci_last_digit_naive(250)
//F250 = 7896325826131730509282738943634332893686268675876375
//WHAT WE ONLY NEED IS THE LAST DIGIT OF THE NUMBER, SO WE DON'T NEED TO SUM THE WHOLE NUMBER ☺
#include <iostream>

int get_fibonacci_last_digit_optimized(int n) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (int i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = ((tmp_previous % 10) + (current % 10)) % 10;
	}
	return current;
}

int main() {
	int n;
	std::cin >> n;

	long long c = get_fibonacci_last_digit_naive(n);
	std::cout << c << '\n';
}
