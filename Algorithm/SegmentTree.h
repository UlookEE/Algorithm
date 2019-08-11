#pragma once

#include<vector>

typedef std::vector<int> vi;

class SegmentTree {
private:
	vi st, A;
	int n;
	int left(int p) {
		return p << 1;
	}
	int right(int p) {
		return (p << 1) + 1;
	}
	void rmq_build(int p, int  L, int R) {
		if (L == R) {
			st[p] = L;
		}
		else {
			rmq_build(left(p), L, (L + R) / 2);
			rmq_build(right(p), (L + R) / 2 + 1, R);
			int c1 = st[left(p)], c2 = st[right(p)];
			st[p] = (A[c1] <= A[c2]) ? c1 : c2;
		}

	}

	int rmq(int p, int L, int R, int i, int j) {	//find minimun value of range
		if (i > R || j < L) return -1;

		if (L >= i && R <= j) return st[p];		//right의 왼쪽이 범위 밖이면 left의 오른쪽이 범위와 딱 맞는다는 뜻이다 반대쪽도 마찬가지.

		int c1 = rmq(left(p), L, (L + R) / 2, i, j);
		int c2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

		if (c1 == -1) return c2;
		if (c2 == -1) return c1;

		return (A[c1] <= A[c2]) ? c1 : c2;
	}

	void rsq_build(int p, int L, int R) {
		if (L == R) {
			st[p] = A[L];
		}
		else {
			rsq_build(left(p), L, (L + R) / 2);
			rsq_build(right(p), (L + R) / 2 + 1, R);
			st[p] = st[left(p)] + st[right(p)];
		}
	}

	int rsq(int p, int L, int R, int i, int j) {	//find sum of range
		if (i > R || j < L) return  0;

		if (L >= i && R <= j) return st[p];		//right의 왼쪽이 범위 밖이면 left의 오른쪽이 범위와 딱 맞는다는 뜻이다 반대쪽도 마찬가지.

		int c1 = rsq(left(p), L, (L + R) / 2, i, j);
		int c2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);

		return c1 + c2;
	}

public:
	SegmentTree(const vi & _A) {
		A = _A;
		n = (int)A.size();
		st.assign(4 * n, 0);
		rmq_build(1, 0, n - 1);
		//rsq_build(1, 0, n - 1);
	}

	int rmq(int i, int j) {
		return rmq(1, 0, n - 1, i, j);
	}

	int rsq(int i, int j) {
		return rsq(1, 0, n - 1, i, j);
	}
};