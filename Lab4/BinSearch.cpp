#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);


    int n, m, temp;
    int le, ri;
    int lt, rt;
    cin >> n;
    int l, r, mid;
    vector <int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];


    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        lt = 0; rt = n - 1;
        while (lt < rt)
        {
            mid = (lt + rt) / 2;

            if (temp > v[mid])
                lt = mid + 1;
            if (temp < v[mid])
                rt = mid - 1;
            if (temp == v[mid])
                rt = mid;
        }
        if (v[lt] == temp) le = lt;
        else le = -2;

        if (le != -2)
        {
            l = le; r = n - 1;
            while (l < r)
            {
                mid = (l + r) / 2 + 1;

                if (temp > v[mid])
                    l = mid + 1;
                if (temp < v[mid])
                    r = mid - 1;
                if (temp == v[mid])
                    l = mid;
            }
            ri = r;
        }
        else ri = -2;

        cout << le + 1 << " ";
        cout << ri + 1 << "\n";
    }
    return 0;
}