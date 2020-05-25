#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 987654321
int N;
int arr[20][20];
int answer = INF;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

bool in_range(int y, int x) {
	return x >= 0 && y >= 0 && x < N&& y < N;
}

bool in_range(int y) {
	return y >= 0 && y < N;
}

void simulate(int y, int x, int d1, int d2) {
	int sum[5] = { 0,0,0,0,0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < y && j <= x + d1 && i + j < x + y)
				sum[0] += arr[i][j];
			else if (i <= y - d1 + d2 && j > x + d1 && j - i > x - y + 2*d1)
				sum[1] += arr[i][j];
			else if (i > y - d1 + d2 && j >= x + d2 && i + j > y + x + 2*d2) 
				sum[2] += arr[i][j];
			else if (i >= y && j < x + d2 && i - j > y - x) 
				sum[3] += arr[i][j];
			else
				sum[4] += arr[i][j];
		}
	}
	int minsum = min({ sum[0], sum[1], sum[2], sum[3], sum[4] });
	int maxsum = max({ sum[0], sum[1], sum[2], sum[3], sum[4] });
	answer = min(answer, (maxsum - minsum));
}
void sep_map(int d1, int d2) {
	for (int i = 1; i <= N; i++) {
		if (!in_range(i - d1))
			continue;
		if (!in_range(i + d2))
			break;
		for (int j = 1; j <= N; j++) {
			if (!in_range(j + d1 + d2))
				break;
			simulate(i,j,d1,d2);
		}
	}
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sep_map(i, j);
		}
	}
}
int main() {
	
	init();
	solve();
	cout << answer << '\n';
	return 0;
}
