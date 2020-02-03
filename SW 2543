#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;

struct Node {
	int val;
	int left; 
	int right;
	bool isOperator;
};

Node tree[1001];

double inOrder(int v) {
	if (tree[v].isOperator == true) {
		if(tree[v].val == '+')
			return inOrder(tree[v].left) + inOrder(tree[v].right);
		else if(tree[v].val == '-')
			return inOrder(tree[v].left) - inOrder(tree[v].right);
		else if (tree[v].val == '*')
			return inOrder(tree[v].left) * inOrder(tree[v].right);
		else if (tree[v].val == '/')
			return inOrder(tree[v].left) / inOrder(tree[v].right);
	}
	else {
		return tree[v].val;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int test = 1; test <= 10; test++) {
		int N; cin >> N;
		memset(tree, 0, sizeof(tree));
		cin.ignore(2, '\n');
		for (int i = 0;i < N; i++) {
			string input; getline(cin, input, '\n');
			stringstream ss(input);
			int nodeIndex;
			ss >> nodeIndex;
			ss.get();
			char c = ss.get();
			if(!(c >= '0' && c <='9')){
				ss.unget();
				ss>>(char&)tree[nodeIndex].val;
				ss >> tree[nodeIndex].left;
				ss >> tree[nodeIndex].right;
				tree[nodeIndex].isOperator = true;
			}
			else {
				ss.unget();
				ss>>tree[nodeIndex].val;
			}
		}
		int res = inOrder(1);
		cout << '#' << test << ' ' << res << '\n';
	}
	return 0;
}
