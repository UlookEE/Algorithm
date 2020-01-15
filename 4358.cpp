#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

#define ARR_SIZE 1000007
#define MAX_LEN 31
#define INF 2000000000

class HashTable {
public:
	char **table;
	int * hit;
	vector<string> used;
	HashTable() {
		table = new char *[ARR_SIZE];
		for (int i = 0; i < ARR_SIZE; i++) {
			table[i] = new char[MAX_LEN];
			memset(table[i], 0, MAX_LEN);
		}
		hit = new int[ARR_SIZE];
		memset(hit, 0, ARR_SIZE * 4);
	}

	~HashTable() {
		for (int i = 0; i < ARR_SIZE; i++)
			delete[] table[i];
		delete[] table;
		delete[] hit;
	}

	unsigned int hash(const char * str, int prime) {
		unsigned int val = 0;
		unsigned int i = 0;
		while (*(str+i) != NULL) {
			val = val * prime + *(str + i);
			i++;
		}
		
		return val % ARR_SIZE;
	}

	void push_table(const char * str) {
		unsigned int index = hash(str, 41);
		unsigned int plus = hash(str, 43);
		while (true) {
			if (strcmp(table[index], str) == 0)
				return;
			if (strcmp(table[index], "") == 0) {
				memcpy(table[index], str, MAX_LEN);
				used.push_back(str);
				return;
			}
			index = (index + plus) % ARR_SIZE;
		}
	}

	unsigned int find_table(const char * str) {
		unsigned int index = hash(str, 41);
		unsigned int plus = hash(str, 43);
		while (true) {
			if (strcmp(table[index], str) == 0) {
				return index;
			}
			if (strcmp(table[index], "") == 0)
				return -1;
			index = (index + plus) % ARR_SIZE;

		}
	}
};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	HashTable ht;
	int str_cnt = 0;
	while (getline(cin, str)) {
		str_cnt++;
		if (ht.find_table(str.c_str()) == -1) {
			ht.push_table(str.c_str());
		}
		ht.hit[ht.find_table(str.c_str())]++;
	}
	sort(ht.used.begin(), ht.used.end());

	cout << fixed;
	cout.precision(4);
	for (int i = 0; i < ht.used.size(); i++) {
		unsigned int ind = ht.find_table(ht.used[i].c_str());
		cout << ht.table[ind] << " " << (double)ht.hit[ind] / str_cnt * 100 <<'\n';
	}
	
	return 0;
}
