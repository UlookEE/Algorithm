#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

int N, K, L;
int board[101][101];
int seconds[101];
char dir[101];
int timeInd = 0;
int time = 0;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
deque<pair<int, int>> dq;
inline bool in_range(int y, int x) {
	return x >= 0 && y >= 0 && x < N && y < N;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int y, x; cin >> y >> x;
		board[y-1][x-1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> seconds[i] >> dir[i];
	}
	int d = 0;
	int y = 0;
	int x = 0;
	board[y][x] = 2;
	dq.push_back({ y,x });
	while (true) {
		/* 시작 */
		if (time == seconds[timeInd]) {
			if (dir[timeInd] == 'L') {
				d = (d + 4 - 1) % 4;
			}
			else {
				d = (d + 1) % 4;
			}
			timeInd++;
		}
		y = y + dy[d];
		x = x + dx[d];
		if (in_range(y, x)) {
			if (board[y][x] == 1) {
				board[y][x] = 2;
				dq.push_back({ y, x });
			}
			else if (board[y][x] == 2)
				break;
			else {
				board[y][x] = 2;
				dq.push_back({ y, x });
				auto p = dq.front();
				board[p.first][p.second] = 0;
				dq.pop_front();
			}
		}
		else {
			break;
		}

		time++;
		
	}
	std::cout << time+1 << endl;
	return 0;
}
