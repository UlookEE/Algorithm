#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, TC, W;
int dist[501];
struct Edge {
	int start, end, weight;
};
constexpr int INF = 987654321;
vector<Edge> edgeList;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		edgeList.clear();
		for (int i = 1; i <= N; i++)
			dist[i] = INF;

		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edgeList.push_back({ s,e,t });
			edgeList.push_back({ e,s,t });
			if (s == 1)
				dist[e] = t;
			if (e == 1)
				dist[s] = t;
		}
		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edgeList.push_back({ s,e,-t });
			if (s == 1)
				dist[e] = -t;
		}
		
		

		for (int i = 0; i < N; i++) {
			for (auto e : edgeList)
				dist[e.end] = min(dist[e.start] + e.weight, dist[e.end]);
		}

		bool mCycle = false;
		for (auto e : edgeList) {
			if (dist[e.start] + e.weight < dist[e.end]){
				mCycle = true;
				break;
			}
		}
		if (dist[1] >= 0 && !mCycle)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

}
