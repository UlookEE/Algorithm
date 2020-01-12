#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

int parent[201];

int find_root(int a) {
	if (parent[a] == a)
		return a;
	int root = find_root(parent[a]);
	parent[a] = root;
	return root;
}

void union_set(int a, int b) {
	int ra = find_root(a);
	int rb = find_root(b);
	parent[ra] = rb;
}

int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp; cin >> tmp;
			if (tmp == 1) {
				union_set(i, j);
			}
		}
	}

	int input;
	int root = -1;
	bool noFlag = false;

	getc(stdin);
	string query; getline(cin, query, '\n');
	stringstream streamQuery;
	streamQuery.str(query);
	
	while (streamQuery >> input) {
		if (root == -1) {
			root = find_root(input);
		}
		else {
			if (root != find_root(input)) {
				cout << "NO\n";
				noFlag = true;
				break;
			}
		}
	}

	if (!noFlag) {
		cout << "YES\n";
	}

}
