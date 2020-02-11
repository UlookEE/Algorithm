#include<iostream>
using namespace std;

int N;
int numArr[11];
int opArr[11];
int opArrInd = 0;
inline void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void reverse(int *first, int * last) {
	last--;
	while (first < last) {
		swap(*first, *last);
		first++;
		last--;
	}
}
bool next_permutation(int * first, int * last) {
	if (first == last || first + 1 == last) {
		return false;
	}
	int * i = last - 1;
	int * ii = last;
	while (true) {
		i--;
		ii--;
		if (*i < *ii) {
			int * j = last;
			while (*i >= *(--j));
			swap(*i, *j);
			reverse(ii, last);
			return true;
		}
		if (i == first) {
			reverse(first, last);
			return false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> numArr[i];
	for (int i = 0; i < 4; i++) {
		int opCount; cin >> opCount;
		for (int j = 0; j < opCount; j++)
			opArr[opArrInd++] = i;
	}

	int max_ans = -1000000000;
	int min_ans = 1000000000;
	do {
		int res = numArr[0];
		for (int i = 1; i < N; i++) {
			switch (opArr[i-1])
			{
			case 0:
				res += numArr[i];
				break;
			case 1:
				res -= numArr[i];
				break;
			case 2:
				res *= numArr[i];
				break;
			case 3:
				res /= numArr[i];
				break;
			default:
				break;
			}
		}
		max_ans = res > max_ans ? res : max_ans;
		min_ans = res < min_ans ? res : min_ans;
	} while (next_permutation(opArr, opArr + N - 1));

	cout << max_ans << endl << min_ans << endl;
	return 0;
}
