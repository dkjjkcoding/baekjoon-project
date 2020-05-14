#include<iostream>
#pragma warning(disable:4996)
using namespace std;

// 전역 변수 자동 초기화
// MAX는 소수 아니므로 고려하지 않는다

const int MAX = 1000000;
int che[MAX]; // 소수 배열
int cnt; // 소수 개수
bool prim[MAX]; // 소수 판정 :: 소수 false 아니면 true

// 시간복잡도: cin, cout > scanf, printf
// 따라서 scanf, printf 더 권장랙

int main()
{
	int n;
	bool found;

	// 에라토스테네스의 체
	for (int i = 2;i * i <= MAX;i++) // 조건식 i<=sqrt(MAX) 와 같은데 시간 생각해서 곱하기로 선택.
	{ 
		if (prim[i] == false) {
			che[cnt++] = i; // che[0] = 2 :: 유일한 짝수 소수
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
		for (int i = 1;i < cnt;i++) { // prim[0]은 2니까 prim[1]부터 고려
			if (prim[n - che[i]] == false) {
				found = true;
				printf("%d = %d + %d\n", n, che[i], n - che[i]); // i != che[i]
				break;
			}
		}
		if (!found)
			printf("Goldbach's conjecture is wrong.");
	}

	// prim[i] == 소수판정(i)
	// BUT, che[i] != i 주의

	return 0;
}