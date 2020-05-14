#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	int j;

	cin >> n;

	for (int i = 1;i <= n;i++) {
		j = n;
		while (j > i) {
			cout << " ";
			j--;
		}
		while (j--)
			cout << "*";
		cout << endl;
	}

	return 0;
}