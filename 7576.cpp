#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Pair {
public:
	int first;
	int second;
};

class Queue {
public:
	int rear = 0;
	int front = 0;
	Pair * q;
	const int ARR_SIZE = 3000000;
	Queue() {
		q = new Pair[ARR_SIZE];
	}
	~Queue() {
		delete[] q;
	}

	bool is_full() {
		return (rear + 1) % ARR_SIZE == front;
	}
	bool is_empty() {
		return rear == front;
	}
	void push_back(const Pair& n) {
		q[rear++] = n;
		rear %= ARR_SIZE;
	}
	Pair pop_front() {
		Pair& val = q[front++];
		front %= ARR_SIZE;
		return val;
	}
};

int arr[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[1001][1001];
int N, M;

inline bool is_range(int x, int y) {
	return  x < 0 || y < 0 || x >= M || y >= N ? false : true;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	Queue q;
	int sum = N * M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push_back({ i,j });
				visited[i][j] = true;
				arr[i][j] = 1;
			}
			else if (arr[i][j] == -1)
				sum--;
		}
	}

	while (!q.is_empty()) {
		auto p = q.pop_front();
		int x = p.first, y = p.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!visited[nx][ny] && arr[nx][ny] != -1 && is_range(nx, ny)) {
				visited[nx][ny] = true;
				q.push_back({ nx,ny });
				arr[nx][ny] = arr[x][y] + 1;
			}
		}
	}

	int ans = 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
			if (ans < arr[i][j])
				ans = arr[i][j];
		}
	}

	cout << ans - 1 << endl;

	return 0;
}
