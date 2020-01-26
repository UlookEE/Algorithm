#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001][1001];
int DP[1001][1001];
int main(){
    int N, M; cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
        }
    }
    DP[1][1] = arr[1][1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            DP[i][j+1] = max(DP[i][j]+arr[i][j+1], DP[i][j+1]);
            DP[i+1][j] = max(DP[i][j]+arr[i+1][j], DP[i+1][j]);
            DP[i+1][j+1] = max(DP[i][j]+arr[i+1][j+1], DP[i+1][j+1]);
        }
    }
    cout<<DP[N][M]<<endl;
}
