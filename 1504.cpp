#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int N, E;
const int V_SIZ = 801;
const int INF = 607654321;
typedef pair<int, int> ii;
vector<ii> v[V_SIZ];
int dist[V_SIZ];

void dijkstra(int start) {
	fill(dist, dist + V_SIZ, INF);
	priority_queue<ii, vector<ii>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		auto e = pq.top();
		pq.pop();
		if (e.first > dist[e.second])
			continue;
		for (auto ee : v[e.second]) {
			if (ee.first + e.first < dist[ee.second]) {
				dist[ee.second] = ee.first + e.first;
				pq.push({ dist[ee.second], ee.second });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back({ weight, to});
		v[to].push_back({ weight, from });
	}
	int via1, via2;
	cin >> via1>> via2;
	dijkstra(1);
	int _1toVia1 = dist[via1];
	int _1toVia2 = dist[via2];
	dijkstra(via1);
	int via1ToVia2 = dist[via2];
	int via1ToN = dist[N];
	dijkstra(via2);
	int via2ToN = dist[N];
	int ans = min(_1toVia1 + via1ToVia2 + via2ToN, _1toVia2 + via1ToVia2 + via1ToN);
	cout << (ans >= INF ? -1 : ans)<< endl;
	
	return 0;
}
