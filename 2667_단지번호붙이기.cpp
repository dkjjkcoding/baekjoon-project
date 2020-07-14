#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 25
#pragma warning(disable:496)
using namespace std;

int n,cnt;
string homes[MAX];
bool visited[MAX][MAX];
vector<int> ans;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int idx,int jdx){
  visited[idx][jdx]=true;
  cnt++;
  for(int i=0;i<4;i++){
    int nx=idx+dx[i];
    int ny=jdx+dy[i];
    
    if(0<=nx&&nx<n&&0<=ny&&ny<n)
      if(homes[nx][ny]=='1'&&!visited[nx][ny])
        dfs(nx,ny);
  }
}

void solution(){

  // 입력받기
  
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>homes[i];
    
  // 단지번호 부여하면서 번호 아파트 수 세기.
  // cnt는 0으로 맞춰놓고 dfs에서 증가시킴.
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(homes[i][j]=='1'&&!visited[i][j]){
        cnt=0;
        dfs(i,j);
        ans.push_back(cnt);
      }
      
  // 오름차순 정렬
  
  sort(ans.begin(),ans.end());
  
  // 출력 - 벡터 ans의 사이즈가 단지 수.
  
  cout<<ans.size()<<'\n';
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solution();
  
  return 0;
}
