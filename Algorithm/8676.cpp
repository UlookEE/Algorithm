#include<iostream>
#include<string>
#include<string.h>

using namespace std;

long long DP[1000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	string sub_s = "SAMSUNG";
	for (int test = 1; test <= T; test++)
	{
		string str; cin >> str;
		cout << str[0] << endl;
		int count = 0;
		memset(DP, 0, sizeof(DP));
		for (int j = str.length() - 1; j >= 0; j--) {
			if (str[j] == sub_s[6])
				DP[j] = ++count;
			else
				DP[j] = count;
		}
		for (int i = 5; i >= 0; i--) {
			for (int j = str.length() - 1; j >= 0; j--) {
				if (str[j] == sub_s[i])
					DP[j] = (DP[j] + DP[j + 1])% 1000000007;
				else
					DP[j] = DP[j + 1];
			}
		}

		cout << '#' << test << " " << DP[0] << '\n';
	}
	return 0;
}