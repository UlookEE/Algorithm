#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

int N, B, C;
int arr[1000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> B >> C;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum++;
		arr[i] -= B;
		if (arr[i] > 0) {
			int share = arr[i] / C;
			int remainder = arr[i] % C;
			sum += share;
			if (remainder != 0)
				sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
