#include<iostream>
#include"FenwickTree.h"

int main() {
	int f[] = { 2,4,5,5,6,6,6,7,7,8,9 };
	FenwickTree ft(10, vi(f, f+sizeof(f)/sizeof(f[0])));

	printf("%d\n", ft.rsq(1, 1));
	printf("%d\n", ft.rsq(1, 2));
	printf("%d\n", ft.rsq(1, 6));
	printf("%d\n", ft.rsq(1, 10));
	printf("%d\n", ft.rsq(3, 6));
	ft.adjust(5, 2);
	printf("%d\n", ft.rsq(1, 10));
	return 0;
}