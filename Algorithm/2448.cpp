#include<iostream>
using namespace std;

//º° Âï±â 11

int a = 0;
int b = 6142 / 2;
bool arr[4000][7000];

// make triangle
void make_left(int k, int starta, int startb, int enda, int endb) {
	for (int i = starta; i < enda; i++) {
		for (int j = startb; j < endb; j++) {
			arr[i][j] = arr[i - k][j + k];
		}
	}
}

void make_right(int k, int starta, int startb, int enda, int endb) {
	for (int i = starta; i < enda; i++) {
		for (int j = startb; j < endb; j++) {
			arr[i][j] = arr[i - k][j - k];
		}
	}
}

void func(int n, int k) {
	if (n == k)
		return;
	else {
		make_left(k, k, b - k * 2 + 1, k + k, b);
		make_right(k, k, b + 1, k + k, b + k * 2);
		func(n, k * 2);
	}
}

// make first triangle
void set_arr(int n, int k) {
	arr[a][b] = 1;
	arr[a + 1][b + 1] = 1;
	arr[a + 1][b - 1] = 1;
	arr[a + 2][b - 2] = 1;
	arr[a + 2][b - 1] = 1;
	arr[a + 2][b - 0] = 1;
	arr[a + 2][b + 1] = 1;
	arr[a + 2][b + 2] = 1;
	func(n, k);
}

// print triangle
void view_triangle(int n) {
	int enda = n;
	int startb = b - n + 1;
	int endb = b + n;

	for (int i = 0; i < enda; i++) {
		for (int j = startb; j < endb; j++) {
			if (arr[i][j] == 0)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}
}
// main
int main() {
	int n;
	cin >> n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set_arr(n, 3);
	view_triangle(n);

	return 0;
}