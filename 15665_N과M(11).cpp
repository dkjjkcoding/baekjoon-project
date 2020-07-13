#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define MAX 7
#pragma warning(disable:4996)
using namespace std;

int n,m,temp;
vector<int> v;
map<int,int> cnt;
int point[MAX];

void dfs(int idx,int depth){
  if(depth==m){
    for(int i=0;i<m;i++)
      cout<<v[point[i]]<<' ';
    cout<<'\n';
    return;
  }
  for(int i=0;i<v.size();i++){
    if(cnt[v[i]]){
      point[idx]=i;
      dfs(idx+1,depth+1);
    }
  }
}

void solution(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>temp;
    if(!cnt.count(temp)){
      cnt[temp]=1;
      v.push_back(temp);
    }
    else
      cnt[temp]++;
  }
  sort(v.begin(),v.end());
  dfs(0,0);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
