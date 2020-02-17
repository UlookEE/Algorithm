#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int N, M, K;
vector<int>graph[1001];
bool visited[1001];
int match[1001];
int remain[1001];
bool dfs(int n) {
	if (visited[n]) return false;
	visited[n] = true;
	for (int i = 0; i < graph[n].size(); i++) {
		if (!match[graph[n][i]] || dfs(match[graph[n][i]])) {
			match[graph[n][i]] = n;
			return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int c; cin >> c;
		remain[i] = c;
		while (c--) {
			int k; cin >> k;
			graph[i].push_back(k);
		}
	}
	int tmpAns = 9999999999;
	for (int j = 0; j < K + 1; j++) {
		int change = 0;
		for (int i = 1; i <= N; i++) {
			memset(visited, 0, sizeof(visited));
			if (remain[i] && dfs(i)) {
				ans++;
				remain[i]--;
				change++;
			}
			if (ans == tmpAns + K)
				goto ESCAPE;
		}
		if (j == 0)
			tmpAns = ans;
		if (change == 0)
			break;
	}
ESCAPE:;
	cout << ans << '\n';
	return 0;
}
