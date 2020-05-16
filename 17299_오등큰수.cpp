#include<iostream>
#include<vector>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

int f[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
		f[v[i]]++;
	}

	vector<int> ngf(n, -1);
	stack<int> s;

	for (int i = 0;i < n;i++) {
		while (!s.empty() && f[v[s.top()]] < f[v[i]]) {
			ngf[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int num : ngf)
		printf("%d ", num);

	return 0;
}