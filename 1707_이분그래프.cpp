#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 20000+1
#define RED 1
#define BLUE 2
#pragma warning(disable:4996)
using namespace std;

int k,v,e;
vector<int> graph[MAX];
int nodecolor[MAX];

void bfs(int idx){
  queue<int> q;
  int color=RED;
  
  nodecolor[idx]=color;
  q.push(idx);
  while(!q.empty()){
    int now=q.front(); q.pop();
    
    color=(nodecolor[now]==RED)?BLUE:RED;
    
    int gsize=graph[now].size();
    for(int i=0;i<gsize;i++){
      int next=graph[now][o];
      if(!nodecolor[next]){
        nodecolor[next]=color;
        q.push(next);
      }
    }
  }
}

bool isBipartiteGraph(){
  for(int i=1;i<=v;i++){
    int gsize=graph[i].size();
    for(int j=0;j<gsize;j++){
      int next=graph[i][j];
      if(nodecolor[i]==nodecolor[next])
        return false;
    }
  }
  return true;
}

void solution(){
  cin>>k;
  while(k--){
    cin>>v>>e;
    for(int i=0;i<e;i++){
      inf a,b;
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    for(int i=1;i<=v;i++)
      if(!nodecolor[i])
        bfs(i);
    if(isBipartiteGraph()) cout<<"YES\n";
    else cout<<"NO\n";
    
    for(int i=1;i<=v;i++)
      graph[i].clear();
    memset(nodecolor,0,sizeof(nodecolor));
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
