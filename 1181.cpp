#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<string.h>

using namespace std;

class custom_string{
public:
	string str;

	bool operator<(const custom_string& tmp) {
		if (str.length() != tmp.str.length())
			return str.length() < tmp.str.length();

		return str < tmp.str;
	}

	bool operator==(const custom_string& tmp) {
		return str == tmp.str;
	}
};

istream& operator>>(istream& is, custom_string& cstr) {
	return is >> cstr.str;
}

ostream& operator<<(ostream& os, custom_string& cstr) {
	return os << cstr.str;
}

void quick_sort(custom_string arr[], int left, int right) {
	int i = left;
	int j = right;
	custom_string pivot = arr[(left + right) / 2];
	custom_string tmp;
	do {
		while (arr[i] < pivot)
			i++;
		while (pivot < arr[j])
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	
	if (left < j)
		quick_sort(arr, left, j);
	if (right > i)
		quick_sort(arr, i, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	custom_string cus_string[20001];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> cus_string[i];

	quick_sort(cus_string, 0, N-1);
	custom_string prev;
	for (int i = 0; i < N; i++) {
		if (cus_string[i] == prev)
			continue;
		cout << cus_string[i] << '\n';
		prev = cus_string[i];
	}
}
