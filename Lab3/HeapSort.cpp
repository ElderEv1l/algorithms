#include <iostream>
#include <vector>
using namespace std;

void siftdown(vector <int>& v, int n, int i)
{
    int l, r, t;
    while (2 * i + 1 < n)
    {
        l = 2 * i + 1;
        r = 2 * i + 2;
        t = l;
        if ((r < n) && (v[l] > v[r]))
            t = r;

        if (v[i] <= v[t])
            break;

        swap(v[i], v[t]);
        i = t;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int n;
    cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = n / 2; i >= 0; i--)
        siftdown(v, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        siftdown(v, i, 0);
    }

    for (int i = n - 1; i >= 0; i--)
        cout << v[i] << " ";

    return 0;
}
