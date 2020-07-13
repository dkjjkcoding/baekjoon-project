#include<iostream>
#include<queue> // for BFS
#include<cstring> // to use memset

#define MAX 1000+1
#pragma warning(disable:4996)
using namespace std;

int n,m,v;
bool connected[MAX][MAX];
bool visited[MAX];

void dfs(int v){
  cout<<v<<' ';
  visited[v]=true;
  for(int i=1;i<=n;i++){
    if(visited[i]||!connected[v][i]) continue;
    dfs(i);
  }
}

void bfs(int v){
  queue<int> q;
  q.push(v);
  visited[v]=true;
  while(!q.empty()){
    v=q.front(); q.pop();
    cout<<v<<' ';
    for(int i=1;i<=n;i++){
      if(visited[i]||!connected[v][i]) continue;
      visited[i]=true;
      q.push(i);
    }
  }
}

void solution(){
  int x,y;
  
  cin>>n>>m>>v;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    connected[x][y]=connected[y][x]=true;
  }
  dfs(v);
  cout<<'\n';
  memset(visited,false,sizeof(visited));
  bfs(v);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
