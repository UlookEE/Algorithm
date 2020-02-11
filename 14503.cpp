#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;

int N, M;
int y, x, d;
int arr[51][51];
int visited[51][51];

inline bool in_range(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < M;
}
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	cin >> y >> x >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int failcount = 0;
	if (arr[y][x] == 0) {
		visited[y][x] = true;
		while (true) {
			int next_d = (d + 3) % 4;
			int ny = y + dy[next_d];
			int nx = x + dx[next_d];
			if (failcount == 4) {
				int back_d = (d + 2) % 4;
				int bny = y + dy[back_d];
				int bnx = x + dx[back_d];
				if (in_range(bny, bnx) && arr[bny][bnx] == 0) {
					y = bny;
					x = bnx;
					failcount = 0;
					continue;
				}
				else {
					break;
				}
			}
			if (in_range(ny, nx) && !visited[ny][nx] && arr[ny][nx] == 0) {
				failcount = 0;
				d = next_d;
				y = ny;
				x = nx;
				visited[ny][nx] = true;
			}
			else {
				failcount++;
				d = next_d;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
