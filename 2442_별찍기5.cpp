#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		for (int j = n - i;j > 0;j--)
			cout << " ";
		for (int j = i;j > 0;j--)
			cout << "*";
		for (int j = i - 1;j > 0;j--)
			cout << "*";
		cout << endl;
	}
}