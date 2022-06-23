#include <iostream>
#include <vector>
using namespace std;
const long long INF = 999999999999999999;
int n, m;
vector < vector <int> > graph;
vector <long long> dist;
vector < pair < long long, pair < int, int > > > edges;
vector <int> parent;
vector <bool> used;

int relax(int v1, int v2, long long w) {
    if (dist[v1] + w < dist[v2]){
        dist[v2] = max(-INF, dist[v1] + w);
        parent[v2] = v1;
        return v2;
    }
    return -1;
}

void dfs(int v) {
    used[v] = true;
    for (int i : graph[v])
        if (!used[i])
            dfs(i);
}

void ford(int s) {
    dist[s] = 0;
    int prev = -1;
    for (int i = 0; i < n; i++){
        prev = -1;
        for (auto edge : edges)
        {
            if(dist[edge.second.first] < INF)
                prev = max(prev, relax(edge.second.first, edge.second.second, edge.first));
        }
    }

    if (prev != -1)
    {
        for (int i = 0; i < n; ++i)
            prev = parent[prev];

        dfs(prev);

        for (int i = 0; i < n; ++i)
            if (used[i])
                dist[i] = -INF;
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int s;
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    cin >> n >> m >> s;
    graph.resize(n);
    dist.resize(n, INF);
    parent.resize(n, -1);
    used.resize(n);

    int v1, v2;
    long long w;

    for (int i = 0; i < m; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1 - 1].push_back(v2 - 1);
        edges.emplace_back(w, make_pair(v1 - 1, v2 - 1)); //как push_back, но сам создает пару
    }

    ford(s-1);

    for (auto res : dist)
    {
        switch (res)
        {
            case INF: {
                cout << "*";
                break;
            }

            case -INF: {
                cout << "-";
                break;
            }

            default:
                cout << res;
                break;
        }
        cout << '\n';
    }
    return 0;
}