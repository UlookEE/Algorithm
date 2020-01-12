#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

#define ARR_SIZE 100001

int tree[ARR_SIZE * 3];
int arr[ARR_SIZE];
int lazy[ARR_SIZE * 3];

int N, M;
int query, a, b;

void lazy_prop(int tIdx, int start, int end) {
	if (lazy[tIdx] % 2) {
		tree[tIdx] = (end - start + 1) - tree[tIdx];
		if (start != end) {
			lazy[tIdx * 2] += lazy[tIdx];
			lazy[tIdx * 2 + 1] += lazy[tIdx];
		}
	}
	lazy[tIdx] = 0;
}

void update_range(int tIdx, int start, int end) {
	lazy_prop(tIdx, start, end);
	if (start > b || end < a)
		return;

	if (start >= a && end <= b) {
		tree[tIdx] = (end - start + 1) - tree[tIdx];
		if (start != end) {
			lazy[tIdx * 2]++;
			lazy[tIdx * 2 + 1]++;
		}
		return;
	}

	update_range(tIdx * 2, start, (start + end) / 2);
	update_range(tIdx * 2 + 1, (start + end) / 2 + 1, end);
	tree[tIdx] = tree[tIdx * 2] + tree[tIdx * 2 + 1];
}


int calc_range(int tIdx, int start, int end) {
	lazy_prop(tIdx, start, end);
	if (start > b || end < a)
		return 0;

	if (start >= a && end <= b)
		return tree[tIdx];

	return calc_range(tIdx * 2, start, (start + end) / 2) +
		calc_range(tIdx * 2 + 1, (start + end) / 2 + 1, end);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> query >> a >> b;
		if (query == 0) {
			update_range(1, 0, N);
		}
		else {
			cout << calc_range(1, 0, N) << '\n';
		}
	}

	return 0;
}
