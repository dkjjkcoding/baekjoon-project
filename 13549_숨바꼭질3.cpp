#include<iostream>
#include<vector>
#include<functional> //**
#include<queue> // to use priority_queue

#define MAX 100000+1
#pragma warning(disable:4996)
using namespace std;

int n,k;
bool visited[MAX];

void bfs(){
  // *2일때 0sec 걸려 더 빠른데도, 일반 큐에 넣으면 +1, -1이 먼저 종료조건에 도달.
  // 따라서 우선순위 큐 사용 - sec이 작을 수록 우선순위 높다.
  
  // 우선순위 큐는 큰 값이 위로 오는 것이 default
  // greater은 큰 게 앞에 오는 내림차순이지만, 우선순위 큐에서는 오름차순이 됨. - 누가 좀 알려주세요.,,
  // priority_queue<데이터타입, 데이터타입에 대한 컨테이너(default는 vector), 데이터타입에 대한 크기 함수>
  
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push(make_pair(0,n)); // sec으로 우선순위 결정하므로 pair은 < second, position >이 됨
  visited[n]=true; // 해당 상황 겪음.
  
  while(!pq.empty()){
    int sec=pq.top().first; // 우선순위 큐는 top() 사용 - front() X
    int idx=pq.top().second;
    pq.pop();
    
    if(idx==k){ // 먼저 (가장 빨리) 온 pair에 의해 리턴
      cout<<sec;
      return;
    }
    
    int nx;
    
    // 순서는 *2(0sec) -> +1(1sec) -> -1(1sec). - 누가 좀 알려주세요.,,
                                                - 아마 순간 이동이 종료조건 더 빨리 도착하려고.?
    
    nx=idx*2;
    if(nx<MAX&&!visited[nx]){
      visited[nx]=true;
      pq.push(make_pair(sec,nx));
    }
    
    nx=idx+1;
    if(0<=nx&&nx<MAX&&!visited[nx]){
      visited[nx]=true;
      pq.push(make_pair(sec+1,nx));
    }
    
    nx=idx-1;
    if(0<=nx&&nx<MAX&&!visited[nx]){
      visited[nx]=true;
      pq.push(make_pair(sec+1,nx));
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
