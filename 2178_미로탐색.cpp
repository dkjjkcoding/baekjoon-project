#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>

#define MAX 100
#pragma warning(disable:4996)
using namespace std;

int n,m;
string map[MAX]; // 붙어서 입력됨
int pathnum[MAX][MAX]; // 해당 지점 도달 시 지나온 정점 수(본인 포함)

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0}; // 위, 오른, 아래, 왼

void bfs(){
  queue<pair<int,int>> q;
  q.push(make_pair(0,0));
  
  while(!q.empty()){
    int idx=q.front().first;
    int jdx=q.front().second;
    q.pop();
    
    pathnum[idx][jdx]++;
    
    for(int i=0;i<4;i++){
      int nx=idx+dx[i];
      int ny=jdx+dy[i];
      
      if(0<=nx&&nx<n&&0<=ny&&ny<m){ // 범위 지정
        if(map[nx][ny]=='1'){
          if(pathnum[nx][ny]==0){
            pathnum[nx][ny]=pathnum[idx][jdx];
            q.push(make_pair(nx,ny));
          }
          else
            pathnum[nx][ny]=min(pathnum[nx][ny],pathnum[idx][jdx]);
        }
      }
    }
  }
}

void solution(){
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>map[i];
    
    bfs(); // dfs보다 bfs가 속도 빠름. (dfs 구현 시 시간 초과 나옴)
    
    cout<<pathnum[n-1][m-1];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
