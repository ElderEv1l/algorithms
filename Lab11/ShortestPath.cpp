#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

long long INF = 999999999999999;
int n, s, f;
vector < vector < long long > > graph;
vector<long long> dist;
vector <bool> used;

void dijkstra ()
{
    dist[s - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if (dist[v] == INF)
            break;
        used[v] = true;

        for (int j = 0; j < n; j++)
            dist[j] = min(dist[j], dist[v] + graph[v][j]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
    cin >> n >> s >> f;
    graph.resize(n, vector <long long>(n, INF));
    dist.resize(n, INF);
    used.resize(n, false);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] < 0)
                graph[i][j] = INF;
        }
    }


    dijkstra();

    if (dist[f - 1] != INF)
        cout << dist[f - 1];
    else
        cout << "-1";

    return 0;
}