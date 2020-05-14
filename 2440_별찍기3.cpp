#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;

	cin >> n;
	
	int j;
	for (int i = n;i > 0;i--) {
		j = i;
		while (j--)
			cout << "*";
		cout << endl;
	}

	return 0;
}