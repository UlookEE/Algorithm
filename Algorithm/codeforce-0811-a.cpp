#include <iostream>
#include <bitset>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	register char arr[10];
	register int T;
	register int K;
	register int nS;
	register int S = 0xFFFFFC00;
	cin >> T;
	while (T--) {
		register char c; cin >> c;
		if (c == 'L') {
			K = 1 << 9;
			while (K & S)
				K >>= 1;
			S |= K;
		}
		else if (c == 'R') {
			nS = ~S;
			K = (nS & (-nS));
			S |= K;
		}
		else {
			S &= ~(1 << 9 >> (c-'0'));
		}

	}
	register bitset<10> x(S);
	cout << x << '\n';
	return 0;
}