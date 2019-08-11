#pragma once

#include<vector>
#include "bitMask.h"
typedef std::vector<int> vi;

class FenwickTree {
private: 
	vi ft;
public:
	FenwickTree(int n) {
		ft.assign(n + 1, 0);
	}

	FenwickTree(int n, const vi& _ft) {
		ft.assign(n + 1, 0);
		for (int i = 0; i < _ft.size(); i++) {
			adjust(_ft[i], 1);
		}
	}

	int rsq(int b) {	//calculate range 1~b
		int sum = 0;
		for (; b; b -= LSOne(b))	//to use index 0 change LSOne function
			sum += ft[b];			//because is nedd to escape for statement
		return sum;
	}
	int rsq(int a, int b) {
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	void adjust(int k, int v) {
		for (; k < (int)ft.size(); k += LSOne(k))
			ft[k] += v;
	}
};