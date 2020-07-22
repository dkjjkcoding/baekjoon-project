#include<iostream>
#include<queue>

#define MAX 50
#pragma warning(disable:4996)
using namespace std;

int r,c;
int st_idx,st_jdx,dt_idx,dt_jdx;
char map[MAX][MAX];
int water[MAX][MAX]; // 물 이동(확장) 시간 - 각 칸에 도착했을 때의 시간
int hedgehog[MAX][MAX]; // 고슴도치 이동 시간 - 각 칸에 도착했을 때의 시간
queue<pair<int,int>> w;
queue<pair<int,int>> q;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void water_bfs(){
  while(!w.empty()){
    int idx=w.front().first;
    int jdx=w.front().second;
    w.pop();
    
    for(int i=0;i<4;i++){
      int nx=idx+dx[i];
      int ny=jdx+dy[i];
      
      if(0<=nx&&nx<r&&0<=ny&&ny<c){
        if(map[nx][ny]=='X'||map[nx][ny]=='D') continue;
        if(water[nx][ny]==0&&map[nx][ny]!='*'){
          water[nx][ny]=water[idx][jdx]+1;
          w.push(make_pair(nx,ny));
        }
      }
    }
  }
}

void bfs(){
  q.push(make_pair(st_idx,st_jdx));
  
  while(!q.empty()){
    int idx=q.front().first;
    int jdx=q.front().second;
    q.pop();
    
    for(int i=0;i<4;i++){
      int nx=idx+dx[i];
      int ny=jdx+dy[i];
      
      if(0<=nx&&nx<r&&0<=ny&&ny<c){
        if(map[nx][ny]=='X'||map[nx][ny]=='*') continue;
        if(hedgehog[nx][ny]==0&&map[nx][ny]!='S'){
          if(water[nx][ny]==0){ // 물이 오지 않음
            hedgehog[nx][ny]=hedgehog[idx][jdx]+1;
            q.push(make_pair(nx,ny));
          }
          else if(hedgehog[idx][jdx]+1<water[nx][ny]){ // 물이 오지만 고슴도치보다 늦게 옴
            hedgehog[nx][ny]=hedgehog[idx][jdx]+1;
            q.push(make_pair(nx,ny));
          }
        }
      }
    }
  }
}

void solution(){
  string temp;
  char tmp;
  
  cin>>r>>c;
  for(int i=0;i<r;i++){
    cin>>temp;
    for(int j=0;j<c;j++){
      tmp=temp[i];
      if(tmp=='S') { st_idx=i; st_jdx=j; }
      else if(tmp=='D') { dt_idx=i; dt_jdx=j; }
      else if(tmp=='*') { w.push(make_pair(i,j)); }
      map[i][j]=tmp;
    }
  }
  
  water_bfs(); // 물 이동 시간 먼저 구한 후
  bfs(); // 물 시간과 비교해가며 고슴도치 이동
  
  if(hedgehog[dt_idx][dt_jdx]) // 0이면 D에 도착하지 못한 것
    cout<<hedgehog[dt_idx][dt_jdx]<<'\n';
  else
    cout<<"KAKTUS\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
