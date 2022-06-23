#include <iostream>
#include <vector>

using namespace std;

vector<int> z_func(string s){
    vector<int> z(s.size());
    int left = 0;
    int right = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (i <= right)
            z[i] = min(right - i + 1, z[i - left]);

        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > right)
        {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);

    string p, t;
    cin >> p >> t;

    int n = t.size();
    int m = p.size();
    vector <int> ans;

    vector<int> z = z_func(p + '#' + t);

    for(int i = m; i < z.size(); i++)
        if(z[i] == m)
            ans.push_back(i - m);

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}
