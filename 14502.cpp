#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;

int N, M;
int board[9][9];
bool visited[9][9];

namespace LHK {
	template<typename T>
	bool next_permutation(T first, T last) {
		if (first == last || first + 1 == last)
			return false;

		T i = last - 1;
		T ii = last;
		while (true) {
			i--;
			ii--;
			if (*i < *ii) {
				T j = last;
				while (*i >= *(--j));
				swap(*i, *j);
				reverse(ii, last);
				return true;
			}
			if (i == first) {
				reverse(first, last);
				return false;
			}
		}
	}
}

inline bool in_range(int y, int x) {
	return x >= 0 && y >= 0 && y < N && x < M;
}

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };
void DFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (in_range(ny, nx) && !visited[ny][nx] && board[ny][nx] != 1) {
			visited[ny][nx] = true;
			DFS(ny, nx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	vector<int> vec;
	vec.assign(N*M, 0);
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	
	int ans = 0;
	do {
		stack<int> s;
		for (int i = 0; i < N*M; i++) {
			if (vec[i] == 1 && board[i/M][i%M] == 0) {
				board[i/M][i%M] = 1;
				s.push(i);
			}
		}
		if (s.size() == 3) {
			memset(visited, 0, sizeof(visited));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (board[i][j] == 2 && !visited[i][j]) {
						visited[i][j] = true;
						DFS(i, j);
					}
				}
			}
			int cleanCount = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (!visited[i][j] && board[i][j] != 1)
						cleanCount++;
				}
			}

			ans = cleanCount > ans ? cleanCount : ans;
		}
		while (!s.empty()) {
			int e = s.top();
			s.pop();
			board[e / M][e % M] = 0;
		}
	} while (LHK::next_permutation<vector<int>::iterator>(vec.begin(), vec.end()));

	cout << ans << endl;
}
