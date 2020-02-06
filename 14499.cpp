#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

int N, M, x, y, K;
int arr[21][21];
inline bool in_range(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < M;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,-1,1 };

	int dice[4][3] =
	{
		0,0,0,
		0,0,0,
		0,0,0,
		0,0,0
	};

	for (int i = 0; i < K; i++) {
		int query; cin >> query;
		query--;
		if (in_range(y + dy[query], x + dx[query])) {
			y += dy[query];
			x += dx[query];
			if (query == 0) {
				int tmp = dice[3][1];
				dice[3][1] = dice[1][0];
				dice[1][0] = dice[1][1];
				dice[1][1] = dice[1][2];
				dice[1][2] = tmp;
			}
			if (query == 1) {
				int tmp = dice[3][1];
				dice[3][1] = dice[1][2];
				dice[1][2] = dice[1][1];
				dice[1][1] = dice[1][0];
				dice[1][0] = tmp;
			}
			if (query == 2) {
				int tmp = dice[3][1];
				dice[3][1] = dice[2][1];
				dice[2][1] = dice[1][1];
				dice[1][1] = dice[0][1];
				dice[0][1] = tmp;
			}
			if (query == 3) {
				int tmp = dice[3][1];
				dice[3][1] = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = dice[2][1];
				dice[2][1] = tmp;
			}

			if (arr[y][x] == 0) {
				arr[y][x] = dice[1][1];
			}
			else {
				dice[1][1] = arr[y][x];
				arr[y][x] = 0;
			}
			cout << dice[3][1] << '\n';

		}
	}

	return 0;
}
