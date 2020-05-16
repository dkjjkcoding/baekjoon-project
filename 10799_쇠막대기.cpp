#include<iostream>
#include<string>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	string input;
	getline(cin, input);

	stack<char> s;
	bool isLaser = false;
	int cnt = 0;

	for (int i = 0;i < input.length();i++) {
		if (input[i] == '(') {
			s.push(input[i]);
			isLaser = true;
		}
		else{
			s.pop();
			if (isLaser) {
				cnt += s.size();
			}
			else {
				cnt += 1;
			}
			isLaser = false;
		}
	}
	cnt += s.size();
	cout << cnt;

	return 0;
}