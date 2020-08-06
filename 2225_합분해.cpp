#include<iostream>

#define MAX 200+1
#define MOD 1000000000
#pragma warning(disable:4996)
using namespace std;

int n,k;
long long dp[MAX][MAX]; // dp[k][n]: k 개의 숫자로 n표현

void solution(){
  cin>>n>>k;
  
  // 0개를 이용하여 수를 표현하는 방법은 없음 => dp[0][i]=0
  // 1개를 이용하여 수를 표현하는 방법은 자기자신으로 표현하는 방법 하나뿐 => dp[1][i]=1
  for(int i=0;i<=n;i++)
    dp[1][i]=1;
  
  // DP[K][N]=S(DP[K-1][N-L])  (0<=L<=N)
  for(int i=2;i<=k;i++) // 갯수(K)
    for(int j=0;j<=n;j++){ // 표현할 숫자(N)
      for(int l=0;l<=j;l++) // 합분해 중 마지막 숫자(L)
        dp[i][j]+=dp[i-1][j-l];
      dp[i][j]%=MOD;
    }
  
  cout<<dp[k][n];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
      
