#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
#include<vector>
using namespace std;

void quick_sort(int arr[], int start, int end) {
	int i = start;
	int j = end;
	int temp;
	int pivot = arr[(start + end) / 2];
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (start < j)
		quick_sort(arr, start, j);
	if(i<end)
		quick_sort(arr, i, end);
}
int arr[500002];
int arr2[500002];
int ans[500002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int M; cin >> M;
	for (int i = 0; i < M; i++) 
		cin >> arr2[i];
	quick_sort(arr, 0, N - 1);

	int lower_bound, upper_bound;
	for (int i = 0; i < M; i++) {
		int find_val = arr2[i];
		int start = 0, end = N;
		while (start < end) {
			int mid = (start + end) / 2;
			if (arr[mid] < find_val)
				start = mid + 1;
			else
				end = mid;
		}
		lower_bound = end + 1;

		find_val = arr2[i];
		start = 0, end = N;
		while (start < end) {
			int mid = (start + end) / 2;
			if (arr[mid] <= find_val)
				start = mid + 1;
			else
				end = mid;
		}
		upper_bound = end + 1;

		ans[i] = upper_bound - lower_bound;
	}


	for (int i = 0; i < M; i++)
		cout << ans[i] << ' ';
	return 0;
}
