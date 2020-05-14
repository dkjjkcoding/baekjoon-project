#include<iostream>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;

bool isPrimeNumber(int num) {
	if (num == 1) // 1�� �Ҽ� �ƴ�
		return false;
	else if (num == 2 || num == 3) // �������� 1�� ���� 1,2,3
		return true;
	else {
		for (int i = 2;i < sqrt(num)+1;i++) {
			if (num % i == 0)
				return false;
		}
	}
	return true;
}

int main()
{
	int n;
	int num, cnt;
	
	cin >> n;
	
	cnt = 0;
	while (n--) {
		cin >> num;
		if (isPrimeNumber(num))
			cnt++;
	}

	cout << cnt;

	return 0;
}