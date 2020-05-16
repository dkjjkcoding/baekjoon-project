#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	string st;
	getline(cin, st); // <string> getline
	string word = "";
	bool tag = false;

	for (int i = 0;i < st.length();i++) {
		if (st[i] == '<') {
			reverse(word.begin(), word.end());
			cout << word << '<';
			word = "";
			tag = true;
		}
		else if (st[i] == '>') {
			cout << word << '>';
			word = "";
			tag = false;
		}
		else if (!tag && st[i] == ' ') {
			reverse(word.begin(), word.end());
			cout << word << ' ';
			word = "";
		}
		else
			word += st[i];
	}
	reverse(word.begin(), word.end());
	cout << word;

	return 0;
}