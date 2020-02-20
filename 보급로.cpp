#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
int T, N;
char arr[102][102];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
 
struct Edge {
    int y;
    int x;
    int w;
};
 
#define INF 987654321
vector<Edge> v[101][101];
int dist[101][101];
 
struct PQNode {
    int w;
    int y;
    int x;
};
inline bool in_range(int y, int x) {
    return x >= 0 && y >= 0 && x < N && y < N;
}
 
void dijkstra() {
    for (int i = 0; i < N; i++)
        fill(dist[i], dist[i] + N, INF);
    auto cmpPQN = [](PQNode& p1, PQNode& p2) -> bool {return p1.w > p2.w; };
    priority_queue<PQNode, vector<PQNode>, decltype(cmpPQN)> pq(cmpPQN);
    pq.push({ 0,0,0 });
    dist[0][0] = 0;
    while (!pq.empty()) {
        auto n = pq.top(); pq.pop();
        if (dist[n.y][n.x] < n.w)
            continue;
        for (int i = 0; i < v[n.y][n.x].size(); i++) {
            int ny = v[n.y][n.x][i].y;
            int nx = v[n.y][n.x][i].x;
            int w = v[n.y][n.x][i].w;
            if (dist[ny][nx] > dist[n.y][n.x] + w) {
                dist[ny][nx] = dist[n.y][n.x] + w;
                pq.push({ dist[ny][nx], ny, nx });
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
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                arr[i][j] -= '0';
                v[i][j].clear();
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (in_range(ny, nx)) {
                        v[i][j].push_back({ ny, nx, arr[ny][nx]});
                        v[ny][nx].push_back({ i, j, arr[i][j]});
                    }
                }
            }
        }
 
        dijkstra();
        cout << '#' << test << ' ' << dist[N - 1][N - 1] << endl;
    }
    return 0;
}
