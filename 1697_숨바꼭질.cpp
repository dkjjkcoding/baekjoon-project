#include<iostream>
#include<queue>

#define MAX 100000+1
#pragma warning(disable:4996)
using namespace std;

int n,k;
bool visited[MAX];

void bfs(){
  queue<pair<int,int>> q;
  q.push(make_pair(n,0));
  visited[n]=true;
  
  while(!q.empty()){
    int idx=q.front().first;
    int sec=q.front().second;
    q.pop();
    
    if(idx==k){ // 가장 먼저 도착한 pair에 의해 리턴
      cout<<sec;
      return;
    }
    
    int nx;
    
    nx=idx-1;
    if(0<=nx&&nx<MAX){
      if(!visited[nx]){
        visited[nx]=true;
        q.push(make_pair(nx,sec+1));
      }
    }
    
    nx=idx+1;
    if(0<=nx&&nx<MAX){
      if(!visited[nx]){
        visited[nx]=true;
        q.push(make_pair(nx,sec+1));
      }
    }
    
    n=idx*2;
    if(nx<MAX){ // 양수 곱하므로 항상 0보다 크거나 같다.
      if(!visited[nx]){
        visited[nx]=true;
        q.push(make_pair(nx,sec+1));
      }
    }
  }
}
    

void solution(){
  cin>>n>>k;
  bfs();
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
