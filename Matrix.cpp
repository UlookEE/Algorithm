#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
 
int T, N;
int arr[101][101];
typedef pair<int, int> ii;
#define f first
#define s second
ii screw[21];
vector<int> graph[21];
int used[21];
vector<int> path;
vector<int> maxPath;
class Matrix {
public:
    int hei;
    int wid;
    bool operator<(const Matrix& m) const {
        if (hei * wid != m.hei * m.wid)
            return hei * wid < m.hei * m.wid;
        return hei < m.hei;
    }
};
 
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
 
inline bool in_range(int y, int x) {
    return y >= 0 && x >= 0 && x < N && y < N;
}
 
vector<Matrix> ansVec;
void BFS(int y, int x) {
    int minY = y;
    int minX = x;
    int maxY = y;
    int maxX = x;
    queue<pair<int, int>>q;
    q.push({ y,x });
    while (!q.empty()) {
        auto e = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = e.first + dy[i];
            int nx = e.second + dx[i];
            if (in_range(ny, nx) && arr[ny][nx]) {
                q.push({ ny, nx });
                arr[ny][nx] = 0;
                maxY = max(maxY, ny);
                maxX = max(maxX, nx);
            }
        }
    }
    ansVec.push_back({ maxY - minY + 1, maxX - minX + 1 });
}
 
void dfs(int v) {
    if (maxPath.size() == N)
        return;
    for (int i = 0; i < graph[v].size(); i++) {
        if (!used[graph[v][i]]) {
            used[graph[v][i]] = true;
            path.push_back(graph[v][i]);
            if (path.size() > maxPath.size())
                maxPath = path;
            dfs(graph[v][i]);
            used[graph[v][i]] = false;
            path.pop_back();
        }
    }
}
 
int DP[21][21];
 
void calc_min() {
    for (int i = 0; i < N; i++)
        DP[i][i] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; i + j < N; j++) {
            for (int k = j; k < i + j; k++) {
                DP[j][j + i] = min(DP[j][k] + DP[k+1][i+j] + screw[maxPath[j]].f * screw[maxPath[k]].s * screw[maxPath[j + i]].second, DP[j][j + i]);
            }
        }
    }
 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cin >> arr[i][j];
        }
        ansVec.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j]) {
                    arr[i][j] = 0;
                    BFS(i, j);
                }
            }
        }
        maxPath.clear();
        path.clear();
        memset(used, 0, sizeof(used));
        N = ansVec.size();
        for (int i = 0; i < N; i++) {
            graph[i].clear();
            screw[i].first = ansVec[i].hei;
            screw[i].second = ansVec[i].wid;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    if (screw[i].s == screw[j].f)
                        graph[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            path.push_back(i);
            used[i] = true;
            dfs(i);
            path.pop_back();
            used[i] = false;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                DP[i][j] = 987654321;
            }
        }
        calc_min();
        cout << '#' << test << ' ' << DP[0][N - 1];
        cout << '\n';
    }
    return 0;
}
