#include<iostream>
#include<cstring>

#define MAX 500
#pragma warning(disable:4996)
using namespace std;

int n, m, result;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void input() {
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> map[i][j];
}

void dfs(int x, int y, int sum, int depth) {
	visit[x][y] = true;

	if (depth == 3) {
		result = result > sum ? result : sum;
		return;
	}

	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visit[nx][ny] == true) continue;

		dfs(nx, ny, sum + map[nx][ny], depth + 1);
		visit[nx][ny] = false;
	}
}

void shape1(int x, int y) {
	int tempSum = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x][y + 2];
	if (tempSum > result)
		result = tempSum;
}

void shape2(int x, int y) {
	int tempSum = map[x][y] + map[x + 1][y + 1] + map[x][y + 1] + map[x][y + 2];
	if (tempSum > result)
		result = tempSum;
}

void shape3(int x, int y) {
	int tempSum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
	if (tempSum > result)
		result = tempSum;
}

void shape4(int x, int y) {
	int tempSum = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x + 1][y + 1];
	if (tempSum > result)
		result = tempSum;
}

void solution() {
	for(int i=0;i<n;i++)
		for (int j = 0;j < m;j++) {
			memset(visit, false, sizeof(visit));
			dfs(i, j, map[i][j], 0);
			if (i - 1 >= 0 && j + 2 < m) shape1(i, j);
			if (i + 1 < n && j + 2 < m) shape2(i, j);
			if (i + 2 < n && j + 1 < m) shape3(i, j);
			if (i - 1 >= 0 && i + 1 < n && j + 1 < m) shape4(i, j);
		}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	solution();

	cout << result << '\n';

	return 0;
}