#include<iostream>

#define MAX 100000+1
#pragma warning(disable:4996)
using namespace std;

const long long MOD=1000000009LL;

struct datatype{
  long long one,tow,three;
};

long long t,n;
datatype dp[MAX];

void solution(){
  dp[1]={1,0,0};
  dp[2]={0,1,0};
  dp[3]={1,1,1};
  for(int i=4;i<MAX;i++){
    dp[i]={(dp[i-1].two+dp[i-1].three)%MOD,(dp[i-2].one+dp[i-2].three)%MOD,(dp[i-3].one+dp[i-3].two)%MOD};
  }
  
  cin>>t;
  while(t--){
    cin>>n;
    cout<<(dp[n].one+dp[n].two+dp[n].three)%MOD<<'\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
