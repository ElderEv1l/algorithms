#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector <string> v(n);
    vector <string> t(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

        for (int i = m - 1; i > m - 1 - k; i--)
        {
            int c[26];
            vector <string> t(n);

            for (int j = 0; j < 26; j++)
                c[j] = 0;

            for (int j = 0; j < n; j++)
                c[v[j][i] - 'a']++;

            int count = 0;

            for (int j = 0; j < 26; j++)
            {
                int tmp = c[j];
                c[j] = count;
                count += tmp;
            }

            for (int j = 0; j < n; j++)
            {
                t[ c[v[j][i] - 'a'] ] = v[j];
                c[v[j][i] - 'a']++;
            }
            v = t;
        }

    for (int i = 0; i < n; i++)
        cout << v[i] << endl;

    return 0;
}