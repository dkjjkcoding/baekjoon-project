#include<iostream>
#include<list>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	string input;
	list<char> str;
	int  m;
	char $;

	cin >> input;
	for (int i = 0;i < input.length();i++)
		str.push_back(input[i]);
	list<char>::iterator curser = str.end();

	cin >> m;
	while (m--) {
		cin >> input;
		if (input == "L") {
			if (curser != str.begin())
				curser--;
		}
		else if (input == "D") {
			if (curser != str.end())
				curser++;
		}
		else if (input == "B") {
			if (curser != str.begin())
				curser = str.erase(--curser);
		}
		else if (input == "P") {
			cin >> $;
			str.insert(curser, $);
		}
	}

	for (curser = str.begin();curser != str.end();curser++)
		cout << *curser;
	cout << endl;

	return 0;
}