#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

bool isPrime(int num) {
	if (num == 1)
		return false;
	else if (num == 2 || num == 3)
		return true;
	else {
		for (int i = 2;i * i <= num;i++) {
			if (num % i == 0)
				return false;
		}
		return true;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<int> prim;

	for (int i = m;i <= n;i++) {
		if (isPrime(i))
			prim.push_back(i);
	}

	for (int num : prim) {
		cout << num << '\n';
	}

	return 0;
}