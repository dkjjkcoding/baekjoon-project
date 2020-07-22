#include<iostream>
#include<string>
#include<queue>

#define MAX 1000 // (0,0)->(n-1,m-1)
#pragma warning(disable:4996)
using namespace std;

int n,m;
int map[MAX][MAX];
bool visited[MAX][MAX][2]; // 각 상황(x,y,broken)에 대해 방문 여부

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int bfs(){
  queue<pair<pair<int,int>,pair<int,int>>> q; // <x,y>,<broken,count>
  q.push(make_pair(make_pair(0,0),make_pair(0,1)); // 1부터 시작
  visited[0][0][0]=true;
  
  while(!q.empty()){
    int x=q.front().first.first;
    int y=q.front().first.second;
    int b=q.front().second.first;
    int cnt=q.front().second.second;
    q.pop();
    
    if(x==n-1&&y==m-1){ // '최단 경로'인 경우가 가장 먼저 도착.
      return cnt;
    }
    
    for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      
      if(0<=nx&&nx<n&&0<=ny&&ny<m){
        if(map[nx][ny]==1&&b==0){
          visited[nx][ny][b+1]=true;
          q.push(make_pair(make_pair(nx,ny),make_pair(b+1,cnt+1)));
        }
        else if(map[nx][ny]==0&&!visited[nx][ny][b]){
          visited[nx][ny][b]=true;
          q.push(make_pair(make_pair(nx,ny),make_pair(b,cnt+1)));
        }
      }
    }
  }
  
  return -1;
}

void solution(){
  string temp;

  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>temp;
    for(int j=0;j<m;j++){
      map[i][j]=temp[j]-'0';
    }
  }
  
  cout<<bfs();
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
