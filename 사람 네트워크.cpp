#include<iostream>
using namespace std;
 
int dist[1000][1000];
#define INF 987654321
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int test = 1; test <= T; test++) {
        int N; cin >> N;
 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> dist[i][j];
                if (!dist[i][j])
                    dist[i][j] = INF;
            }
        }
 
        for (int i = 0; i < N; i++)
            dist[i][i] = 0;
        for (register int via = 0; via < N; via++) 
            for (register int from = 0; from < N; from++)
                for (register int to = 0; to < N; to++)
                    if (dist[from][to] > dist[from][via] + dist[via][to])
                        dist[from][to] = dist[from][via] + dist[via][to];
 
        int ans = INF;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++)
                sum += dist[i][j];
            ans = ans < sum ? ans : sum;
        }
 
        cout << '#' << test << ' ' << ans << '\n';
    }
    return 0;
}
