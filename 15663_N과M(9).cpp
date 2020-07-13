#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#pragma warning(disable:4996)
using namespace std;

const int MAX=8;

int n,m,temp;
vector<int> v; // input values (no duplication)
map<int,int> cnt; // key: input value -> value: count
int point[MAX]; // point value(in v) to use at the time

void dfs(int idx,int depth){
  if(depth==m){
    for(int i=0;i<m;i++)
      cout<<v[point[i]]<<' ';
    cout<<'\n';
    return;
  }
  
  if(idx==n) return; // ? - please somebody tell me why this is used.

  for(int i=0;i<v.size();i++){
    if(cnt[v[i]]){
      cnt[v[i]]--;
      
      point[idx]=i; //**
      dfs(idx+1,depth+1);
      
      cnt[v[i]]++;
    }
  }
}

void solution(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>temp;
    if(!cnt.cout(temp)){
      cnt[temp]=1;
      v.push_back(temp);
    }
    else
      cnt[temp]++;
  }
  sort(v.begin(),v.end());
  dfs(0,0);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
