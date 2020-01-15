#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
using namespace std;

#define ARR_SIZE 100001
#define INF 2000000000

inline int MIN(int a, int b) {
	return a > b ? b : a;
}

class SegTree {
public:
	int* tree;

	SegTree() {
		tree = new int[ARR_SIZE * 4];
	}

	~SegTree() {
		delete[] tree;
	}



	int init_tree(int * arr, int tIdx, int start, int end) {
		if (start == end)
			return tree[tIdx] = arr[start];

		int mid = (start + end) / 2;
		return tree[tIdx] = MIN(init_tree(arr, tIdx * 2, start, mid),
							init_tree(arr, tIdx * 2 + 1, mid + 1, end));
	}

	int query_range(int tIdx, int start, int end, int left, int right) {
		if (start > right || end < left)
			return INF;
		if (start >= left && end <= right)
			return tree[tIdx];

		int mid = (start + end) / 2;
		return MIN(query_range(tIdx * 2, start, mid, left, right),
			query_range(tIdx * 2 + 1, mid + 1, end, left, right));
	}


};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int arr[ARR_SIZE];

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	SegTree segTree;
	segTree.init_tree(arr, 1, 0, N - 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout<<segTree.query_range(1, 0, N - 1, a-1, b-1)<<'\n';
	}
	
	return 0;
}
