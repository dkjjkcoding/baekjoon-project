#include<iostream>
#include<algorithm> // to use max, max_element
#include<utility> // to use pair
#include<queue>

#define MAX 1000
#pragma warning(disable:4996)
using namespace std;

int n,m;
int boxes[MAX][MAX];
int days[MAX][MAX];
queue<pair<int,int>> q;

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0}; // up, right, down, left

void printall(){
  cout<<'\n';
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<days[i][j]<<' ';
    }
    cout<<'\n';
  }
}

void bfs(){
  while(!q.empty()){
    int idx=q.front().first;
    int jdx=q.front().second;
    q.pop();
    
    days[idx][jdx]++;
    
    for(int i=0;i<4;i++){
      int nx=idx+dx[i];
      int ny=jdx+dy[i];
      
      if(0<=nx&&nx<n&&0<=ny&&ny<m){
        if(boxes[nx][ny]==0){
          boxes[nx][ny]=1;
          days[nx][ny]=days[idx][jdx];
          q.push(make_pair(nx,ny));
        }
      }
    }
    
    // printall() // call to overall state
  }
}

bool allripen(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(boxes[i][j]==0)
        return false;
    }
  }
  return true;
}

void solution(){
  // input(initialize)
  cin>>m>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>boxes[i][j];
      if(boxes[i][j]==1){
        q.push(make_pair(i,j));
      }
    }
  }
  
  // ripen
  bfs();
  
  //check and output - day(can be 0) or -1(unable to ripen for all)
  if(allripen()){
    int maxv=0;
    for(int i=0;i<n;i++)
      maxv=max(maxv,*max_element(days[i],days[i]+m));
    cout<<maxv-1;
  }
  else
    cout<<-1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
