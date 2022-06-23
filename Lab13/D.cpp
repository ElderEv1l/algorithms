#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    //freopen("prefix.in", "r", stdin);
    //freopen("prefix.out", "w", stdout);

    int power;
    string s;
    cin  >> power >> s;

    s += '#';

    int n = s.size();
    vector <int> pref(n);
    for(int i = 1; i < n; i++)
    {
        int j = pref[i - 1];

        while(j > 0 && s[i] != s[j])
            j = pref[j - 1];

        if(s[i] == s[j])
            j++;

        pref[i] = j;
    }

    vector < vector <int> > ans(s.size(), vector <int>(power));
    for(int i = 0; i < s.size(); i++)
    {
        for(char c = 'a'; c < 'a' + power; c++)
        {
            if(i > 0 && c != s[i])
                ans[i][c - 'a'] = ans[pref[i - 1]][c - 'a'];
            else
                ans[i][c - 'a'] = i + (c == s[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
