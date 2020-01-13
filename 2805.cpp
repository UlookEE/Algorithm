#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

int arr[1000001];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	
	int start = 0;
	int end = 2000000000;
	int ans = 0;
	while (start <= end) {
		int mid = (end + start) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++) {
			int plus_sum = arr[i] - mid > 0 ? arr[i] - mid : 0;
			sum += plus_sum;
		}

		if (sum >= M && mid >= ans) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}



	}
	cout << ans << endl;
}
