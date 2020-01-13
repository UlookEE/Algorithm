#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<string.h>

using namespace std;

typedef pair<int, int> ii;

ii arr[100001];

void quick_sort(int left, int right) {
	ii pivot = arr[(left + right) / 2];
	int i = left; int j = right;
	do {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i <= j) {
			ii tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (i < right)
		quick_sort(i, right);
	if (j > left) {
		quick_sort(left, j);
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].second >> arr[i].first;
	}

	quick_sort(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << arr[i].second <<" "<< arr[i].first << '\n';
	}
	
}
