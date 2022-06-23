#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
 
vector < vector <int> > graph;
vector <bool> used;
vector <int> c;
int nc = 0;

void dfs(int v) 
{
    used[v] = true;
    c[v] = nc;
    for (int i = 0; i < graph[v].size(); i++) 
    {
        int t = graph[v][i];
        if (!used[t])
            dfs(t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    used.resize(n);
    c.resize(n);
    
    for (int i = 0; i < m; i++) 
    {
        int b, e;
        cin >> b >> e;
        graph[b - 1].push_back(e - 1);
        graph[e - 1].push_back(b - 1);
    }
    
    for (int i = 0; i < graph.size(); i++)
        if (!used[i]) 
        {
            nc++;
            dfs(i);
        }
    cout << nc << endl;
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";

	return 0;
}