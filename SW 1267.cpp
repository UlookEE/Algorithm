#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
#include<vector>
#include<string.h>
#include<stack>
#include<list>
using namespace std;

int arr[1001][1001];
int visited[1001];
int V, E;
vector<int> dag;
void DFS(int v) {
	visited[v] = true;
	for (int i = 1; i <= V; i++) {
		if (!visited[i] && arr[v][i])
			DFS(i);
	}
	dag.push_back(v);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int test = 1; test <= 10; test++) {
		cin >> V >> E;
		dag.clear();
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < E; i++) {
			int s, e; cin >> s >> e;
			arr[s][e] = 1;
		}

		for (int i = 1; i <= V; i++) {
			if(!visited[i])
				DFS(i);
		}
		cout << '#' << test << ' ';
		for (int i = dag.size() - 1; i>=0; i--) {
			cout << dag[i] << ' ';
		}
		cout << '\n';
		
	}

	return 0;
}
