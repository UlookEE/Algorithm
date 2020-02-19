#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int T, V, E, A, B;
vector<int> v[10001];
int depth[10001];
int p[15][10001];
void dfs(int n = 1, int d = 0) {
	for (int i = 0; i < v[n].size(); i++) {
		depth[v[n][i]] = d + 1;
		p[0][v[n][i]] = n;
		dfs(v[n][i], d + 1);
	}
}
int dfs2(int n) {
	int ans = 1;
	for (int i = 0; i < v[n].size(); i++) {
		ans += dfs2(v[n][i]);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> V >> E >> A >> B;
		memset(depth, 0, sizeof(depth));
		for (int i = 0; i <= V; i++) v[i].clear();
		memset(p, 0, sizeof(p));

		for (int i = 0; i < E; i++) {
			int p, n;
			cin >> p >> n;
			v[p].push_back(n);
		}

		p[0][1] = 0;
		depth[1] = 0;
		dfs();
		for (int i = 0; i < 15; i++) {
			for (int j = 1; j <= V; j++) {
				if(p[i][p[i][j]])
					p[i+1][j] = p[i][p[i][j]];
			}
		}
		int d1 = depth[A];
		int d2 = depth[B];
		int diff = d1 - d2;
		if (d1 < d2) {
			swap(A, B);
			diff = -diff;
		}
		for(int i=14; i>=0; i--){
			if (diff & (1 << i)) {
				diff %= (1 << i);
				A = p[i][A];
			}
		}
		for (int i = 14; i >= 0; i--) {
			if (p[i][A] != p[i][B]) {
				A = p[i][A];
				B = p[i][B];
			}
		}
		int ans = dfs2(p[0][A]);
		cout << '#' << test << ' ' << p[0][A] <<' '<<ans<< endl;
	}
	return 0;
}
