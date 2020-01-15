#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

#define ARR_SIZE 500001
#define INF 2000000000

int N, M;
class SegmentTree {
public:
	int *tree;
	int *arr;
	int *lazy;
	SegmentTree() {
		tree = new int[ARR_SIZE * 4];
		arr = new int[ARR_SIZE];
		lazy = new int[ARR_SIZE * 4];
		memset(lazy, 0, ARR_SIZE * 4);
	}
	~SegmentTree() {
		delete[] tree;
		delete[] arr;
		delete[] lazy;
	}

	inline bool isOdd(int s, int e) {
		return (e - s) % 2 == 0;
	}
	void init_tree(int tIdx, int start, int end) {
		if (start == end) {
			tree[tIdx] = arr[start];
			return;
		}

		init_tree(tIdx * 2, start, (start + end) / 2);
		init_tree(tIdx * 2 + 1, (start + end) / 2 + 1, end);
		tree[tIdx] = tree[tIdx * 2] ^ tree[tIdx * 2 + 1];
	}

	void lazy_prop(int tIdx, int start, int end) {
		if (lazy[tIdx] != 0) {
			if(isOdd(start, end))
				tree[tIdx] ^= lazy[tIdx];
			int mid = (start + end) / 2;
			lazy[tIdx * 2] ^= lazy[tIdx];
			lazy[tIdx * 2 + 1] ^= lazy[tIdx];
			lazy[tIdx] = 0;
		}
	}

	void update_range(int tIdx, int start, int end, int left, int right, int n) {
		lazy_prop(tIdx, start, end);
		if (start > right || end < left)
			return;

		int mid = (start + end) / 2;
		if (start >= left && end <= right) {
			if (start != end) {
				lazy[tIdx * 2] ^= n;
				lazy[tIdx * 2 + 1] ^= n;
			}
			if (isOdd(start, end))
				tree[tIdx] ^= n;	
			return;
		}
		update_range(tIdx * 2, start, mid, left, right, n);
		update_range(tIdx * 2 + 1, mid + 1, end, left, right, n);
		tree[tIdx] = tree[tIdx * 2] ^ tree[tIdx * 2 + 1];
	}

	int calc_range(int tIdx, int start, int end, int left, int right) {
		lazy_prop(tIdx, start, end);
		if (start > right || end < left)
			return 0;

		int mid = (start + end) / 2;
		if (start >= left && end <= right) {
			return tree[tIdx];
		}
		
		return calc_range(tIdx * 2, start, mid, left, right) ^ calc_range(tIdx * 2 + 1, mid + 1, end, left, right);;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	SegmentTree st;
	for (int i = 0; i < N; i++)
		cin >> st.arr[i];

	cin >> M;
	st.init_tree(1, 0, N-1);
	for (int i = 0; i < M; i++) {
		int query; cin >> query;
		if (query == 1) {
			int s, e, n; cin >> s >> e >> n;
			if (s > e) {
				int tmp = s;
				s = e;
				e = tmp;
			}
			st.update_range(1, 0, N - 1, s, e, n);
		}
		else {
			int s, e; cin >> s >> e;
			if (s > e) {
				int tmp = s;
				s = e;
				e = tmp;
			}
			cout<<st.calc_range(1, 0, N - 1, s, e)<<'\n';
		}
	}
	
	return 0;
}
