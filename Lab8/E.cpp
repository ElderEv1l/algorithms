#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int dis[1000000];
vector < vector <int> > graph;

void bfs() 
{
    dis[1] = 1;
    queue<int> ququ;
    ququ.push(1);
    
    while(!ququ.empty()) 
    {
        int now = ququ.front();
        ququ.pop();
        
        for(int i = 0; i < graph[now].size(); i++) 
        {
            int to = graph[now][i];
            
            if(dis[to] == 0) 
            {
                dis[to] = dis[now] + 1;
                ququ.push(to);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) 
    {
        int b, e;
        cin >> b >> e;
        graph[b].push_back(e);
        graph[e].push_back(b);
    }
    
    bfs();
    
    for(int i = 1; i <= n; i++)
        cout << dis[i] - 1 << ' ';
    return 0;
}