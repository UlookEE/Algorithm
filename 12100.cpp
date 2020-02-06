#include<iostream>
#include<cstring>
using namespace std;


int board[21][21];
int N;
int maxAns = 0;


void DFS(int depth, int dir) {
	if (depth == 5)
		return;

	else {
		int tmpBoard[21][21];
		int tmpArr[21];
		memcpy(tmpBoard, board, sizeof(board));
		
		if (dir == 0) {
			for (int i = 0; i < N; i++) {
				int arrInd = 0;
				memset(tmpArr, 0, N*sizeof(int));
				for (int j = 0; j < N; j++) {
					if (board[i][j] != 0) {
						int blockIndex = j + 1;
						while (board[i][blockIndex] == 0 && blockIndex < N)
							blockIndex++;

						if (board[i][j] == board[i][blockIndex] && blockIndex != N) {
							board[i][j] *= 2;
							board[i][blockIndex] = 0;
							maxAns = board[i][j] > maxAns ? board[i][j] : maxAns;
						}
					}
					if (board[i][j] != 0)
						tmpArr[arrInd++] = board[i][j];
				}
				memcpy(board[i], tmpArr, N * sizeof(int));
			}
		}
		if (dir == 1) {
			for (int i = 0; i < N; i++) {
				int arrInd = N-1;
				memset(tmpArr, 0, N * sizeof(int));
				for (int j = N-1; j >=0; j--) {
					if (board[i][j] != 0) {
						int blockIndex = j - 1;
						while (board[i][blockIndex] == 0 && blockIndex >= 0 )
							blockIndex--;

						if (board[i][j] == board[i][blockIndex] && blockIndex != -1) {
							board[i][j] *= 2;
							board[i][blockIndex] = 0;
							maxAns = board[i][j] > maxAns ? board[i][j] : maxAns;
						}
					}
					if (board[i][j] != 0)
						tmpArr[arrInd--] = board[i][j];
				}
				memcpy(board[i], tmpArr, N * sizeof(int));
			}
		}
		if (dir == 2) {
			for (int j = 0; j < N; j++) {
				int arrInd = 0;
				memset(tmpArr, 0, N * sizeof(int));
				for (int i = 0; i < N; i++) {
					if (board[i][j] != 0) {
						int blockIndex = i + 1;
						while (board[blockIndex][j] == 0 && blockIndex < N)
							blockIndex++;

						if (board[i][j] == board[blockIndex][j] && blockIndex != N) {
							board[i][j] *= 2;
							board[blockIndex][j] = 0;
							maxAns = board[i][j] > maxAns ? board[i][j] : maxAns;
						}
					}
					if (board[i][j] != 0)
						tmpArr[arrInd++] = board[i][j];
				}
				for (int i = 0; i < N; i++)
					board[i][j] = tmpArr[i];
			}
		}
		if (dir == 3) {
			for (int j = 0; j < N; j++) {
				int arrInd = N-1;
				memset(tmpArr, 0, N * sizeof(int));
				for (int i = N-1; i >=0; i--) {
					if (board[i][j] != 0) {
						int blockIndex = i - 1;
						while (board[blockIndex][j] == 0 && blockIndex >= 0)
							blockIndex--;

						if (board[i][j] == board[blockIndex][j] && blockIndex != -1) {
							board[i][j] *= 2;
							board[blockIndex][j] = 0;
							maxAns = board[i][j] > maxAns ? board[i][j] : maxAns;
						}
					}
					if (board[i][j] != 0)
						tmpArr[arrInd--] = board[i][j];
				}
				for (int i = 0; i < N; i++)
					board[i][j] = tmpArr[i];
			}
		}

		for (int i = 0; i < 4; i++)
			DFS(depth + 1, i);

		memcpy(board, tmpBoard, sizeof(board));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			maxAns = maxAns < board[i][j] ? board[i][j] : maxAns;
		}
	}
	for (int i = 0; i < 4; i++)
		DFS(0, i);

	cout << maxAns << endl;
	return 0;
}
