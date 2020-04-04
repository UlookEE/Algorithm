#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
#define f first
#define s second
ii arr[500001];
int ans[500001];
int N;
static struct SegTree {
	int tree[500001 * 2];

	SegTree() {
		for (int i = N; i < 2 * N; i++)
			tree[i] = 0;
		for (int i = N - 1; i > 0; i--)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}


	void update(int val) {
		int pos = N + val;
		tree[pos] = 1;
		for (int i = pos; i > 0; i >>= 1)
			tree[i / 2] = tree[i] + tree[i ^ 1];
	}

	int query(int l, int r) {
		int res = 0;
		for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				res += tree[l++];

			if (r & 1)
				res += tree[--r];
		}

		return res;
	}
}segtree;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr[i] = { input, i };
	}
	sort(arr, arr + N, [](const ii& i1, const ii& i2) {return i1.f < i2.f; });
	for (int i = 0; i < N; i++)
		arr[i].first = N-i-1;
	sort(arr, arr + N, [](const ii& i1, const ii& i2) {return i1.s < i2.s; });
	for (int i = 0; i < N; i++) {
		ans[i] = segtree.query(0, arr[i].first) + 1;
		segtree.update(arr[i].first);
	}
	for (int i = 0; i < N; i++) 
		cout << ans[i] << '\n';
	
	return 0;
}
