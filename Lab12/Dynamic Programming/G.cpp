#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    int s, n;
    cin >> s >> n;

    vector <int> w(n);

    for (int i = 0; i < n; i++)
        cin >> w[i];

    int a[n + 1][s + 1];

    for (int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            if(i == 0 || j == 0)
                a[i][j] = 0;
            else
                if(j < w[i - 1])
                    a[i][j] = a[i - 1][j];
                else
                    a[i][j] = max(a[i - 1][j], w[i - 1] + a[i - 1][j - w[i - 1]]);
        }
    }

    cout << a[n][s];
    return 0;
}