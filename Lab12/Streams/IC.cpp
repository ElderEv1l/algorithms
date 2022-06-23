#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int to, capacity, flow, number;
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

int decomposition(int v, int minFlow = INF) {
    if (v == sink)
    {
        answer.emplace_back();
        return minFlow;
    }

    for (int edge : graph[v])
    {
        if (edges[edge].flow > 0)
        {
            int result = decomposition(edges[edge].to, min(minFlow, edges[edge].flow));
            if (result)
            {
                answer.back().push_back(edges[edge].number);
                if (v == source)
                {
                    answer.back().push_back(answer[answer.size() - 1].size());
                    answer.back().push_back(result);
                    reverse(answer.back().begin(), answer.back().end());
                }
                edges[edge].flow -= result;
                return result;
            }
        }
    }
    return 0;
}

int main() {

    cin >> n >> m;
    graph.resize(n);
    ptr.resize(n, 0);
    sink = n - 1;

    for (int i = 0; i < m; i++)
    {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        graph[from - 1].push_back(edges.size());
        edges.emplace_back(Edge{to - 1, capacity, 0, i + 1});
        graph[to - 1].push_back(edges.size());
        edges.emplace_back(Edge{from - 1, 0, 0, i + 1});
    }

    while (bfs())
    {
        while (dfs());
        ptr.assign(n, 0);
    }

    while(decomposition(source));

    cout << answer.size() << '\n';
    for (auto i : answer)
    {
        for (int j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}

/*Пусть source — исток, sink — сток сети G.
 * Пойдем по ребру, попадем в вершину v1.
 * Если v1 совпадает с t, то найденный путь является путем из source в sink,
 * иначе по закону сохранения потока для вершины v1 из неё должно выходить хотя бы одно ребро в некоторую вершину v2.
 * Будем продолжать этот процесс до тех пор, пока vi не совпадет с sink (найден путь pi из source в sink)
 * либо с одной из ранее посещенных вершин (найден цикл kj).
 * Данный путь (цикл) будет иметь положительный поток f(pi) или f(kj),
 * равный минимальному среди потоков по всем рёбрам пути (цикла). */
