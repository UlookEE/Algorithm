#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int tmp;
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			cin >> tmp;
			sum += tmp;
		}
		
		cout << "#" << 3 - T << " " << round(sum / (double)10) << "\n";
	}
	return 0;
}