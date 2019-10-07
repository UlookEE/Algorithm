#include<iostream>
#include<cstring>

using namespace std;

bool arr[1001][1001];
bool visit[1001];
int N; 

void DFS(int v){
	visit[v] = true;
	for(int i=1; i<=N; i++){
		if(arr[v][i] && !visit[i]){
			DFS(i);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T; cin >> T;
	while(T--){
		cin>>N;
		for(int i=1; i<=N; i++){
			memset(arr[i], 0, N+1);
		}
		memset(visit, 0, N+1);

		for(int i=1; i<=N; i++){
			int n; cin>>n;
			arr[i][n] = 1;
		}
		int count =0;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(arr[i][j] && !visit[i]){
					DFS(i);
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}