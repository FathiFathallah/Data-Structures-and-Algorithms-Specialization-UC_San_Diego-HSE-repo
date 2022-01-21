#include <iostream>
#include <vector>
#include <algorithm>

//This Will Take 2n only ( Running Time asymptotically = n)
long long MaxPairwiseProduct_Fast(const std::vector<int>& numbers) {
	long long max_product = 0;
	int firstMaxindex = 0;
	int secondMaxindex = 0;

	int n = numbers.size();

	int firstMax = 0;
	for (int i = 0; i < n; i++) {
		if (numbers[i] > firstMax) {
			firstMax = numbers[i];
			firstMaxindex = i;
		}
	};

	long long secondMax = 0;
	for (int j = 0; j < n; j++) {
		if (j != firstMaxindex && numbers[j] > secondMax ) {
			secondMax = numbers[j];
			secondMaxindex = j;
		}
	};

	max_product = (long long)firstMax * (long long)secondMax;
	return max_product;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}

	std::cout << MaxPairwiseProduct_Fast(numbers) << "\n";
	return 0;
}
