#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int M, N;
char arr[101][101];
int minDepth[101][101];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };

struct qnode {
	int y;
	int x;
	int depth;
};

auto comp = [](const qnode& a, const qnode& b) -> bool {return a.depth > b.depth; };
inline bool in_range(int y, int x) {
	return x >= 1 && y >= 1 && y <= N && x <= M;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	priority_queue<qnode,vector<qnode>, decltype( comp )> q(comp);
	q.push({ 1,1,0 });
	fill(*minDepth, *minDepth + 101 * 101, 987654321);
	while (!q.empty()) {
		auto e = q.top();
		q.pop();

		if(e.y == N && e.x == M && e.depth < minDepth[e.y][e.x]) minDepth[e.y][e.x] = e.depth;
		if (e.depth >= minDepth[e.y][e.x] || (e.y == N && e.x == M)) continue;

		minDepth[e.y][e.x] = e.depth;
		for (int i = 0; i < 4; i++) {
			int ny = e.y + dy[i];
			int nx = e.x + dx[i];
			if (in_range(ny, nx)) {
				if (arr[ny][nx] == '1' && minDepth[ny][nx] > e.depth + 1) 
					q.push({ ny, nx, e.depth + 1 });
				
				if (arr[ny][nx] == '0' && minDepth[ny][nx] > e.depth) 
					q.push({ ny, nx, e.depth });
				
			}
		}
	}
	cout << minDepth[N][M] << endl;
	return 0;
}
