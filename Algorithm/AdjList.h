#pragma once

#include <vector>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
typedef std::queue<int> qi;

#define UNVISITED 1
#define VISITED 0
#define INF -1

class AdjList {
public:
	std::vector<vii> graph;			//each vertex have vector, 
									//pair first is other side vertex, second is weight
	AdjList(int vertex) {			//parameter : the number of vertex
		graph.reserve(vertex + 1);
	}

	vii& operator[] (int i) {
		return graph[i];
	}

	vi dfs_num;						//dfs visit check
private: 
	vi _dag;
public:
	void dfs_init() {
		dfs_num = vi(graph.size(), UNVISITED);
		_dag = vi();
	}

	void dfs(int u) {
		dfs_num[u] = VISITED;
		//function
		for (int i = 0; i < graph[u].size(); i++) {
			ii v = graph[u][i];
			if (dfs_num[v.first] == UNVISITED)
				dfs(v.first);
		}
		_dag.push_back(u);
	}

	vi dag() {
		dfs_init();
		for (int i = 0; i < graph.size(); i++)
			if (dfs_num[i] == UNVISITED)
				dfs(i);
	
		std::reverse(_dag.begin(), _dag.end());
		return _dag;
	}
	
	vi bfs_num;
	void bfs_init() {
		bfs_num = vi(graph.size(), UNVISITED);
	}

	void bfs(int u) {
		bfs_num[u] = 0;
		qi q;
		q.push(u);
		while (!q.empty()) {
			u = q.front();
			q.pop();
			//function
			for (int i = 0; i < graph[u].size(); i++) {
				ii v = graph[u][i];
				if (v.first == INF) {
					bfs_num[v.first] = bfs_num[u] + 1;
					q.push(v.first);
				}
			}
			
		}
	}

	bool connected_component(int a, int b) {
		dfs(a);
		return dfs_num[b] == VISITED;
	}
	
};