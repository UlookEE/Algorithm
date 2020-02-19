#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
vii cus;
int T,N;
#define x first
#define y second
typedef vector<int> vi;
vi perm;
int minDist = 987654321;
 
int calc_dist(ii p1, ii p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
void permutation(int n, int r) {
    if (r == 0) {
        int dist = 0;
        for (int i = 0; i < N - 1; i++) 
            dist += calc_dist(cus[perm[i]], cus[perm[i + 1]]);
        minDist = min(minDist, dist);
        return;
    }
    for (int i = n - 1; i >= 1; i--) {
        swap(perm[i], perm[n - 1]);
        permutation(n - 1, r - 1);
        swap(perm[i], perm[n - 1]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        minDist = 987654321;
        cus.clear();
        perm.clear();
        cin >> N;
        N += 2;
        for (int i = 0; i < N; i++) {
            int tx, ty; cin >> tx >> ty;
            cus.push_back({ tx, ty });
        }
        swap(cus[1], cus[N - 1]);
         
        perm.push_back(0);
        for (int i = 1; i < N - 1; i++)
            perm.push_back(i);
        perm.push_back(N - 1);
 
        permutation(N - 1, N - 2);
        cout << '#' << test << ' ' << minDist << endl;
    }
    return 0;
}
