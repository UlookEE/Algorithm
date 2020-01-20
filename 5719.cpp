#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<string.h>
using namespace std;

const int MAX = 501;
const int INF = 0x7FFFFFFF;

vector<pair<int, int>> graph[MAX];
vector<int> trace[MAX];

vector<int> dijkstra(int start, int end) {
	vector<int> distance(MAX, INF);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, start);
	distance[start] = 0;
	while (!pq.empty()) {
		int e = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if (w > distance[e])
			continue;

		for (int i = 0; i < graph[e].size(); i++) {
			int n_e = graph[e][i].first;
			if (graph[e][i].second == -1)
				continue;
			int n_w = w + graph[e][i].second;
			if (n_w < distance[n_e])
				trace[n_e].clear();
			if (n_w <= distance[n_e]) 
			{
				distance[n_e] = n_w;
				pq.emplace(n_w, n_e);
				trace[n_e].emplace_back(e);
			}
		}
	}
	return distance;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (true) {
		int N, M; cin >> N >> M;
		for (auto& i : graph)
			i.clear();
		for (auto& i : trace)
			i.clear();

		if (N == 0 && M == 0)
			break;
		int start, end; cin >> start >> end;
		for (int i = 0; i < M; i++) {
			int s, e, w; cin >> s >> e >> w;
			graph[s].emplace_back(e, w);
		}
		dijkstra(start, end);
		queue<int> q;
		q.push(end);
		bool visited[MAX];
		memset(visited, 0, MAX);
		visited[end] = true;
		while (!q.empty()) {
			int e = q.front();
			q.pop();
			visited[e] = true;
			for (auto element : trace[e]) {
				for (auto& edge : graph[element]) {
					if (edge.first == e)
						edge.second = -1;
				}
				if(!visited[element])
					q.push(element);
			}
		}
		auto res = dijkstra(start, end);
		if (res[end] == INF)
			cout << -1 << endl;
		else
			cout << res[end] << endl;
	}
	return 0;
}
