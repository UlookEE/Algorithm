#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<algorithm>

using namespace std;

int arr1[1000001];
int arr2[1000001];
int N, M;
int ans[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr1[i];

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> arr2[i];

	sort(arr1, arr1 + N);
	for (int i = 0; i < M; i++) {
		int start = 0;
		int end = N - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (arr1[mid] == arr2[i]) {
				ans[i] = 1;
				break;
			}
			else if (arr1[mid] < arr2[i]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
