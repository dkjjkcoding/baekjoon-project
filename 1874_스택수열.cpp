#include<iostream>
#include<stack>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n, num;
	vector<int> input;
	stack<int> s;
	string output = "";

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> num;
		input.push_back(num);
	}

	vector<int>::iterator iter;
	iter = input.begin();
	for (int i = 1;i <= n;i++) {
		s.push(i);
		output += '+';
		while (!s.empty()) {
			if (*iter != s.top())
				break;
			else {
				output += '-';
				s.pop();
				iter++;
			}
		}
	}
	if (s.empty())
		for (int i = 0;i < output.length();i++)
			cout << output[i] << '\n';
	else
		cout << "NO";

	
	return 0;
}