#include<iostream>
#include<algorithm>
using namespace std;

struct iii {
	int val;
	int rank;
	int irank;
};
iii arr[500001];
iii carr[500001];

void merge(int l, int m, int r) {
	int m2 = m + 1;
	int pos = l;

	int left = l;
	int right = r;

	while (l <= m && m2 <= r) {
		if (arr[l].val < arr[m2].val) {
			arr[m2].rank -= (m - l) + 1;
			carr[pos++] = arr[m2];
			m2++;
		}
		else {
			carr[pos++] = arr[l];
			l++;
		}
	}
	while (l <= m)
		carr[pos++] = arr[l++];
	while (m2 <= r)
		carr[pos++] = arr[m2++];
	for (int i = left; i <= right; i++)
		arr[i] = carr[i];
}

void mergeSort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr[i] = { input, i + 1, i+1 };
	}
	mergeSort(0, N - 1);
	sort(arr, arr + N, [](const iii& iii1, const iii& iii2)->bool {return iii1.irank < iii2.irank;});
	for (int i = 0; i < N; i++)
		cout << arr[i].rank << '\n';
	return 0;
}
