#include<iostream>

#define MAX 1000+1
#pragma warning(disable:4996)
using namespace std;

int n;
int d[MAX];

void solution(){
  cin>>n;
  
  d[1]=1, d[2]=2;
  for(int i=3;i<=n;i++){
    d[i]=(d[i-1]+d[i-2])%10007; // 왜 모든 값에 %10007 적용하는 지 의문. 결과 출력할 때만 하면 안되나요.?
  }
  
  cout<<d[n];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
