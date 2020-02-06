#include<iostream>
#include<cstring>
using namespace std;
 
int arr[1001][1001];
int N;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };
 
int maxVal;
int maxAns;
 
inline bool in_range(int y, int x) {
    return y >= 0 && x >= 0 && y < N && x < N;
}
void DFS(int y, int x, int depth, int startV) {
    if (depth == maxAns) {
        maxVal = startV > maxVal ? maxVal : startV;
    }
    if (depth > maxAns) {
        maxAns = depth;
        maxVal = startV;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (in_range(ny, nx) && (arr[ny][nx] - arr[y][x] == 1)) {
            DFS(ny, nx, depth + 1, startV);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int test = 1; test <= T; test++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }
        maxAns = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                DFS(i, j, 1, arr[i][j]);
            }
        }
        cout << '#' << test << ' ' << maxVal << ' ' << maxAns << '\n';
    }
    return 0;
}
