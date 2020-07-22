#include<iostream>
#include<algorithm>

#define MAX 1000000+1
#pragma warning(disable:4996)
using namespace std;

int n;
int d[MAX];

void solution(){
  cin>>n;
  
  d[1]=0;
  for(int i=2;i<=n;i++){
    d[i]=d[i-1]+1;
    if(i%2==0)
      d[i]=min(d[i],d[i/2]+1);
    if(i%3==0)
      d[i]=min(d[i],d[i/3]+1);
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
