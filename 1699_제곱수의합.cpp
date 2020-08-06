#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX 100000+1
#pragma warning(disable:4996)
using namespace std;

int n;
int dp[MAX];

void solution(){
  cin>>n;
  
  dp[1]=1;
  for(int i-2;i<=n;i++){
    dp[i]=dp[i-1*1]+1;
    for(int j=2;j<=sqrt(i);j++){
      dp[i]=min(dp[i],dp[i-j*j]+1);
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
