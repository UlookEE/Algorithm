#include <iostream>
#include <math.h>
using namespace std;


long long int find_next_square(long long int N) {
	return pow(int(sqrt(N)) + 1, 2);
}

int recursive(long long int N) {
	if (N == 1) {
		return 0;
	}
	if (N == 2) {
		return 0;
	}
	else if (N == (long long int)(pow(int(sqrt(N)), 2)))
		return recursive(sqrt(N)) + 1;
	else {
		return find_next_square(N) - N + recursive(find_next_square(N));
	}
}
int main() {
	int T;
	cin >> T;

	int t = 1;
	while (T--) {
		long long int N;
		cin >> N;
		cout << "#" << t << " " << recursive(N) << endl;
		t++;
	}
	return 0;
}