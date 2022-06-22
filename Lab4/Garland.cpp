#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);

    int n;
    cin >> n;

    vector <double> v(n);
    cin >> v[0];

    double l = 0 , r = v[0];
    while (r - l > 0.00001)
    {
        v[1] = (l + r) / 2;
        bool check = true;
        for (int i = 2; i < n; i++)
        {
            v[i] = 2 * v[i - 1] - v[i - 2] + 2;
            if (v[i] < 0)
            {
                check = false;
                break;
            }
        }

        if (check)
            r = v[1];
        else l = v[1];
    }

    printf("%.2f", v[n-1]);
    return 0;
}