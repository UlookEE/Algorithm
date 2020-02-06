#include<iostream>
#include<cstring>
using namespace std;

int N, M;
char board[12][12];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int ans;

inline bool in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

void DFS(int depth, int dir) {
	if (depth == 10)
		return;

	char tmpBoard[12][12];
	memcpy(tmpBoard, board, sizeof(tmpBoard));
	if (dir == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 'B' || board[i][j] == 'R') {
					int y = i;
					int x = j;
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					while (in_range(ny, nx) && (board[ny][nx] == '.' || board[ny][nx] == 'O')) {
						if (board[ny][nx] == 'O') {
							board[y][x] = '.';
							break;
						}
						else {
							board[ny][nx] = board[y][x];
							board[y][x] = '.';
						}
						y = ny;
						x = nx;
						ny += dy[dir];
						nx += dx[dir];
					}
				}
			}
		}
	}
	if (dir == 1) {
		for (int i = M-1; i >=0; i--) {
			for (int j = 0; j < N; j++) {
				if (board[j][i] == 'B' || board[j][i] == 'R') {
					int y = j;
					int x = i;
					int ny = j + dy[dir];
					int nx = i + dx[dir];
					while (in_range(ny, nx) && (board[ny][nx] == '.' || board[ny][nx] == 'O')) {
						if (board[ny][nx] == 'O') {
							board[y][x] = '.';
							break;
						}
						else {
							board[ny][nx] = board[y][x];
							board[y][x] = '.';
						}
						y = ny;
						x = nx;
						ny += dy[dir];
						nx += dx[dir];
					}
				}
			}
		}
	}
	if (dir == 2) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 'B' || board[i][j] == 'R') {
					int y = i;
					int x = j;
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					while (in_range(ny, nx) && (board[ny][nx] == '.' || board[ny][nx] == 'O')) {
						if (board[ny][nx] == 'O') {
							board[y][x] = '.';
							break;
						}
						else {
							board[ny][nx] = board[y][x];
							board[y][x] = '.';
						}
						y = ny;
						x = nx;
						ny += dy[dir];
						nx += dx[dir];
					}
				}
			}
		}
	}
	if (dir == 3) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (board[j][i] == 'B' || board[j][i] == 'R') {
					int y = j;
					int x = i;
					int ny = j + dy[dir];
					int nx = i + dx[dir];
					while (in_range(ny, nx) && (board[ny][nx] == '.' || board[ny][nx] == 'O')) {
						if (board[ny][nx] == 'O') {
							board[y][x] = '.';
							break;
						}
						else {
							board[ny][nx] = board[y][x];
							board[y][x] = '.';
						}
						y = ny;
						x = nx;
						ny += dy[dir];
						nx += dx[dir];
					}
				}
			}
		}
	}
	bool redFlag = false;
	bool blueFlag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'R') {
				redFlag = true;
			}
			else if (board[i][j] == 'B') {
				blueFlag = true;
			}
		}
	}
	if (!blueFlag) {
		memcpy(board, tmpBoard, sizeof(board));
		return;
	}
	if (!redFlag) {
		memcpy(board, tmpBoard, sizeof(board));
		ans = ans > depth + 1 ? depth + 1 : ans;
		return;
	}
	for (int i = 0; i < 4; i++)
		DFS(depth + 1, i);


	memcpy(board, tmpBoard, sizeof(board));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> board[i];

	ans = 1000;
	 
	for (int i = 0; i < 4; i++)
		DFS(0, i);

	if (ans == 1000)
		ans = -1;
	cout << ans << '\n';
	return 0;
}
