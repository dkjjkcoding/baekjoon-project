#include<iostream>
#include<cstring>
#include<vector>

#define MAX 2000+1
#pragma warning(disable:4996)
using namespace std;

int n,m;
bool visited[MAX];
bool answer;
vector<int> v[MAX];

void dfs(int idx,int depth){
  if(depth==4){
    answer=true;
    return;
  }
  visited[idx]=true;
  for(long long i=0;i<v[idx].size();i++){
    int jdx=v[idx][i];
    if(!visited[jdx]) dfs(jdx,depth+1);
    if(answer) return;
  }
  visited[idx]=false;
}

void solution(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  
  for(int i=0;i<n;i++){
    memset(visited,false,sizeof(visited));
    dfs(i,0)l
    if(answer) break;
  }
  cout<<int(answer);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
