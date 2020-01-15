#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

char str[100001][81];
int countSum = 0;
bool initail = false;
class Trie {
public:
	bool isTerminal;
	vector<Trie*> child;
	char c;
	Trie() : isTerminal(false) {
		child.reserve(3);
	}

	~Trie() {
		for (int i = 0; i < child.size(); i++) {
			delete child[i];
		}
	}

	void insert(const char* key) {
		if (*key == 0)
			isTerminal = true;
		else {
			bool existFlag = false;
			int index;
			for (int i = 0; i < child.size(); i++) {
				if (child[i]->c == *key) {
					existFlag = true;
					index = i;
					break;
				}
			}
			if (!existFlag) {
				Trie* tmpTrie = new Trie();
				tmpTrie->c = *key;
				child.push_back(tmpTrie);
				index = child.size()-1;
			}

			child[index]->insert(key + 1);
		}
	}

	Trie* find(const char* key) {
		int index;
		if (*key == 0)
			return this;

		if (child.size() > 1 || isTerminal)
			countSum++;

		bool existFlag = false;
		for (int i = 0; i < child.size(); i++) {
			if (child[i]->c == *key) {
				existFlag = true;
				index = i;
				break;
			}
		}
		if (!existFlag)
			return NULL;
		return child[index]->find(key + 1);
	}
};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	while (cin >> N) {
		Trie* trie = new Trie();

		countSum = 0;
		for (int i = 0; i < N; i++) {
			cin >> str[i];
			trie->insert(str[i]);
		}

		for (int i = 0; i < N; i++) {
			trie->find(str[i]);
		}
		cout << fixed;
		cout.precision(2);

		if (trie->child.size() == 1)
			countSum += N;
		cout <<(double)countSum / N << '\n';	

		delete trie;
	}
	return 0;
}
