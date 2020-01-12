#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

string phone_number[10001];

class Trie {
public:
	bool isTerminal;
	Trie* child[10];

	Trie() : isTerminal(false) {
		memset(child, 0, sizeof(child));
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (child[i])
				delete child[i];
		}
	}

	void insert(const char* key) {
		if (*key == 0)
			isTerminal = true;
		else {
			int index = *key - '0';
			if (child[index] == 0)
				child[index] = new Trie();

			child[index]->insert(key + 1);
		}
		
	}

	Trie* find(const char* key) {
		if (*key == 0)
			return this;
		
		int index = *key - '0';

		if (child[index] == NULL)
			return NULL;

		return child[index]->find(key + 1);
	}

	bool isPrefix() {
		for (int i = 0; i < 10; i++) {
			if (child[i] != NULL)
				return true;
		}
		return false;
	}
};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		Trie* trie = new Trie();
		for (int i = 0; i < N; i++) {
			cin >> phone_number[i];
			trie->insert(phone_number[i].c_str());
		}
		
		for (int i = 0; i < N; i++) {
			if (trie->find(phone_number[i].c_str())->isPrefix()) {
				cout << "NO\n";
				break;
			}
			if(i == N-1)
				cout << "YES\n";
		}
		
	}
	

	return 0;
}
