#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

#define MAX 1000+1
#pragma warning(disable:4996)
using namespace std;

int n,m;
bool connected[MAX][MAX];
bool visited[MAX];
queue<int> q;

void bfs(int v){
  visited[v]=true;
  q.push(v);
  
  while(!q.empty()){
    v=q.front(); q.pop();
    
    for(int i=1;i<=n;i++){
      if(visited[i]||!connected[v][i]) continue;
      visited[i]=true;
      q.push(i);
    }
  }
}

void solution(){
  int x,y,cnt=0;
  
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    connected[x][y]=connected[y][x]=true;
  }
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      cnt++;
      bfs(i);
    }
  }
  cout<<cnt;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
