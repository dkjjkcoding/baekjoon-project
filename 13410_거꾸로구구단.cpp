#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n, k;
	int* arr;
	string temp;

	cin >> n >> k;
	
	arr = new int[k];

	for (int i = 1;i <= k;i++)
	{
		temp = to_string(n * i);
		reverse(temp.begin(), temp.end());
		arr[i - 1] = atoi(temp.c_str());
	}

	cout << *max_element(arr, arr + k);

	delete arr;

	return 0;
}