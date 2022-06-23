#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<vector <int>> graph;
vector<int> path;
vector<bool> used;

void dfs(int b)
{
    used[b] = true;
    for (int i = 0; i < graph[b].size(); i++) 
    {
        int e = graph[b][i];
        if (!used[e])
            dfs(e);
    }
    path.push_back(b);
}
        
bool exist(int b, int e) 
{
    for (int i = 0; i < graph[b].size(); i++)
        if (graph[b][i] == e)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    
    int n, m;
    int b, e;
    cin >> n >> m;
    graph.resize(n);
    used.resize(n, false);
    
    for (int i = 0; i < m; i++)
    {
        cin >> b >> e;
        graph[b - 1].push_back(e - 1);
    }
    
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
            
    for (int i = n - 1; i > 0; i--)
        if (!exist(path[i], path[i - 1])) 
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
        
	return 0;
}