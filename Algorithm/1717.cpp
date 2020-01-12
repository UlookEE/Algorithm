#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

#define ARR_SIZE 1000001

int parent[ARR_SIZE];
int N, M;
int query, a, b;
int i;
int r;
int find_root(int n) {
	return parent[n] = (parent[n] == n) ? parent[n] : find_root(parent[n]);
}

void union_set() {
	/* If need, Set child to big parent */
	a = find_root(a);
	b = find_root(b);
	parent[a] = b;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	N++;
	M++;
	while (--N)
		parent[N] = N;

	while (--M) {
		cin >> query >> a >> b;
		if (query) {
			if (find_root(a) == find_root(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else {
			union_set();
		}
	}

	return 0;
}
