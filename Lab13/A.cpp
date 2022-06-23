#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);

    string p, t;
    cin >> p >> t;

    int n = t.size();
    int m = p.size();
    vector <int> ans;

    for(int i = 0; i <= n - m; i++)
    {
        bool check = true;
        for(int j = 0; j < m; j++)
            if(p[j] != t[i + j])
                check = false;

        if(check)
            ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}
