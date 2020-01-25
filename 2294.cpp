#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int money[101];
int DP[10001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= K; i++)
		DP[i] = 987654321;

	for (int i = 0; i < N; i++) {
		cin >> money[i];
		for (int j = 1; j <= K; j++) {
			if (j - money[i] >= 0)
				DP[j] = min(DP[j], DP[j - money[i]] + 1);
		}
	}
	
		if (DP[K] != 987654321)
			cout << DP[K] << endl;
		else
			cout << -1 << endl;

	return 0;
}
