#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define MAX 8
#pragma warning(disable:4996)
using namespace std;

int n,m;
int a[MAX];
bool visited[MAX];
vector<int> v;

void dfs(int depth){
  if(depth==m){
    for(int i=0;i<v.size();i++)
      cout<<v[i]<<' ';
    cout<<'\n';
    return;
  }
  for(int i=0;i<n;i++){
    if(visited[i]) continue;
    visited[i]=true;
    v.push_back(a[i]);
    dfs(depth+1);
    visited[i]=false;
    v.pop_back();
  }
}

void solution(){
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a,a+n);
  dfs(0);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
