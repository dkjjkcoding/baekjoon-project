#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	string str; // char stc[1000];
	string word="";

	while (n--) {
		getline(cin, str); // cin.getline(stc,1000);
		for (int i = 0;i < str.length();i++) { // i<strlen(stc)
			if (str[i] == ' ') {
				reverse(word.begin(), word.end());
				cout << word << ' ';
				word = "";
			}
			else
				word += str[i];
		}
		reverse(word.begin(), word.end());
		cout << word << endl;
		word = "";
	}

	return 0;
}