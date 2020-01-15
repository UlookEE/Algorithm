#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<long long> vec;
	while (N--) {
		long long n; cin >> n;
		vec.push_back(n);
	}
	
	long long left = 0;
	long long right = 4294967295/2;
	long long mid;
	long long p = 0;
	long long ans = 0;
	while (left <= right) {
		p = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < vec.size(); i++) {
			p += vec[i] / mid;
		}
		if (p < M)
			right = mid - 1;
		else {
			if (mid > ans)
				ans = mid;
			left = mid + 1;
		}
			
	}
	cout << ans << '\n';
	
	return 0;
}
