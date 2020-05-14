#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int gcd(int a, int b)
{
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
	int t;
	int n;
	long long sum;

	cin >> t;

	vector<int> v;
	while (t--) {
		cin >> n;
		v.resize(n);

		for (int i = 0;i < v.size();i++)
			cin >> v[i];

		sum = 0;
		for (int i = 0;i < v.size() - 1;i++)
			for (int j = i + 1;j < v.size();j++)
				sum += gcd(v[i], v[j]);

		cout << sum << endl;
	}

	return 0;
}