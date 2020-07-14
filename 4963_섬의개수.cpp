#include<iostream>
#include<cstring> // to use 'memset'

#define MAX 50
#pragma warning(disable:4996)
using namespace std;

int w,h,cnt;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={-1,-1,0,1,1,1,0,-1};

void dfs(int idx,int jdx){ // dfs로 인접 노드(땅) 완전 탐색
  visited[idx][jdx]=true;
  
  for(int i=0;i<8;i++){
    int nx=idx+dx[i];
    int ny=jdx+dy[i];
    
    if(0<=nx&&nx<h&&0<=ny&&ny<w)
      if(map[nx][ny]&&!visited[nx][ny])
        dfs(nx,ny);
  }
}

void solution(){
  while(ture){
    cin>>w>>h;
    
    if(!w&&!h) break;
    
    for(int i=0;i<h;i++)
      for(int j=0;j<w;j++)
        cin>>map[i][j];
    
    cnt=0;
    for(int i=0;i<h;i++)
      for(int j=0;j<w;j++)
        if(map[i][j]&&!visited[i][j]){
          cnt++;
          dfs(i,j);
        }
    
    memset(visited,false,sizeof(visited));
    cout<<cnt<<'\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
