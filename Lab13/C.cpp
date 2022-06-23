#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    string s;
    cin >> s;

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

    for(int i = 0; i < pref.size(); i++)
        cout << pref[i] << ' ';
    return 0;
}
