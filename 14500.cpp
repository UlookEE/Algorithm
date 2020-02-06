#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

int N, M;
int arr[501][501];
inline bool in_range(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < M;
}

int maxVal = 0;

bool visited[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 }; //위로는 그릴 필요 없을듯

void DFS(int y, int x, int depth, int val) {
	if (depth == 3) {
		maxVal = val > maxVal ? val : maxVal;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (in_range(ny, nx) && !visited[ny][nx]) {
			visited[ny][nx] = true;
			DFS(ny, nx, depth + 1, val + arr[ny][nx]);
			visited[ny][nx] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			DFS(i, j, 0, arr[i][j]);
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmpsum = arr[i][j];
			int countA = 1;
			for (int k = 0; k < 4; k++) {
				int ni = i + dy[k];
				int nj = j + dx[k];
				if (in_range(ni, nj)) {
					tmpsum += arr[ni][nj];
					countA++;
				}
			}
			if(countA == 4)
				maxVal = maxVal > tmpsum ? maxVal : tmpsum;
			else if(countA == 5){
				for (int k = 0; k < 4; k++) {
					int ni = i + dy[k];
					int nj = j + dx[k];
					if (in_range(ni, nj)) {
						int newVal = tmpsum - arr[ni][nj];
						maxVal = maxVal > newVal ? maxVal : newVal;
					}
				}
			}
		}
	}
	cout << maxVal << endl;
	return 0;
}
