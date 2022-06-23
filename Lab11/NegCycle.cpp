#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long long INF = 999999999999999999;
int n, m;
int k=0;
vector < vector <int> > graph;
vector <long long> dist;
vector < pair < int, pair < int, int > > > edges;


stack <int> path;

int relax(int v1, int v2, long long w, vector<int> &parent) {
    if (dist[v1] + w < dist[v2])
    {
        dist[v2] = max(-INF, dist[v1] + w);
        parent[v2] = v1;
        return v2;
    }
    return -1;
}

void ford() {
    vector <int> parent(n, -1);
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        prev = -1;
        for (auto edge : edges)
            prev = max(prev, relax(edge.second.first, edge.second.second, edge.first, parent));
    }

    if (prev != -1)
    {
        for (int i = 0; i < n; i++)
            prev = parent[prev];

        path.push(prev);
        int v = parent[prev];
        while (v != prev)
        {
            path.push(v);
            v=parent[v];
        }
        path.push(v);
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
    cin >> n;
    graph.resize(n);
    dist.resize(n, INF);


    int w;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w;
            if(w != 1000000000)
                edges.emplace_back(w, make_pair(i, j));
        }
    }

    ford();

    int ss = path.size();
    if (ss != 0)
    {
        cout << "YES" << endl;
        cout << ss << endl;
        for (int i = 0; i < ss; i++)
        {
            cout << path.top() + 1 << " ";
            path.pop();
        }
    }
    else
        cout << "NO";
    return 0;
}