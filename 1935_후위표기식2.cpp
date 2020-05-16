#include<iostream>
#include<string>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();

	string st;
	getline(cin, st);

	int* arr = new int[n];
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	stack<double> s;
	double a, b, result;
	for (char c : st) {;
		if (c >= 65 && c <= 90) {
			s.push(arr[c - 65]);
		}
		else {
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			switch (c) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/': result = a / b; break;
			}
			s.push(result);
		}
	}

	printf("%.2f", s.top());

	return 0;
}