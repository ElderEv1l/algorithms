#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    stack <int> s;
    char temp;
    int x1,x2;

    while (cin>>temp)
    {
        switch (temp)
        {
            case '+':
            {
                x1 = s.top();
                s.pop();
                x2 = s.top();
                s.pop();

                x1 += x2;
                s.push(x1);
                break;
            }

            case '-':
            {
                x1 = s.top();
                s.pop();
                x2 = s.top();
                s.pop();

                x2 -= x1;
                s.push(x2);
                break;
            }

            case '*':
            {
                x1 = s.top();
                s.pop();
                x2 = s.top();
                s.pop();

                x1 *= x2;
                s.push(x1);
                break;
            }

            default:
            {
                x1 = temp - '0';
                s.push(x1);
                break;
            }
        }
    }
    cout << s.top();
    return 0;
}