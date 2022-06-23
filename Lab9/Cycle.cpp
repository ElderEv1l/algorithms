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

int start = -1, finish;
vector<vector <int>> graph;
vector<color> col;
vector<int> p;


bool dfs(int& b, vector<vector<int>>& graph, vector<color>& col, vector<int>& p) 
{
	col[b] = gray;
	for (int i = 0; i < graph[b].size(); i++) 
	{
		int e = graph[b][i];
		if (col[e] == white) 
		{
			p[e] = b;
			if (dfs(e, graph, col, p))
				return true;
		}
		else if (col[e] == gray) 
		{
		   	start = e;
			finish = b;
			return true;
		}
	}
	col[b] = black;
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    
    int n, m;
    int b, e;
    
	cin >> n >> m;
	graph.resize(n);
	col.resize(n, white);
	p.resize(n);
	
	for (int i = 0; i < m; i++)
	{
		cin >> b >> e;
		if (b == e) 
		{
			cout << "YES" << endl << e;
			return 0;
		}
		graph[b - 1].push_back(e - 1);
	}
	
	for (int i = 0; i < n; i++)
		if (dfs(i, graph, col, p) && col[i] == white)
			break;
			
	if (start != -1) 
	{
		cout << "YES" << endl;
		vector <int> res;
		
		for (int now = finish; now != start; now = p[now])
			res.push_back(now);
		res.push_back(start);
		
		for (int i = res.size() - 1; i >= 0; i--)
			cout << res[i] + 1 << ' ';
	}
	else
		cout << "NO";
	return 0;
}