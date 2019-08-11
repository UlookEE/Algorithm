#include<iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int tmp;
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			cin >> tmp;
			if (tmp % 2 == 1)
				sum += tmp;
		}
		cout << "#" << 3 - T << " " << sum << "\n";
	}
	return 0;
}