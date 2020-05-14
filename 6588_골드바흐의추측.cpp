#include<iostream>
#pragma warning(disable:4996)
using namespace std;

// ���� ���� �ڵ� �ʱ�ȭ
// MAX�� �Ҽ� �ƴϹǷ� ������� �ʴ´�

const int MAX = 1000000;
int che[MAX]; // �Ҽ� �迭
int cnt; // �Ҽ� ����
bool prim[MAX]; // �Ҽ� ���� :: �Ҽ� false �ƴϸ� true

// �ð����⵵: cin, cout > scanf, printf
// ���� scanf, printf �� ���巢

int main()
{
	int n;
	bool found;

	// �����佺�׳׽��� ü
	for (int i = 2;i * i <= MAX;i++) // ���ǽ� i<=sqrt(MAX) �� ������ �ð� �����ؼ� ���ϱ�� ����.
	{ 
		if (prim[i] == false) {
			che[cnt++] = i; // che[0] = 2 :: ������ ¦�� �Ҽ�
			for (int j = i + i;j <= MAX;j += i)
				prim[j] = true;
		}
	}
	while (1)
	{
		scanf("%d", &n);
		if (n <= 4)
			break;
		
		found = false;
		for (int i = 1;i < cnt;i++) { // prim[0]�� 2�ϱ� prim[1]���� ���
			if (prim[n - che[i]] == false) {
				found = true;
				printf("%d = %d + %d\n", n, che[i], n - che[i]); // i != che[i]
				break;
			}
		}
		if (!found)
			printf("Goldbach's conjecture is wrong.");
	}

	// prim[i] == �Ҽ�����(i)
	// BUT, che[i] != i ����

	return 0;
}