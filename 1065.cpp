#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		vector<int> v;
		int n = i;
		while (n != 0) {
			v.push_back(n % 10);
			n /= 10;
		}
		bool flag = true;
		int gap;
		if (v.size() >= 2) {
			gap = v[1] - v[0];	
		}
		
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i + 1] - v[i] != gap) {
				flag = false;
				break;
			}
		}
		if (flag)
			count++;
	}
	cout << count << endl;
	return 0;
}
