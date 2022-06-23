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

vector<vector <int>> graph;
vector<color> col;
bool bigraph = true;

color revers(color col)
{
	if (col)
		return white;
	else
		return black;
}

void dfs(int b, color now) 
{
	col[b] = now;
	for (int i = 0; i < graph[b].size(); i++)
	{
		int e = graph[b][i];
		if (col[e] == white)
			dfs(e, revers(now));
		else if (col[e] == now)
		{
			bigraph = false;
			return;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    
    int n, m;
    int b, e;
	cin >> n >> m;
	
	graph.resize(n);
	col.resize(n, white);
	
	for (int i = 0; i < m; i++) 
	{
		cin >> b >> e;
		graph[b - 1].push_back(e - 1);
		graph[e - 1].push_back(b - 1);
	}
	
	for (int i = 0; i < n; i++)
		if (col[i] == white) 
		{
			dfs(i, white);
			if (!bigraph) 
			{
				cout << "NO";
				return 0;
			}
		}
	cout << "YES";
	return 0;
}