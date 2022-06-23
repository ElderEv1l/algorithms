#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int INF = 9999999;
int n, m;

vector < vector < pair <int, int> > > graph;
vector <int> dist;


void dijkstra()
{
    dist[0] = 0;
    set < pair <int, int> > s;
    s.insert(make_pair(dist[0], 0));

    while (!s.empty())
    {
        int v = s.begin()->second;
        s.erase(s.begin());

        for (int i = 0; i < graph[v].size(); i++)
        {
            int to = graph[v][i].first;
            int dnow = graph[v][i].second;
            if (dist[v] + dnow < dist[to])
            {
                dist[to] = dist[v] + dnow;
                s.erase({dist[v], v});
                s.insert({dist[to], to});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);
    cin >> n >> m;
    graph.resize(INF);
    dist.resize(n, INF);


    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1-1].push_back({v2-1,w});
        graph[v2-1].push_back({v1-1,w});
    }

    dijkstra();

    for (int i = 0; i < n; i++)
        cout << dist[i] << ' ';

    return 0;
}