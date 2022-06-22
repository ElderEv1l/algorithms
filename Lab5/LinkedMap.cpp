#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct meow
{
    string key;
    string value;
    meow* next = nullptr;
    meow* prev = nullptr;
};

int nhash(string value)
{
    int p = 3, pow = 1;
    int h = 1;
    for (char i : value)
    {
        h += (53 * h + i);
        h %= 100003;
    }
    return h;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);

    vector <vector<meow>> lmap(100005);
    string s, key, value;

    meow* prev = nullptr;
    while (cin >> s)
    {
        if (s == "put")
        {
            cin >> key >> value;
            int h = nhash(key);
            bool check = false;

            for (auto & i : lmap[h])
            {
                if (i.key == key)
                {
                    check = true;
                    i.value = value;
                }
            }

            if (!check)
            {
                if (lmap[h].empty())
                    lmap[h].reserve(10);
                meow t;
                t.key = key;
                t.value = value;
                t.next = nullptr;
                t.prev = prev;
                lmap[h].push_back(t);
                if (prev != nullptr)
                    prev->next = &lmap[h][lmap[h].size() - 1];
                prev = &lmap[h][lmap[h].size() - 1];
            }
        }

        if (s == "delete")
        {
            cin >> key;
            int h = nhash(key);
            for (auto & i : lmap[h])
            {
                if (i.key == key)
                {
                    if (i.next == nullptr)
                        prev = i.prev;
                    else
                        i.next->prev = i.prev;
                    if (i.prev != nullptr)
                        i.prev->next = i.next;
                    i.key = "";
                    i.value = "";
                    i.next = nullptr;
                    i.prev = nullptr;
                    break;
                }
            }
        }

        if (s == "get")
        {
            cin >> key;
            int h = nhash(key);
            bool check = false;

            for (auto & i : lmap[h])
            {
                if (i.key == key)
                {
                    cout << i.value << '\n';
                    check = true;
                }
            }
            if (!check)
                cout << "none\n";
        }

        if (s == "prev")
        {
            cin >> key;
            int h = nhash(key);
            bool check = false;

            for (auto & i : lmap[h])
            {
                if (i.key == key)
                {
                    if (i.prev != nullptr)
                    {
                        cout << i.prev->value << '\n';
                        check = true;
                    }
                }
            }
            if (!check)
                cout << "none\n";
        }

        if (s == "next")
        {
            cin >> key;
            int h = nhash(key);
            bool check = false;
            for (auto & i : lmap[h])
            {
                if (i.key == key && i.next != nullptr)
                {
                    cout << i.next->value << '\n';
                    check = true;
                }
            }
            if (!check)
                cout << "none\n";
        }
    }
    return 0;
}
