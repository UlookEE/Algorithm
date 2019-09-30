#include<iostream>

using namespace std;


int main() {
	int arr[8] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
	for (int i = 0; i < 256; i++) {
		if (i == 0) {
			cout << 0 << ", ";
			continue;
		}
		for (int j = 0; j < 8; j++) {
			if (i & arr[j]) {
				cout << 7 - j << ", ";
				break;
			}
		}
		if (i % 16 == 15) {
			cout << endl;
		}
	}
}