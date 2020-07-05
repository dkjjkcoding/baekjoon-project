#include<iostream>
#include<algorithm>

#define MAX 15
#pragma warning(disable:4996)
using namespace std;

int use[MAX];
char alpha[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int l, c;
	cin >> l >> c;
	for (int i = 0;i < c;i++) {
		if (i >= l)
			use[i] = 1;
		cin >> alpha[i];
	}

	sort(alpha, alpha + c);

	bool use_mo;
	string out;
	char temp;
	int cnt_ja;

	do {
		use_mo = false;
		out = "";
		cnt_ja = 0;
		for (int i = 0;i < c;i++) {
			if (use[i] == 0) {
				temp = alpha[i];
				if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
					use_mo = true;
				else
					cnt_ja++;
				out += temp;
			}
		}
		if (use_mo&&cnt_ja>=2)
			cout << out << '\n';
	} while (next_permutation(use, use + c));

	return 0;
}