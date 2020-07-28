#include<iostream>

#define MAX 100+1
#define mod 1000000000
#pragma warning(disable:4996)
using namespace std;

int n;
long long sum;
long long dp[MAX][10]; 0 ~ 9 for each n

void solution(){
  for(int i=1;i<=9;i++){
    dp[1][i]=1;
  }
  
  cin>>n;
  
  for(int i=2;i<=n;i++){
    for(int j=0;j<=9;j++){
      if(i==0) dp[i][j]=dp[i-1][1]%mod;
      else if(i==9) dp[i][j]=dp[i-1][8]%mod;
      else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
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
