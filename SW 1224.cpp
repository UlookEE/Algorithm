#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
#include<vector>
#include<string.h>
#include<stack>
#include<list>
using namespace std;

string calcString;
int opPrio[257];


inline bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	opPrio['+'] = 1;
	opPrio['-'] = 1;
	opPrio['*'] = 2;
	opPrio['/'] = 2;
	opPrio['('] = 3;
	opPrio[')'] = 0;

	for (int test = 1; test <= 10; test++) {
		int noneVal; cin >> noneVal;
		cin >> calcString;
		vector<char> postfix;
		stack<char> op;
		for (int i = 0; i < calcString.size(); i++) {
			char c = calcString[i];

			if (isDigit(c))
				postfix.push_back(c);
			else {
				if (op.empty() || opPrio[op.top()] < opPrio[c])
					op.push(c);
				else {
					if (c == ')') {
						while (op.top() != '(') {
							postfix.push_back(op.top());
							op.pop();
						}
						op.pop();
					}
					else {
						while (!op.empty() && opPrio[op.top()] >= opPrio[c] && op.top() != '(') {
							postfix.push_back(op.top());
							op.pop();
						}
						op.push(c);
					}
				}
			}
		}
		while (!op.empty()) {
			postfix.push_back(op.top());
			op.pop();
		}

		stack<int> calcStack;
		for (int i = 0; i < postfix.size(); i++) {
			if (isDigit(postfix[i])) {
				calcStack.push(postfix[i] - '0');
			}
			else {
				int n1 = calcStack.top(); calcStack.pop();
				int n2 = calcStack.top(); calcStack.pop();
				if (postfix[i] == '+')
					calcStack.push(n1 + n2);
				else if (postfix[i] == '-')
					calcStack.push(n1 - n2);
				else if (postfix[i] == '*')
					calcStack.push(n1 * n2);
				else if (postfix[i] == '/')
					calcStack.push(n1 / n2);
			}
		}
			cout << '#' << test << ' ' << calcStack.top() << '\n';
	}

	return 0;
}
