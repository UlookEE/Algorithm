#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int pow(int num, int N) {
	if (N == 1)
		return num;
	else {
		return num * pow(num, N - 1);
	}
}

bool is_exp(int num, int N) {
	if (num == 1)
		return true;

	if (num % N == 0)
		return is_exp(num / N, N);
	else
		return false;
}
int arr[10000];
int arr2[10000];
int K;

int count = 1;
void in_order(int index, int depth) {
	if (depth > K)
		return;
	in_order(index * 2, depth + 1);
	arr2[index] = arr[count++];
	in_order(index * 2 + 1, depth + 1);
}
int main(void)
{
	scanf("%d", &K);
	int arr_size = pow(2, K) - 1;

	for (int i = 1; i <= arr_size; i++)
		scanf("%d", arr + i);

	in_order(1, 1);
	for (int i = 1; i <= arr_size; i++) {
		printf("%d ", arr2[i]);
		if (is_exp(i + 1, 2))
			printf("\n");
	}
	return 0;
}
