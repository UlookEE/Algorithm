#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define ARR_SIZE 1000007

char hashTable[ARR_SIZE][30];
int parent[ARR_SIZE];
int union_size[ARR_SIZE];

int find_root(int index) {
	if (parent[index] == index)
		return index;

	return parent[index] = find_root(parent[index]);
}

void union_set(int ind1, int ind2) {
	int root1 = find_root(ind1);
	int root2 = find_root(ind2);
    if(root1!=root2)
	union_size[root2] += union_size[root1];
	parent[root1] = root2;
}

unsigned int make_hash(char * str, unsigned int prime) {
	unsigned int val=0;
	while (*str != NULL) {
		val += *str * prime;
		prime *= prime;
		str++;
	}
	return val % ARR_SIZE;
}

unsigned int get_index(char * str) {
	unsigned int index = make_hash(str, 11);
	unsigned int jmp = make_hash(str, 13);
	while (hashTable[index][0] != NULL && strcmp(str, hashTable[index])) {
		index = (index + jmp) % ARR_SIZE;
	}

	if (hashTable[index][0] == NULL)
		return -1;
	else
		return index;
}

void push_table(char * str) {
	unsigned int index = make_hash(str, 11);
	unsigned int jmp = make_hash(str, 13);
	while (hashTable[index][0] != NULL)
		index = (index + jmp) % ARR_SIZE;

	memcpy(hashTable[index], str, strlen(str));
	parent[index] = index;
	union_size[index] = 1;	
}
int main(void)
{
	int T; scanf("%d", &T);
	while (T--) {
		int F; scanf("%d", &F);
		memset(hashTable, 0, ARR_SIZE * 30);

		while (F--) {
			char str1[30]; char str2[30];
			scanf("%s %s", str1, str2);
			if (get_index(str1) == -1)
				push_table(str1);

			if (get_index(str2) == -1)
				push_table(str2);

			unsigned int ind1 = get_index(str1);
			unsigned int ind2 = get_index(str2);
			union_set(ind1, ind2);
			printf("%d\n", union_size[find_root(ind1)]);
		}
	}

	return 0;
}
