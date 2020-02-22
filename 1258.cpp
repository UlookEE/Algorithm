#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int T, N;
int arr[101][101];

class Matrix {
public:
	int hei;
	int wid;
	bool operator<(const Matrix& m) const{
		if (hei * wid != m.hei * m.wid)
			return hei * wid < m.hei * m.wid;
		return hei < m.hei;
	}
};

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

inline bool in_range(int y, int x) {
	return y >= 0 && x >= 0 && x < N && y < N;
}

vector<Matrix> ansVec;
void BFS(int y, int x) {
	int minY = y;
	int minX = x;
	int maxY = y;
	int maxX = x;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		auto e = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = e.first + dy[i];
			int nx = e.second + dx[i];
			if (in_range(ny, nx) && arr[ny][nx]) {
				q.push({ ny, nx });
				arr[ny][nx] = 0;
				maxY = max(maxY, ny);
				maxX = max(maxX, nx);
			}
		}
	}
	ansVec.push_back({ maxY - minY + 1, maxX - minX + 1 });
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		}
		ansVec.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j]) {
					arr[i][j] = 0;
					BFS(i, j);
				}
			}
		}

		cout << '#' << test << ' '<<ansVec.size()<<' ';
		sort(ansVec.begin(), ansVec.end());
		for (int i = 0; i < ansVec.size(); i++)
			cout << ansVec[i].hei << ' ' << ansVec[i].wid<< ' ';
		cout << '\n';
	}
	return 0;
}
