#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int T, N;
struct Edge {
	long long w;
	int s;
	int e;
};

struct Vertex {
	int y;
	int x;
};

vector<Vertex> vv;
int p[1001];

inline long long calc_dist(Vertex& v1, Vertex& v2) {
	return pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2);
}

int find(int n) {
	if (p[n] == -1)
		return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	if (find(a) != find(b))
		p[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		vv.assign(N, { 0,0 });
		for (int i = 0; i < N; i++) 
			cin >> vv[i].x;
		for (int i = 0; i < N; i++) 
			cin >> vv[i].y;
		
		double weight; cin >> weight;
		auto cmpEdge = [](Edge e1, Edge e2)->bool {return e1.w > e2.w; };
		priority_queue < Edge, vector<Edge>, decltype(cmpEdge)> pq(cmpEdge);
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				long long dist = calc_dist(vv[i], vv[j]);
				pq.push({ dist, i, j });
			}
		}
		
		fill(p, p + N, -1);
		int count = 0;
		long long ans = 0;
		while (count != N - 1) {
			auto e = pq.top(); pq.pop();
			int p1 = find(e.s);
			int p2 = find(e.e);
			if (p1 != p2) {
				count++;
				merge(p1, p2);
				ans += e.w;
			}
		}
		
		cout << fixed;
		cout.precision(0);
		cout << '#' << test << ' ' <<ans*weight<< '\n';
	}
	return 0;
}
