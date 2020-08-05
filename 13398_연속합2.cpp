#include<iostream>
#include<algorithm>

#define MAX 100000
#pragma warning(disable:4996)
using namespace std;

int n,ans;
int inp[MAX];
int dp[MAX][2]; // dp는 각 상황에서의 최댓값, 0: 제거하지 않는 경우 1: 한 개를 제거하는 경우

void solution(){
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>inp[i];
    
  ans=inp[0]; // 한 개 이상 선택해야 하므로 n이 1일때 inp[0]가 답.
  for(int i=0;i<n;i++){
    dp[i][0]=dp[i][1]=inp[i];
    if(i==0) continue;
    dp[i][0]=max(dp[i-1][0]+inp[i],inp[i]);
    dp[i][1]=max(dp[i-1][0],dp[i-1]+inp[i]);
    ans=max(ans,max(dp[i][0],dp[i][1]));
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
    
