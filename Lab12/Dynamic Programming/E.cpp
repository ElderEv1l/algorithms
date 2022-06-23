#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans, root;
vector < vector <int> > g;
vector <int> d;

int get_independent_set (int v)
{
    if (d[v])
        return d[v];

    int first = 0, second = 1;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        first += get_independent_set(to);
        for (int j = 0; j < g[to].size(); ++j)
            second += get_independent_set(g[to][j]);
    }
    return d[v] = max(first, second);
}

int main()
{
    cin >> n;
    g.resize(n + 1);
    d.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        if (a)
            g[a].push_back(i);
        else
            root = i;
    }

    ans = get_independent_set(root);
    cout << ans << '\n';
    return 0;
}