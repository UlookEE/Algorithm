#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;


// 시작 2:54
int board[51][51];
int tmpBoard[51];

#define INVALID 987654321

bool visited[51][51];
bool flag_equal;
int N, M, T;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

void DFS(int x, int y, int value) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = (y + dy[i] + M) % M;
		if (nx >= 0 && nx < N && !visited[nx][ny] && value == board[nx][ny]) {
			board[x][y] = INVALID;
			board[nx][ny] = INVALID;
			flag_equal = true;
			DFS(nx, ny, value);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	while (T--) {
		flag_equal = false;
		int x, d, k; cin >> x >> d >> k;
		for (int l = x - 1; l < N; l += x) {
			if (d == 0) {   //시계 방향
				memcpy(tmpBoard + k, board[l], 4 * (M - k));
				memcpy(tmpBoard, board[l] + M - k, 4 * k);
				memcpy(board[l], tmpBoard, 4 * M);
			}
			else {
				memcpy(tmpBoard, board[l] + k, 4 * (M - k));
				memcpy(tmpBoard + M - k, board[l], 4 * k);
				memcpy(board[l], tmpBoard, 4 * M);
			}
		}

		memset(visited, 0, 51 * 51);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] != INVALID && !visited[i][j])
					DFS(i, j, board[i][j]);
			}
		}
		int sum = 0;
		int count_valid = 0;
		if (flag_equal == false) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (board[i][j] != INVALID) {
						sum += board[i][j];
						count_valid++;
					}
				}
			}
			if (!count_valid)
				continue;
			double average = (double)sum / count_valid;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (board[i][j] == INVALID)
						continue;
					else if (board[i][j] == average)
						continue;
					else if (board[i][j] > average)
						board[i][j]--;
					else
						board[i][j]++;
				}
			}
		}
	}
	int ans_sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != INVALID)
				ans_sum += board[i][j];
		}
	}
	cout << ans_sum << endl;
	return 0;
}
