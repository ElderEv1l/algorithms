#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector < vector <int> > capacity;
vector < vector <int> > g;
vector <bool> used;

int dfs(int v, int f)
{
    if (v == n - 1)
        return f;

    used[v] = true;
    for (int i = 0; i < n; ++i)
        if (!used[i] && capacity[v][i] > 0)
        {
            int t = dfs(i, min(f, capacity[v][i]));
            if (t > 0)
            {
                capacity[v][i] -= t;
                capacity[i][v] += t;
                return t;
            }
        }
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    capacity.assign(n, vector <int> (n, 0));
    g.resize(n);
    used.resize(n, false);

    int from, to, flow;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> flow;
        capacity[from - 1][to - 1] = flow;
        g[from - 1].push_back(to);
    }

    int max = 0, delta = 0;

    do {
        used.assign(n, false);
        delta = dfs(0, 9999999);
        max += delta;
    } while (delta > 0);
    
    cout << max << endl;
    return 0;
}