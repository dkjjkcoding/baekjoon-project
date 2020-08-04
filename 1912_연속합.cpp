#include<iostream>
#include<algorithm>

#define MAX 100000
#pragma warning(disable:4996)
using namespace std;

int n,ans;
int inp[MAX];
int dp[MAX]; // max value including itself

void solution(){
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>inp[i];
  
  dp[0]=inp[0];
  ans=dp[0];
  for(int i=1;i<n;i++){
    dp[i]=max(dp[i-1]+inp[i],inp[i]);
    ans=max(ans,dp[i]);
  }
  
  cout<<ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
