#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#pragma warning(disable:4996)
using namespace std;

const int MAx=8;

int n,m,temp;
vector<int> v;
map<int,int> cnt;
int point[MAX]; //**

void dfs(int idx,int jdx,int depth){
  if(depth==m){
    for(int i=0;i<m;i++)
      cout<<v[point[i]]<<' ';
    cout<<'\n';
    return;
  }
  for(int i=jdx;i<v.size();i++){
    if(cnt[v[i]]){
      cnt[v[i]]--;
      
      point[idx]=i; //**
      dfs(idx+1,i,depth+1);
      
      cnt[v[i]]++;
    }
  }
}

void solution(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>temp;
    if(!cnt.count(temp)){
      cnt[temp]=1;
      v.push_back(temp);
    }
    else
      cnt[temp]++;
  }
  sort(v.begin(),v.end());
  dfs(0,0,0);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
