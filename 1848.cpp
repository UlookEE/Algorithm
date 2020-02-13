#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int N, E;
const int V_SIZ = 5001;
const int INF = 987654321;
typedef pair<int, int> ii;
vector<ii> v[V_SIZ];
vector<ii> outEdge;
vector<ii> inEdge;

vector<int> dijkstra(int bitmask) {
	vector<int> dist;
	dist.assign(V_SIZ, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;

	for (auto e : outEdge) {
		if (e.second & (1 << bitmask)) {
			pq.push(e);
			dist[e.second] = e.first;
		}
	}
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
	return dist;
}
vector<int> dijkstra2(int bitmask) {
	vector<int> dist;
	dist.assign(V_SIZ, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;

	for (auto e : outEdge) {
		if (!(e.second & (1 << bitmask))) {
			pq.push(e);
			dist[e.second] = e.first;
		}
	}
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
	return dist;
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int from, to, w1, w2;
		cin >> from >> to >> w1 >> w2;
		if (from != 1 && to != 1) {
			v[from].push_back({ w1, to });
			v[to].push_back({ w2, from });
		}
		if (from * to == to) {
			outEdge.push_back({ w1, to });
			inEdge.push_back({ w2, to });
		}
		if (from * to == from) {
			inEdge.push_back({ w1, from });
			outEdge.push_back({ w2, from });
		}
	}

	int ans = INF;
	for (int i = 0; i <= 12; i++) {
		auto dist = dijkstra(i);
		for (auto e : inEdge) {
			if (!(e.second & (1 << i)))
				ans = min(ans, dist[e.second] + e.first);
		}
		dist = dijkstra2(i);
		for (auto e : inEdge) {
			if ((e.second & (1 << i)))
				ans = min(ans, dist[e.second] + e.first);
		}
	}
	cout << ans << endl;

	return 0;
}
