#include<iostream>
#include<string>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	string str;
	stack<char>s;
	bool vps;

	while (t--) {
		cin >> str;
		vps = true;

		for (int i = 0;vps && i < str.length();i++) {
			if (str[i] == '(')
				s.push(str[i]);
			else if (s.empty())
				vps = false;
			else
				s.pop();
		}

		if (s.empty()&&vps)
			cout << "YES" << endl;
		else {
			cout << "NO" << endl;
			s = stack<char>();
		}
	}

	return 0;
}