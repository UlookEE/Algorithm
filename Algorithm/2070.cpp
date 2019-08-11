#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << "#" << 3-T << " ";

		if (a > b) {
			cout << ">" << endl;
		}
		else if (a == b) {
			cout << "=" << endl;
		}
		else if (a < b) {
			cout << "<" << endl;
		}
	}
	return 0;
}