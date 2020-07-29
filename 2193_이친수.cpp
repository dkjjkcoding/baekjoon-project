#include<iostream>

#define MAX 90+1
#pragma warning(disable:4996)
using namespace std;

int n;
long long dp[MAX];

void solution(){
  cin>>n;
  
  dp[1]=dp[2]=1;
  for(int i=3;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
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
