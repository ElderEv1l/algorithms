#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);

    int n;
    cin >> n;

    vector <int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n / 2; i++)
    {
        if ((2 * i <= n) && (v[i] > v[2 * i]))
        {
            v[0] = 1;
            break;
        }
       
        if ((2 * i + 1 <= n) && (v[i] > v[2 * i + 1]))
        {
            v[0] = 1;
            break;
        }
    }


    if (v[0] == 1) cout << "NO";
        else cout << "YES";

    return 0;
}
