#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int tree[200000][3];
int m = 0;
void height(int nu, int h)
{
    if (m < h)
        m = h;

    if (tree[nu][1] > 0)
        height(tree[nu][1], h + 1);

    if (tree[nu][2] > 0)
        height(tree[nu][2], h + 1);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
        cin >> tree[i][0] >> tree[i][1] >> tree[i][2];

    height(1, 1);
    cout << m << "\n";

    return 0;
}