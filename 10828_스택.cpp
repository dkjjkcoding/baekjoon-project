#include<iostream>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	stack<int> s;

	int n;
	cin >> n;

	string str;
	int num;
	while (n--) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			if (s.empty())
				cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (str == "size")
			cout << s.size() << endl;
		else if (str == "empty")
			cout << int(s.empty()) << endl;
		else if (str == "top") {
			if (s.empty())
				cout << -1 << endl;
			else
				cout << s.top() << endl;
		}
	}

	return 0;
}