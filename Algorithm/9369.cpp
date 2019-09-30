#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

typedef vector<string> vs;
typedef vector<char> vc;

vc* encVec;
vc* decVec;

char enc[26];
char decr[26];
bool solved;
void predict(string& decStr, string& encStr) {
	memset(enc, 0, 26);
	memset(decr, 0, 26);
	int str_len = decStr.length();
	if (str_len != encStr.length())
		return;
	else {
		int used_alphabet = 0;
		for (int i = 0; i < str_len; i++) {
			if (enc[decStr[i] - 'a'] == 0) {
				enc[decStr[i] - 'a'] = encStr[i];
				used_alphabet++;
			}
			else if (enc[decStr[i] - 'a'] != encStr[i]) {/// enc : abc,  dec : aaa
				return;
			}
		}
		for (int i = 0; i < str_len; i++) {
			if (decr[encStr[i] - 'a'] == 0)
				decr[encStr[i] - 'a'] = decStr[i];
			else if (decr[encStr[i] - 'a'] != decStr[i]) {/// enc : aaa,  dec : abc
				return;
			}
		}
		if (used_alphabet == 25) {
			int last_enc, last_dec;
			for (int i = 0; i < 26; i++) {
				if (enc[i] == 0)
					last_enc = i;
				if (decr[i] == 0)
					last_dec = i;
			}
			enc[last_enc] = last_dec + 'a';
			decr[last_dec] = last_enc + 'a';
		}
	}
	for (int i = 0; i < 26; i++) {
		if (find(encVec[i].begin(), encVec[i].end(), enc[i]) == encVec[i].end() && enc[i] != 0)
			encVec[i].push_back(enc[i]);
		if (find(decVec[i].begin(), decVec[i].end(), decr[i]) == decVec[i].end() && decr[i] != 0)
			decVec[i].push_back(decr[i]);
	}
	solved = true;

}
int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vs encryptVec;
		string decrypt;
		encVec = new vc[26];
		decVec = new vc[26];

		for (int i = 0; i < N; i++) {
			string input_string; cin >> input_string; encryptVec.push_back(input_string);
		}

		cin >> decrypt;
		solved = false;
		string result; cin >> result;
		for (int i = 0; i < N; i++) {
			predict(decrypt, encryptVec[i]);
		}



		for (int i = 0; i < result.length(); i++) {
			char c = result[i] - 'a';
			if (decVec[c].size() != 1) {
				result[i] = '?';
			}
			else {
				if (encVec[decVec[c][0] - 'a'].size() == 1 && encVec[decVec[c][0] - 'a'][0] == result[i]) {
					result[i] = decVec[c][0];

				}
				else
					result[i] = '?';
			}

		}
		if (solved)
			cout << result << endl;
		else
			cout << "IMPOSSIBLE" << endl;;
	}
	return 0;
}

