#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
  
struct cords {
    int x;
    int y;
};

int n;
vector <vector <int>> graph;
vector <cords> points;
vector <bool> used;
vector <double> distans;

int d(cords a, cords b) 
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void prim() 
{
    distans[0] = 0;
	for (int i = 0; i < n; i++) 
	{
		int next = -1;
		for (int j = 0; j < n; j++)
			if (!used[j] && (next == -1 || distans[j] < distans[next]))
				next = j;
		
		used[next] = true;
		
		for (int j = 0; j < n; j++) 
			if (!used[j] && graph[next][j] < distans[j])
				distans[j] = graph[next][j];
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
  
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
     
    cin >> n;
    graph.assign(n, vector<int>(n));
    points.resize(n);
    used.resize(n, false);
    distans.resize(n, 999999999);
	
	for (int i = 0; i < n; i++)
		cin >> points[i].x >> points[i].y;
    for (int i = 0; i < n; i++)	
		for (int j = 0; j < n; j++)
			graph[i][j] = d(points[i], points[j]);
			
	prim();
	double res = 0;
	for (int i = 0; i < n; i++)
		res += sqrt(distans[i]);
	cout.precision(10);
	cout << res;
	
	return 0;
}