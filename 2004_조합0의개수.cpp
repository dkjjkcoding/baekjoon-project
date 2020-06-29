#include<iostream>
#pragma warning(disable:4996)
using namespace std;

// int�� ǥ�������� �� -21��~21�� -> ��� ���������� ǥ�������� ���� �� �־ long long ���
//nCm=n!/m!(n-m)!


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int two = 0, five = 0;

	cin >> n >> m;

	for (long long i = 2;i <= n;i *= 2)	// n,n-1,n-2,...,1�� ��� �� 2�� ���� ������.
		two += (n / i);					//
	for (long long i = 2;i <= m;i *= 2)
		two -= (m / i);
	for (long long i = 2;i <= n;i *= 2)
		two -= ((n - m) / i);
	
	for (long long i = 5;i <= n;i *= 5)
		five+= (n / i);
	for (long long i = 5;i <= m;i *= 5)
		five -= (m / i);
	for (long long i = 5;i <= n;i *= 5)
		five -= ((n - m) / i);
	
	cout << (two < five ? two : five) << '\n';

	return 0;
}