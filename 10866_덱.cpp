#include<iostream>
#include<deque>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	cin >> n;

	string str;
	int x;

	deque<int> dq;

	for (int i = 0;i < n;i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (str == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop_front") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (str == "size")
			cout << dq.size() << '\n';
		else if (str == "empty")
			cout << int(dq.empty()) << '\n';
		else if (str == "front") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
		}
		else if (str == "back") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.back() << '\n';
		}
	}

	return 0;
}