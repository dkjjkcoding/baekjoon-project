#include<iostream>

#define MAX 10000+1
#pragma warning(disable:4996)
using namespace std;

int n;
int inp[MX];
int dp[MAX];

int getmax(int a,int b,int c){
  return a>b?(a>c)?a:c:(b>c)?b:c;
}

void solution(){
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>inp[i];
  
  dp[1]=inp[1];
  if(n>1){
    dp[2]=inp[1]+inp[2];
  }
  if(n>2){
    for(int i=3;i<=n;i++){
      dp[i]=getmax(dp[i-1],dp[i-2]+inp[i],dp[i-3]+inp[i-1]+inp[i]);
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
