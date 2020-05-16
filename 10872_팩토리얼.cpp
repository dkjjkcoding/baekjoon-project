#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int result = n < 2 ? 1 : n; // 0!=1!=1
	for (int i = n - 1;i > 1;i--)
		result *= i;

	cout << result;

	return 0;
}