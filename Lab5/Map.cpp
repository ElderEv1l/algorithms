#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);

    vector <vector<pair<string, string>>> h(1000);
    string s, key, value;
    int n, t, ti;
    bool check;

    while (cin >> s)
    {
        check = false;
        cin >> key;
        n = 0;
        for (int i = key.length() - 1; i >= 0; i--)
            n += ((int)(key[i])) * i;
        t = n % 1000;

        for (int i = 0; i < h[t].size(); i++)
        {
            if (h[t][i].first == key)
            {
                check = true;
                ti = i;
                break;
            }
        }

        if (s == "put")
        {
            cin >> value;
            if (check)
                h[t][ti].second = value;
            else
                h[t].push_back(make_pair(key, value));
        }

        if (check && s == "delete")
            h[t].erase(h[t].begin() + ti);

        if (s == "get")
        {
            if (check)
                cout << h[t][ti].second << '\n';
            else
                cout << "none\n";
        }
    }
    return 0;
}

