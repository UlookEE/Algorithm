#include<iostream>
#include<cstring>
using namespace std;
 
double arr[17][17];
int N;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };
 
double res = 0;
 
void DFS(int depth, int flag, double ans) {
    if (ans <= res)
        return;
 
    if (depth == N) {
        res = ans > res ? ans : res;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (((1 << i) & flag) == 0) { 
            int nflag = flag | (1 << i);
            DFS(depth + 1, nflag, ans * arr[depth][i]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int test = 1; test <= T; test++) {
        cin >> N;
        res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                arr[i][j] /= 100;
            }
        }
        DFS(0, 0, 1);
 
        cout.precision(6);
        cout<<fixed;
        cout << '#' << test << ' ' << res*100 << '\n';
    }
    return 0;
}
