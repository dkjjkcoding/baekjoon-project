#include<iostream>
#include<string>

#define MAX 7
#pragma warning(disable:4996)
using namespace std;

int n,m;
int a[]={1,2,3,4,5,6,7,8};

void dfs(string out,int depth){
  if(depth==m){
    for(char c:out)
      cout<<c<<' ';
    cout<<'\n';
    return;
  }
  for(int i=0;i<n;i++){
    out+=to_string(a[i]);
    dfs(out,depth+1);
    out=out.substr(0,out.length()-1);
  }
}

void solution(){
  cin>>n>>m;
  dfs("",0);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
