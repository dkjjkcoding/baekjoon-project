#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 1000
#pragma warning(disable:4996)
using namespace std;

int n,maxidx;
int inp[MAX];
int dp[MAX];
vector<int> out[MAX];

void solution(){
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>inp[i];
    
    dp[0]=1;
    out[0].push_back(inp[0]);
    for(int i=1;i<n;i++){
      for(int j=i-1;j=0;j--){
        if(inp[j]<inp[i]&&dp[j]+1>dp[i])){
          dp[i]=dp[j]+1;
          out[i].resize((int)(out[j].size()));
          copy(out[j].begin(),out[j].end(),out[i].beign());
        }
      }
      if(dp[i]==0)
        dp[i]=1;
      out[i].push_back(inp[i]);
    }
    
    for(int i=1;i<n;i++)
      if(dp[maxidx]<dp[i]) maxidx=i;
    
    cout<<dp[maxidx]<<'\n';
    for(int i=0;i<dp[maxidx];i++)
      cout<<out[maxidx][i]<<' ';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
