#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int N, M;
vector<int>graph[1001];
bool visited[1001];
int match[1001];
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
	cin >> N >> M;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int c; cin >> c;
		while (c--) {
			int k; cin >> k;
			graph[i].push_back(k);
		}
	}
	for (int j = 0; j < 2; j++) {
		for (int i = 1; i <= N; i++) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i))
				ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
