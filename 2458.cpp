#include<iostream>
#include<vector>
using namespace std;

int N, M;
int v[501][501];
int dist[501][501];
constexpr int INF = 987654321;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from][to] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				dist[i][j] = 0;
			else if (v[i][j])
				dist[i][j] = v[i][j];
			else
				dist[i][j] = INF;
		}
	}
	for (int via = 1; via <= N; via++) {
		for (int from = 1; from <= N; from++) {
			for (int to = 1; to <= N; to++) {
				if (dist[from][to] > dist[from][via] + dist[via][to])
					dist[from][to] = dist[from][via] + dist[via][to];
			}
		}
	}
	int ans = N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF && dist[j][i] == INF) {
				ans--;
				break;
			}
		}
	}
	cout << ans << endl;

}
