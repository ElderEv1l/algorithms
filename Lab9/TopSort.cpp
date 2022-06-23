#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
enum color {
    white,
    gray,
    black
};

vector < vector <int> > graph;
vector <color> col;
vector <int> res;
bool check = false;

void dfs(int t) 
{
    col[t] = gray;
    for (int i = 0; i < graph[t].size(); i++) 
    {
        int e = graph[t][i];
        if (col[e] == white)
            dfs(e);
            
        if (col[e] == gray)
        {
            check = true;
            return;
        }
    }
    col[t] = black;
    res.push_back(t);
}

void topsort() 
{
    for (int i = 1; i < graph.size(); i++)
        col[i] = white;
    res.clear();
    for (int i = 1; i < graph.size(); i++)
        if (col[i] == white)
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    
    int n, m;
    int b, e;
    cin >> n >> m;
    
    graph.resize(n + 1);
    col.resize(n + 1);
    res.resize(n + 1);
    
    for (int i = 1; i <= m; i++) 
    {
        cin >> b >> e;
        graph[b].push_back(e);
    }
    
    topsort();
    if (check)
        cout << "-1" << endl;
    else
        for (int i = n - 1; i >= 0; i--)
            cout << res[i] << " ";
    return 0;
}