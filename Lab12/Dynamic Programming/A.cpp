#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >>a[i];

    vector <int> d(n, 1);
    vector <int> p(n,-1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && d[j] + 1 > d[i])
            {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int now = 0, max = 0;
    for (int i = 0; i < n; ++i)
        if (d[i] > max)
        {
            max = d[i];
            now = i;
        }

    cout << max << endl;

    vector<int> ans;
    while (now != -1)
    {
        ans.push_back(a[now]);
        now = p[now];
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';

    return 0;
}