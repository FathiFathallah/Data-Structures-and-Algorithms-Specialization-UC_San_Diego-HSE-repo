#include <iostream>

//lcd(a,b) = |a.b|/gcd(a,b)
//we need the optimized gcd algorithm and the running time will be very good
long long EuclidGCD(int a, int b) {
	if (b == 0)
		return a;
	else {
		a = a % b;
		return EuclidGCD(b, a);
	}
}

long long lcm_optimized(int a, int b) {
	long long LCM = ((long long)a * b) / EuclidGCD(a, b);
	return LCM;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << lcm_optimized(a, b) << std::endl;
	return 0;
}



