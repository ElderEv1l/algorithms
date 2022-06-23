#include <iostream>
#include <vector>

using namespace std;

vector < vector <int> > d;

void up(int i, int j){
    d[i][j] += d[i - 2][j - 1] + d[i - 2][j + 1] + d[i - 1][j - 2] + d[i + 1][j - 2];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    n += 2;
    m += 2;

    d.resize(n + 1, vector <int> (m + 1, 0));
    d[2][2] = 1;
    int i = 2, j = 2;

    while(i != n-1 || j != m-1)
    {
        int x = i, y = j;
        while(x >= 2 && y < m)
            up(x--, y++);

        if(i == n - 1)
            j++;
        else i++;
    }
    up(n-1, m-1);

    cout << d[n-1][m-1];

    return 0;
}