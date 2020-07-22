#include<iostream>

#defin MAX 1000+1
#pragma warning(disable:4996)
using namespace std;

int n;
int d[MAX];

void solution(){
  cin>>n;
  
  d[1]=1,d[2]=3;
  for(int i=3;i<=n;i++){
    d[i]=(d[i-1]+2*d[i-2])%10007;
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
