#include<iostream>
#include<algorithm>

#define MAX 1000
#pragma warning(disable:4996)
using namespace std;

int n;
int inp[MAX];
int dp[MAX];

void solution(){
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>inp[i];
  
  dp[0]=1;
  for(int i=1;i<n;i++){
    for(int j=i-1;j>=0;j--){
      int temp=dp[j]+1;
      if(inp[j]>inp[i]&&temp>dp[i])
        dp[i]=temp;
    }
    if(dp[i]==0)
      dp[i]=1;
  }
  
  cout<<*max_element(dp,dp+n);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
