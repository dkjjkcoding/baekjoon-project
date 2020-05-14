#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int t;
	int a, b;
	int r, ab;

	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> a >> b;
		ab = a * b;
		while (b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		cout << ab / a << endl;
	}

	return 0;
}