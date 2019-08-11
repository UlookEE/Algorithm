#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int T, n, m, K;
int i;
int col[101];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	
	cin >> T;
	while (T--) {
		cin >> n >> m >> K;
		for (i = 0; i < n; i++)
			cin >> col[i];
		
		if (n == 1) {
			cout << "YES" << '\n';
			continue;
		}

		for (i = 0; i < n-1; i++) {
			int diff = col[i + 1] - col[i];
			if (diff >= 0) {
				if (diff - K > m) {
					cout << "NO" << '\n';
					break;					
				}
				else if(diff-K <=m && diff-K>=0) {
					m -= (diff - K);
					col[i] += (diff - K);
				}
				else if (diff - K < 0) {
					int get = K-diff;
					col[i] -= get;
					m += get;
					if (col[i] < 0) {
						m += col[i];
						col[i] = 0;
					}
				}
			}
			else if (diff < 0) {
				m += -diff;
				col[i] += diff;
				m += K;
				col[i] -= K;
				if (col[i] < 0) {
					m += col[i];
					col[i] = 0;
				}
			}
			
			if (i == n - 2)
				cout << "YES" << '\n';
		}
		
	}
	return 0;
}