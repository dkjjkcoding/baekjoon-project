#include<iostream>
#include<vector>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> v;
	string temp;
	int lower, upper, number, blank;

	while (1) {
		getline(cin, temp);
		if (temp == "")
			break;
		v.push_back(temp);
	}

	vector<string>::iterator it;
	for (it = v.begin();it != v.end();it++) {
		temp = *it;
		lower = 0, upper = 0, number = 0, blank = 0;
		for (int i = 0;i < temp.length();i++) {
			if (temp[i] == ' ')
				blank++;
			else if (48 <= temp[i] && temp[i] <= 57)
				number++;
			else if (65 <= temp[i] && temp[i] <= 90)
				upper++;
			else if (97 <= temp[i] && temp[i] <= 122)
				lower++;
			else {
				cout << "원하는 형식이 아닙니다." << endl;
				exit(1);
			}
		}
		cout << lower << ' ' << upper << ' ' << number << ' ' << blank << '\n';
	}

	return 0;
}