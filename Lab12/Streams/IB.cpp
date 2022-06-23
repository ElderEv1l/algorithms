#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
vector <int> match;
vector < vector <int> > g;
vector <bool> used;

bool dfs(int v)
{
    if (used[v])
        return false;

    used[v] = true;
    for (auto to : g[v])
        if (match[to] == -1 || dfs((match[to])))
        {
            match[to] = v;
            return true;
        }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);

    cin >> n >> m >> k;
    match.assign(m, -1);
    g.resize(n);
    used.resize(n, false);

    int from, to, maxx = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> from >> to;
        g[from - 1].push_back(to - 1);
    }

    for(int i = 0; i < n; i++)
    {
        used.assign(m, false);
        if(dfs(i))
            maxx++;
    }

    cout << maxx;
    return 0;
}

/*Алгоритм можно описать так: сначала возьмём пустое паросочетание,
 * а потом — пока в графе удаётся найти увеличивающую цепь,
 * — будем выполнять чередование паросочетания вдоль этой цепи, и
 * повторять процесс поиска увеличивающей цепи.
 * Как только такую цепь найти не удалось — процесс останавливаем,
 * — текущее паросочетание и есть максимальное.
 */