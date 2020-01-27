#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

int money[101];
int DP[2][10001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	DP[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			DP[i % 2][j] = (DP[(i - 1) % 2][j] + DP[(i - 1) % 2][j > 0 ? j -1 : 10000])%10007;
		}
	}
	cout << DP[N % 2][K] << endl;
	return 0;
}
