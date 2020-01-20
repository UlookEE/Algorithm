#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int Q_SIZ = 100001;

class Queue {
public:
	int * buf;
	int front = 0;
	int rear = 0;

	Queue() {
		buf = new int[Q_SIZ];
	}
	~Queue() {
		delete[] buf;
	}

	void push_back(int n) {
		buf[rear++] = n;
		rear %= Q_SIZ;
	}

	int pop_front() {
		int ret = buf[front++];
		front %= Q_SIZ;
		return ret;
	}
	bool empty() {
		return front == rear;
	}

};
bool visited[Q_SIZ];
int graph[Q_SIZ];

inline bool in_range(int x) {
	return x < 0 || x >= Q_SIZ ? false : true;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M; cin >> N >> M;
	Queue q;
	q.push_back(N);
	visited[N] = true;
	while (!q.empty()) {
		int n = q.pop_front();
		if (n == M)
			break;
		int arr[] = { n - 1,n + 1,n * 2 };
		for (int i = 0; i < 3; i++) {
			if (in_range(arr[i]) && !visited[arr[i]]) {
				visited[arr[i]] = true;
				q.push_back(arr[i]);
				graph[arr[i]] = graph[n] + 1;
			}
		}
	}
	cout << graph[M] << '\n';
	return 0;
}
