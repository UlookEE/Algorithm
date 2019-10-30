#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef stack<int> si;

int N, M;
vi facility[100000];
vi facility_inv[100000];
bool visited[100000];
bool used[100000];
si dfsStack;
void dfs(int v)
{
    visited[v] = true;
    for (int i = 0; i < facility[v].size(); i++)
    {
        int next_v = facility[v][i];
        if (!visited[next_v])
            dfs(next_v);
    }
    dfsStack.push(v);
}

void dfs2(int v)
{
    visited[v] = true;
    for (int i = 0; i < facility[v].size(); i++)
    {
        int next_v = facility[v][i];
        if (!visited[next_v])
            dfs2(next_v);
    }
}
int main()
{
    cin >> N >> M;
    int ans = N;
    while (M--)
    {
        int from, to;
        cin >> from >> to;
        facility[from].push_back(to);
        facility_inv[to].push_back(from);
        if(!used[from]){
            used[from] = true;
            ans--;
        }
        if(!used[to]){
            used[to] = true;
            ans--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && used[i])
            dfs(i);
    }

    memset(visited, 0, sizeof(visited));
    
    while(!dfsStack.empty())
    {
        int v = dfsStack.top();
        dfsStack.pop();
        if (!visited[v] && used[v])
        {
            dfs2(v);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}