#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
  
vector <bool> is;
vector <pair <long long, long long>> graph[100000];

long long prim()
{
	long long res = 0;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> vertexq;
	vertexq.push(make_pair(0, 0));
	
	while (!vertexq.empty()) 
	{
		pair<long long, long long> weight = vertexq.top();
		vertexq.pop();
		long long dis = weight.first;
		long long ver = weight.second;
		
		if (is[ver])
			continue;
			
		is[ver] = true;
		res += dis;
		for (long long i = 0; i < graph[ver].size(); i++) 
		{
			long long tov = graph[ver][i].first;
			long long tod = graph[ver][i].second;
			if (!is[tov])
				vertexq.push(make_pair(tod, tov));
		}
	}
	return res;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
  
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
     
	int n, m;
	cin >> n >> m;
	is.resize(n, false);
	
	for (int i = 0; i < m; i++) 
	{
		int b, e, w;
		cin >> b >> e >> w;
		graph[b - 1].push_back(make_pair(e - 1, w));
		graph[e - 1].push_back(make_pair(b - 1, w));
	}
	cout << prim();
	return 0;
}