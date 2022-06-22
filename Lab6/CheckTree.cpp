#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int tree[200000][3];

bool check(int i, int min, int max) 
{
    int k = tree[i][0];

    if (k < min || k > max)
        return false;

    if (tree[i][1])
    {
        if (k <= tree[tree[i][1]][0])
            return false;

        if (!check(tree[i][1], min, k - 1))
            return false;
    }

    if (tree[i][2])
    {
        if (k >= tree[tree[i][2]][0])
            return false;
        if (!check(tree[i][2], k + 1, max))
            return false;
    }

    return true;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);

    int n, k, r, l;
    cin >> n;

    if (n == 0)
    {
        cout << "YES\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> k >> l >> r;
        tree[i][0] = k;

        if (left)
            tree[i][1] = l;

        if (right)
            tree[i][2] = r;
    }

    
    if (check(1, -1000000001, 1000000001))
        cout << "YES\n";
    else cout << "NO\n";

    return 0;
}