#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);

    int n, last;
    cin >> n;
    last = 0;

    int* stack = new int[n];

    char command;
    for (int i = 0; i < n; ++i)
    {
        cin >> command;
        switch (command)
        {
            case '+':
            {
                cin >> stack[last];
                last++;
                break;
            }

            case '-':
            {
                last--;
                cout << stack[last] << endl;
                break;
            }

            default:
                break;
        }
    }
    return 0;
}