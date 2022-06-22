#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio (false); cin.tie(NULL);

    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    stack <char> s;
    char temp;
    string str;
    int k = 0;
    while (cin >> str)
    {
       
        for (int i = 0; i < str.size(); i++)
            switch (str[i])
            {
                case '(':
                {
                    s.push(str[i]);
                    break;
                }

                case ')':
                {
                    if (!s.empty())
                    {
                        if (s.top() == '(') s.pop();
                        else s.push(str[i]);
                    }
                    else s.push(str[i]);
                    break;
                }

                case '[':
                {
                    s.push(str[i]);
                    break;
                }

                case ']':
                {
                    if (!s.empty())
                    {
                        if (s.top() == '[') s.pop();
                        else s.push(str[i]);
                    }
                    else s.push(str[i]);
                    break;
                }
            }

        if (s.empty() == true) cout << "YES\n";
        else
        {
            cout << "NO\n";
            while (!s.empty()) s.pop();
        }
    }
    return 0;
}