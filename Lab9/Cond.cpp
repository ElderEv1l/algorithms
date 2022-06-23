#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<vector <int>> graph; 
vector<vector <int>> rev;
vector<int> sort;
vector<int> component;
vector<bool> used;
int k = 1;

void dfs(int b) 
{
    used[b] = true;
    for (int i = 0; i < graph[b].size(); i++) 
    {
        int to = graph[b][i];
        if (!used[to])
            dfs(to);
    }
    sort.push_back(b);
}

void revdfs(int b) 
{
    used[b] = true;
    component[b] = k;
    for (int i = 0; i < rev[b].size(); i++) 
    {
        int to = rev[b][i];
        if (!used[to])
            revdfs(to);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    
    int n, m;
    int b, e;
    cin >> n >> m;
    rev.resize(n);
    graph.resize(n);
    used.resize(n, false);
    component.resize(n);
    
    for (int i = 0; i < m; i++) 
    {
        cin >> b >> e;
        graph[b - 1].push_back(e - 1);
        rev[e - 1].push_back(b - 1);
    }
    
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
            
    used.assign(n, false);
    for (int i = 0; i < n; i++) 
    {
        int t = sort[n - i - 1];
        if (!used[t]) 
        {
            revdfs(t);
            k++;
        }
    }
    
    cout << k - 1 << endl;
    for (int i = 0; i < n; i++)
        cout << component[i] << ' ';
        
	return 0;
}