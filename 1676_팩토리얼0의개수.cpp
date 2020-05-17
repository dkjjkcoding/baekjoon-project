#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, two, five, temp;

	cin >> n;

	two = 0, five = 0;
	for (int i = 2;i <= n;i++) {
		temp = i;
		while (temp % 2 == 0) {
			two++;
			temp /= 2;
		}
		temp = i;
		while (temp % 5 == 0) {
			five++;
			temp /= 5;
		}
	}

	temp = two > five ? five : two;
	cout << temp;

	return 0;
}