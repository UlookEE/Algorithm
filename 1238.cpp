#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

constexpr int MAX = 1000 + 1;
constexpr int INF = 987654321;

int N, M, X;
int graph[MAX][MAX];

void floyd() {
	for (int via = 1; via <= N; via++) {
		for (int from = 1; from <= N; from++) {
			if (graph[from][via] == 0)
				continue;
			for (int to = 1; to <= N; to++) {
				if (graph[via][to] != 0 && (graph[from][to] == 0 || graph[from][to] > graph[from][via] + graph[via][to]))
					graph[from][to] = graph[from][via] + graph[via][to];
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int from, to, weight; cin >> from >> to >> weight;
		if (graph[from][to] == 0)
			graph[from][to] = weight;
		else
			graph[from][to] = graph[from][to] > weight ? weight : graph[from][to];
	}

	floyd();
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if(i != X)
			ans = ans < graph[X][i] + graph[i][X] ? graph[X][i] + graph[i][X] : ans;
	}
	cout << ans << '\n';
	return 0;
}
