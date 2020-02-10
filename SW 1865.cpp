#include<iostream>
#include<cstring>
using namespace std;

double arr[17][17];
double DP[1 << 16];

double res = 0;
int N;

void DFS(int depth, int flag, double ans) {
	if (DP[flag] >= ans || ans <= DP[(1 << N) - 1])
		return;
	DP[flag] = ans;
	if (depth == N)
		return;
	for (int i = 0; i < N; i++) {
		if (((1 << i) ^ flag)) {
			DFS(depth + 1, flag | (1 << i), ans * arr[depth][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		memset(DP, 0, (1 << N) * sizeof(double));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				arr[i][j] /= 100;
			}
		}
		DFS(0, 0, 100);
		cout.precision(6);
		cout << fixed;
		cout << '#' << test << ' ' << DP[(1 << N) - 1] << '\n';
	}
	return 0;
}
