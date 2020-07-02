#include<iostream>

#pragma warning(disable:4996)
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int e, s, m;
	cin >> e >> s >> m;

	int result = 0;
	while (!(e == 0 && s == 0 && m == 0)) {
		if (e == 0)
			e = 15;
		if (s == 0)
			s = 28;
		if (m == 0)
			m = 19;
		e--;
		s--;
		m--;
		result++;
	}

	cout << result << '\n';

	return 0;
}