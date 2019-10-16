#include<iostream>
#include<string.h>

using namespace std;

long long DP[1000000];
char str[10002];
int i, j, count;
const char sub_s[] = "SAMSUNG";
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	
	for (int test = 1; test <= T; test++)
	{
		cin >> str;
		
		count = 0;
		for (i = strlen(str) - 1; i >= 0; --i) {
			if (str[i] == sub_s[6])
				DP[i] = ++count;
			else
				DP[i] = count;
		}
		
		DP[strlen(str)] = 0;
		for (i = 5; i >= 0; --i) {
			for (j = strlen(str) - 1; j >= 0; --j) {
				if (str[j] == sub_s[i])
					DP[j] += DP[j + 1];
				else
					DP[j] = DP[j + 1];
			}
		}

		cout << '#' << test << " " << DP[0] % 1000000007 << '\n';
	}
	return 0;
}