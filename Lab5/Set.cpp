#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);

    vector < vector < int > > h(1000);
    string s;
    int n, t, ti;
    bool check;

    while (cin >> s)
    {
        check = false;
        cin >> n;
        t = n % 1000;
        if (t < 0)
            t = -t;
      
        for (int i = 0; i < h[t].size(); i++)
        {
            if (h[t][i] == n)
            {
                check = true;
                ti = i;
                break;
            }
        }

        if (!check && s == "insert")
            h[t].push_back(n);

        if (check && s == "delete")
            h[t].erase(h[t].begin() + ti);

        if (s == "exists")
        {
            if (check)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    return 0;
}
