#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<vector <int>> graph;
vector<int> res;
vector<bool> used;

void dfs(int b)
{
    used[b] = true;
    int now = 0;
    for (int i = 0; i < graph[b].size(); i++) 
    {
        int e = graph[b][i];
        if (!used[e])
            dfs(e);
        
        if (res[e] == 0)
            now = 1;
    }
    res[b] = now;
}
        
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    
    int n, m, s;
    int b, e;
    cin >> n >> m >> s;
    graph.resize(n);
    res.resize(n);
    used.resize(n, false);
    
    for (int i = 0; i < m; i++)
    {
        cin >> b >> e;
        graph[b - 1].push_back(e - 1);
    }
    
    dfs(s-1);
    
    if(res[s-1])
        cout << "First player wins" << endl;
    else cout << "Second player wins" << endl;
        
	return 0;
}