#include<iostream>

using namespace std;

long long int DP[30][30];
int main(){
    int T; cin>>T;
    for(int i=0; i<30; i++){
        DP[i][0] = DP[i][i] = 1;
        for(int j=1; j<i; j++){
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
        }
    }
    while(T--){
        int N, M; cin>>N>>M;
        cout<<DP[M][N]<<endl;
    }
}