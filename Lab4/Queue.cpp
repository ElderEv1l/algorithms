#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);

    int n, first, last;
    cin >> n;
    first = 0; last = 0;

    int* queue = new int[n];

    char command;
    for (int i = 0; i < n; ++i)
    {
        cin >> command;
        switch (command)
        {
            case '+':
            {
                cin >> queue[last];
                last++;
                break;
            }

            case '-':
            {
                cout << queue[first] << endl;
                first++;
                break;
            }

            default:
                break;
        }
    }
    return 0;
}