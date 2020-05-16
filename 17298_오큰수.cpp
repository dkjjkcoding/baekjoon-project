#include<iostream>
#include<vector>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> v(n);
	for (int i = 0;i < n;i++)
		scanf("%d", &v[i]);

	vector<int> nge(n, -1);
	stack<int> s;

	for (int i = 0;i < n;i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			nge[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int num : nge)
		printf("%d ", num);

	return 0;
}