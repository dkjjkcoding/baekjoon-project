#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int n, s;
	int* bros;
	int result, temp;

	cin >> n >> s;
	bros = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> bros[i];
		bros[i] -= s;
		if (bros[i] < 0) {
			bros[i] *= -1;
		}
	}
	result = gcd(bros[0], bros[1]);
	for (int i = 1;i < n - 1;i++) {
		temp = gcd(bros[i], bros[i + 1]);
		result = result < temp ? result : temp;
	}
	cout << result << '\n';

	return 0;
}