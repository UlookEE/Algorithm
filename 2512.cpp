#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<int> vec;
	int maxm = 0;
	while (N--) {
		int n; cin >> n; vec.push_back(n);
		if (n > maxm)
			maxm = n;
	}
	int m; cin >> m;
	int left = 0, right = maxm;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (mid >= vec[i])
				sum += vec[i];
			else
				sum += mid;
		}

		if (sum <= m) {
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}
