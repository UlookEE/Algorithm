#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;


char dp[2001][2001];

int main() {
	int T;
	cin >> T;


	int t = 1;
	while (T--) {
		for (int i = 0; i < 2001; i++) {
			memset(dp[i], 0, 2001);
		}
		char l[2001];
		int k_i[27];
		int k_o[27];
		int L, K;
		cin >> L >> K;

		for (int i = 0; i < K; i++)
			cin >> k_i[i] >> k_o[i];





	}
	return 0;
}