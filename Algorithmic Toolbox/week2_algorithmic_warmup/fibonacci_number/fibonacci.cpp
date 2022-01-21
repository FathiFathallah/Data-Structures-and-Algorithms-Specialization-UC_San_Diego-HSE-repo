#include <iostream>

int febonacciCalc(int n) {
	if (n <= 1) return n;
	else { return febonacciCalc(n - 1) + febonacciCalc(n - 2); }
}

int main()
{
    std::cout << febonacciCalc(40);
}
