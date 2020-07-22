#include<iostream>
#include<queue>

#define MAX 100 // (0,0)->(n-1,m-1)
#define INFIN 987654321
#pragma warning(disable:4996)
using namespace std;

int n,m;
int maze[MAX][MAX];
int count[MAX][MAX];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(){
  queue<pair<int,int>> q;
  q.push(make_pair(0,0));
  count[0][0]=0;
  
  while(!q.empty()){
    int idx=q.front().first;
    int jdx=q.front().second;
    q.pop();
    
    for(int i=0;i<4;i++){
      int nx=idx+dx[i];
      int ny=jdx+dy[i];
      
      if(0<=nx&&nx<n&&0<=ny&&ny<m){
        if(maze[nx][ny]==1&&count[nx][ny]>count[idx][jdx]+1){
          count[nx][ny]=count[idx][jdx]+1;
          q.push(make_pair(nx,ny));
        }
        else if(maze[nx][ny]==0&&count[nx][ny]>count[idx][jdx]){
          count[nx][ny]=count[idx][jdx];
          q.push(make_pair(nx,ny));
        }
      }
    }
  }
}

void solution(){
  string temp;
  
  cin>>m>>n; // m,n 순서 유의.
  for(int i=0;i<n;i++){
    cin>>temp;
    for(int j=0;j<m;j++){
      maze[i][j]=temp[j]-'0';
      count[i][j]=INFIN;
    }
  }
  
  bfs();
  
  cout<<count[n-1][m-1];
}
  
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
