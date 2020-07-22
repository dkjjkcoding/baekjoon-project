#include<iostream>
#include<algorithm>

#define MAX 1000+1
#pragma warning(disable:4996)
using namespcae std;

int n;
int p[MAX],dp[MAX];

void solution(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>p[i];
  }
  
  for(int i=1;i<=n;i++){
    dp[i]=p[i];
    for(int j=1;j<i;j++){
      dp[i]=max(dp[i],dp[i-j]+p[j]); // 마지막에 몇 개 팩을 사느냐를 생각.
    }
  }
  
  cout<<dp[n];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}

