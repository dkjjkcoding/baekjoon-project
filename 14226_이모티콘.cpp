#include<iostream>
#include<queue>

#define MAX 1000+1
#pragma warning(disable:4996)
using namespace std;

struct component{
  int display, clipboard, second;
}

int s;
bool visited[MAX][MAX]; // [화면][클립보드] - 각 상황들

void bfs(){
  queue<component> q; // int 3개 저장 필요 -> 구조체 활용
  q.push({1,0,0}); // { 값, ... }으로 구조체 초기화 가능
  visited[1][0]=true;
  
  while(!q.empty()){
    int dis=q.front().display;
    int board=q.front().clipboard;
    int sec=q.front().second;
    q.pop();
    
    if(dis==s){
      cout<<sec;
      return;
    }
    
    // 화면에서 복사하고 클립보드에 저장 :: board=display (할당)
    if(0<dis&&dis<MAX){ // 화면에 1개 이상 있어야 복사
      if(!visited[dis][dis]){ // 화면 값 할당되므로 클립보드 자리에 dis (다음 연산을 위해 board 자체를 바꿀 수 없음)
        visited[dis][dis]=true;
        q.push({dis,dis,sec+1});
      }
    }
    
    // 클립보드에서 화면으로 붙여넣기 :: display=display+board (추가)
    if(0<board&&dis+board<MAX){
      if(!visited[dis+board][board]){
        visited[dis+board][board]=true;
        q.push({dis+board,board,sec+1});
      }
    }
    
    // 화면에서 1개 삭제
    if(0<dis){
      if(!visited[dis-1][board]){
        visited[dis-1][board]=true;
        q.push({dis-1,board,sec+1});
      }
    }
  }
}

void solution(){
  cin>>s;
  bfs();
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
