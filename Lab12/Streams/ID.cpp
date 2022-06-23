#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, capacity, flow;
};

vector < vector <int> > graph;
vector <Edge> edges;
vector <int> ptr;
vector <int> level;
const int INF = 999999999;
int n, m, source = 0, sink = 0;
vector < vector <int> > answer;

bool bfs() {
    level.assign(n, 0);
    queue <int> q;
    q.push(source);
    level[source] = 1;
    while (!q.empty() && !level[sink])
    {
        int from = q.front();
        q.pop();
        for (auto edge : graph[from])
        {
            if (!level[edges[edge].to] && edges[edge].capacity > edges[edge].flow)
            {
                q.push(edges[edge].to);
                level[edges[edge].to] = level[from] + 1;
            }
        }
    }
    return level[sink];
}

int dfs(int v = source, int flow = INF) {
    if (!flow)
        return 0;
    if (v == sink)
        return flow;
    while (ptr[v] < graph[v].size())
    {
        int edge = graph[v][ptr[v]];
        if (level[v] + 1 == level[edges[edge].to])
        {
            int pushed = dfs(edges[edge].to, min(flow, edges[edge].capacity - edges[edge].flow));
            if (pushed)
            {
                edges[edge].flow += pushed;
                edges[edge ^ 1].flow -= pushed;
                return pushed;
            }
        }
        ptr[v]++;
    }
    return 0;
}

void in(int from, int to, int capacity) {
    graph[from].push_back(edges.size());
    edges.emplace_back(Edge{ from, to, capacity, 0});
    graph[to].push_back(edges.size());
    edges.emplace_back(Edge{ to, from, 0, 0 });
}

int main() {

    cin >> n >> m; n += 2;
    graph.resize(n);
    ptr.resize(n, 0);
    sink = n - 1;

    for (int i = 0; i < m; i++)
    {
        int from, to, low, high;
        cin >> from >> to >> low >> high;
        in(source, to, low);
        in(from, to, high - low);
        in(from, sink, low);
    }

    while (bfs())
    {
        while (dfs());
        ptr.assign(n, 0);
    }

    for (int edge : graph[0])
        if (edges[edge].flow < edges[edge].capacity)
        {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";
    for (int i = 0; i < edges.size(); i += 6)
        cout << edges[i + 2].flow + edges[i + 4].flow << endl;

    return 0;
}
/*Каждое ребро изначального графа заменяется на три новых.
 * Если по ребру ei=(vfrom,vto) в исходной сети протекает поток li⩽fi⩽ci,
 * то в новой сети по ребру (s,vto) должен течь поток, равный li, то есть его пропускной способности.
 * Поток, который вытекает из vfrom по ребру в G, заменяется на поток, который протекает по рёбрам (vfrom,vto) и (vfrom,t)
 * (поскольку сумма их пропускных способностей в полученном графе равна ci). Аналогично, для вершины vto суммарный входящий поток не изменился.
 * Таким образом, любой допустимый поток по любому ребру в изначальном графе можно распределить между тремя рёбрами в полученном графе.
 * Заметим, что в сети G′ все li=0, то есть мы имеем обыкновенную сеть.*/