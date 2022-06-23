#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;


int INF = 999999999;
int n, m;
vector < vector < int > > graph;

void floyd()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);

    cin >> n >> m;
    graph.assign(n, vector <int> (n, INF));

    int b, e, weight;
    for (int i = 0; i < m; i++)
    {
        cin >> b >> e >> weight;
        graph[b - 1][e - 1] = weight;
    }

    floyd();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}