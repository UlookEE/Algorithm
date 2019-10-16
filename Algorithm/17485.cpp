#include <iostream>
using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INVALID 0x7FFFFFFF

int N, M;
int dx[] = {-1, 0, 1};
int dp[1001][1001][3];
int arr[1001][1001];

int k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    register int i, j;

    cin >> N >> M;

    for (i = 0; i < M; i++)
    {
        cin >> arr[0][i];
        dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = arr[0][i];
    }

    for (i = 1; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            dp[i][j][0] = j + 1 < M ? MIN(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + arr[i][j] : INVALID;
            dp[i][j][1] = MIN(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];
            dp[i][j][2] = j - 1 >= 0 ? MIN(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + arr[i][j] : INVALID;
        }
    }

    for (j = 0; j < M; j++)
    {
        dp[N][j][0] = j + 1 < M ? MIN(dp[N - 1][j + 1][1], dp[N - 1][j + 1][2]) + arr[N][j] : INVALID;
        dp[N][j][1] = MIN(dp[N - 1][j][0], dp[N - 1][j][2]) + arr[N][j];
        dp[N][j][2] = j - 1 >= 0 ? MIN(dp[N - 1][j - 1][0], dp[N - 1][j - 1][1]) + arr[N][j] : INVALID;
    }
    
    int minVal = INVALID;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (minVal > dp[N][i][j])
                minVal = dp[N][i][j];
        }
    }
    cout << minVal << '\n';
    return 0;
}