#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<string.h>

using namespace std;
typedef pair<int, int> ii;

#define ARR_SIZE 100001
int arr[ARR_SIZE];
int tree_max[ARR_SIZE * 3];
int tree_min[ARR_SIZE * 3];
int N, M;

inline int MAX(int a, int b) {
	return a > b ? a : b;
}

inline int MIN(int a, int b) {
	return a < b ? a : b;
}

void init_tree(int tIdx, int start, int end) {
	if (start == end) {
		tree_max[tIdx] = arr[start];
		tree_min[tIdx] = arr[start];
		return;
	}

	init_tree(tIdx * 2, start, (start + end) / 2);
	init_tree(tIdx * 2 + 1, (start + end) / 2 + 1, end);
	tree_max[tIdx] = MAX(tree_max[tIdx * 2], tree_max[tIdx * 2 + 1]);
	tree_min[tIdx] = MIN(tree_min[tIdx * 2], tree_min[tIdx * 2 + 1]);
}

int query_max(int tIdx, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	
	if (left <= start && right >= end)
		return tree_max[tIdx];
	
	int mid = (start + end)/2;
	return MAX(query_max(tIdx * 2, start, mid, left, right), query_max(tIdx * 2 + 1, mid + 1, end, left, right));
}

int query_min(int tIdx, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 2000000000;

	if (left <= start && right >= end)
		return tree_min[tIdx];

	int mid = (start + end) / 2;
	return MIN(query_min(tIdx * 2, start, mid, left, right), query_min(tIdx * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	init_tree(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		int min_val = query_min(1, 0, N - 1, a-1, b-1);
		int max_val = query_max(1, 0, N - 1, a-1, b-1);
		cout << min_val << " " << max_val << '\n';
	}
}
