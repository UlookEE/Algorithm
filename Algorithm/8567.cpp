#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int divNum[100001];
int q[100001];

int main()
{
	int T;
	scanf("%d", &T);

	register int i, j;
	register int max = -1;
	register int maxIndex = -1;
	for (i = 1; i <= 100000; i++) {
		for (j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				if (j == i / j)
					divNum[i]++;
				else
					divNum[i] += 2;
			}
		}
		if (max <= divNum[i]) {
			max = divNum[i];
			maxIndex = i;
		}
		q[i] = maxIndex;
	}

	for (i = 1; i <= T; ++i)
	{
		scanf("%d", &j);
		printf("#%d %d\n", i, q[j]);
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}