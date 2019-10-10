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

    register int i,j;
    
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(j=0; j<M; j++){
        for(k=0; k<3; k++){
            dp[0][j][k] = arr[0][j];
        }
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 0; j < M; j++)
        {
            dp[i][j][0] = j+1 < M ?  MIN(dp[i-1][j+1][1],dp[i-1][j+1][2]) + arr[i][j] : INVALID;
            dp[i][j][1] = MIN(dp[i-1][j][0],dp[i-1][j][2]) + arr[i][j];
            dp[i][j][2] = j-1 >= 0 ? MIN(dp[i-1][j-1][0],dp[i-1][j-1][1]) + arr[i][j] : INVALID;
        }
    }
    
    int minVal = INVALID;
    for(i=0;i<M; i++){
        for(j=0; j<3; j++){
            if(minVal > dp[N][i][j])
                minVal = dp[N][i][j];
        }
    }
    cout<<minVal<<'\n';
    return 0;
}