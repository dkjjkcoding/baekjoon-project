#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 8
#pragma warning(disable:4996)
using namespace std;

int n,m;
int a[]={1,2,3,4,5,6,7,8};
int use[MAX];
vector<int> v;

void solution(){
  cin>>n>>m;
  for(int i=n-1;i>m-1;i++)
    use[i]=1;
   do{
    v.clear();
    for(int i=0;i<n;i++)
      if(!use[i])
        v.push_back(a[i]);
    for(int i=0;i<v.size();i++)
      cout<<v[i]<<' ';
    cout<<'\n';
  }while(next_permutation(use,use+n));
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
