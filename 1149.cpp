#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int r[1001];
int g[1001];
int b[1001];

int dp[1001][3];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}

	dp[0][0] = r[0];
	dp[0][1] = g[0];
	dp[0][2] = b[0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1] + r[i], dp[i - 1][2] + r[i]);
		dp[i][1] = min(dp[i - 1][0] + g[i], dp[i - 1][2] + g[i]);
		dp[i][2] = min(dp[i - 1][0] + b[i], dp[i - 1][1] + b[i]);
	}
	N--;
	cout << min({ dp[N][0], dp[N][1], dp[N][2] }) << '\n';
	return 0;
}
