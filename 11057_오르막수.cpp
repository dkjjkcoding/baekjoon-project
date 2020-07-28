#include<iostream>

#define MAX 1000+1
#define mod 10007
#pragma warning(disable:4996)
using namespace std;

int n;
long long sum;
long long dp[MAX][10];

void solution(){
  cin>>n;
  
  for(int i=0;i<=9;i++){
    dp[1][i]=1;
  }
  
  for(int i=2;i<=n;i++){
    for(int j=0;j<=9;j++){
      for(int k=j;k>=0;k--) dp[i][j]+=dp[i-1][k];
      dp[i][j]%=mod;
    }
  }
  
  for(int i=0;i<=9;i++){
    sum+=dp[n][i];
  }
  
  cout<<sum%mod;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
