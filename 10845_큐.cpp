#include<iostream>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	cin >> n;

	string st;
	int num;

	queue<int> q;

	for (int i = 0;i < n;i++) {
		cin >> st;
		if (st == "push") {
			cin >> num;
			q.push(num);
		}
		else if (st == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (st == "size")
			cout << q.size() << '\n';
		else if (st == "empty")
			cout << int(q.empty()) << '\n';
		else if (st == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (st == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}