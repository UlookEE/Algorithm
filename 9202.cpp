#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

class Trie {
public:
	Trie* child[26];
	Trie() {
		memset(child, 0, sizeof(child));
	}

	~Trie() {
		for (auto c : child)
			delete c;
	}

	void insert(char *str) {
		if (*str == NULL)
			return;
		int index = static_cast<int>(*str - 'A');
		if (child[index] == nullptr)
			child[index] = new Trie();
		child[index]->insert(str + 1);
	}

	bool find(char *str) {
		if (*str == 0)
			return true;
		int index = static_cast<int>(*str - 'A');
		if (child[index] != nullptr)
			return child[index]->find(str + 1);
		else
			return false;
	}

};

char arr[4][4];
bool visited[4][4];
char str[300001][9];
char cur_str[9];
int dx[8] = { -1,-1,-1, 0,0,1,1, 1 };
int dy[8] = { 1, 0,-1,-1,1,1,0,-1 };
Trie* trie;

inline bool in_range(int x, int y) {
	return (x < 0 || x > 3 || y < 0 || y > 3) ? false : true;
}

void brute_force(int x, int y, int depth) {
	if (depth == 8)
		return;

	visited[x][y] = true;
	cur_str[depth] = arr[x][y];
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in_range(nx, ny) && !visited[nx][ny])
			brute_force(nx, ny, depth + 1);
	}
	cur_str[depth + 1] = 0;
	trie->insert(cur_str);
	visited[x][y] = false;
}

void insert_trie() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			memset(visited, 0, 16);
			brute_force(i, j, 0);
		}
	}
}

int calc_score(const char * str) {
	int len = strlen(str);
	if (len <= 2)
		return 0;
	else if (len <= 4)
		return 1;
	else if (len == 5)
		return 2;
	else if (len == 6)
		return 3;
	else if (len == 7)
		return 5;
	else if (len == 8)
		return 11;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];

	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		trie = new Trie();
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> arr[j][k];
		insert_trie();
		int score = 0;
		int hit = 0;
		char max_str[9];
		memset(max_str, 0, sizeof(max_str));
		for (int j = 0; j < N; j++) {
			if (trie->find(str[j])) {
				score += calc_score(str[j]);
				hit++;
				if (strlen(max_str) < strlen(str[j]))
					strcpy(max_str, str[j]);
				else if ((strlen(max_str) == strlen(str[j])) && (strcmp(max_str, str[j]) == 1))
					strcpy(max_str, str[j]);
			}
		}

		cout << score << ' ' << max_str << ' ' << hit << '\n';
		delete trie;
	}
	return 0;
}
