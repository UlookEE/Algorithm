#include<iostream>
#include<algorithm>
#include<string.h>
#include<sstream>
#include<queue>
using namespace std;
 
char arr[1000];
 
void inorder(int v) {
    if (arr[v * 2])
        inorder(v * 2);
    cout << arr[v];
    if (arr[v * 2 + 1])
        inorder(v * 2 + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int test = 1; test <= 10; test++) {
        int N; cin >> N;
        memset(arr, 0, sizeof(arr));
        cin.ignore(2, '\n');
        for (int i = 0; i < N; i++) {  
			string inputS;
            getline(cin, inputS);
			stringstream ss(inputS);
            int v;
            char c;
            ss >> v >> c;
            arr[v] = c;
        }
        cout << '#' << test << ' ';
        inorder(1);
        cout << '\n';
    }
    return 0;
}
