#include<iostream>
#include<algorithm>

#define MAX 1000
#pragma warning(disable:4996)
using namespace std;

int n;
int inp[MAX];
int dp[MAX],rdp[MAX];

void solution(){
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>inp[i];
  
  for(int i=0;i<n;i++){
    dp[i]=1;
    for(int j=i-1;j>=0;j--){
      if(inp[j]<inp[i]&&dp[j]+1>dp[i])
        dp[i]=dp[j]+1;
    }
  }
  for(int i=n-1;i>=0;i--){
    rdp[i]=1;
    for(int j=i+1;j<n;j++){
      if(inp[j]<inp[i]&&rdp[j]+1>rdp[i])
        rdp[i]=rdp[j]+1;
    }
  }
  
  for(int i=0;i<n;i++)
    dp[i]=dp[i]+rdp[i]-1;
  
  cout<<*max_element(dp,dp+n);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
