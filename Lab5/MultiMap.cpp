#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Map
{
    static const int m = 300;
    int size = 0;
    struct list
    {
        string value;
        list* next = NULL;
        list* prev = NULL;
    };

    vector<list*> v;
    static int nhash (string value)
    {
        int p = 3, pow = 1;
        int h = 0;
        for (char i : value)
        {
            h += (i - 'a' + 1) * pow;
            pow *= p;
        }
        if (h >= 0)
            return h % m;
        else
            return (m - abs(h) % m) % m;
    }

public:
    Map()
    {
        size = 0;
        v = vector<list*>(m);
    }

    list* nnew(string key)
    {
        auto node = new list;
        node->prev = NULL;
        node->value = key;
        node->next = NULL;
        return node;
    }

    list* nadd(list* tail, string key)
    {
        list* node = nnew(key);
        node->prev = tail;
        tail->next = node;
        node->value = key;
        return node;
    }

    void add(string s)
    {
        int h = nhash(s);
        list* head = v[nhash(s)];
        if (head == NULL) 
        {
            v[nhash(s)] = nnew(s);
            size++;
        }
        else
        {
            list* point = v[nhash(s)];
            while (point->next != NULL)
            {
                if (point->value == s)
                    return;
                point = point->next;
            }

            if (point->value != s)
            {
                nadd(point, s);
                size++;
            }
        }
    }

    void remove(string s)
    {
        list* point = v[nhash(s)];
        if (point == NULL)
            return;
        if (point->value == s)
        {
            v[nhash(s)] = point->next;
            size--;
            free(point);
            return;
        }

        while (point != NULL)
        {
            if (point->value == s)
            {
                if (point->prev != NULL)
                    point->prev->next = point->next;
                if (point->next != NULL)
                    point->next->prev = point->prev;
                size--;
                free(point);
                return;
            }
            point = point->next;
        }
    }

    void print()
    {
        cout << size << " ";
        for (int i = 0; i < m; ++i)
        {
            if (v[i] != NULL)
            {
                list* point = v[i];
                while (point != NULL)
                {
                    cout << point->value << " ";
                    point = point->next;
                }
            }
        }
        cout << '\n';
    }
};

struct mapn {
    mapn* prev = NULL;
    string key;
    Map values;
    mapn* next = NULL;
};

mapn* MapCreateNode(string& key, string& value) {
    auto node = new mapn;
    node->prev = NULL;
    node->key = key;
    node->values = Map();
    node->values.add(value);
    node->next = NULL;
    return node;
}

mapn* MapAddNode(mapn* tail, string& key, string& value) {
    mapn* node = MapCreateNode(key, value);
    node->prev = tail;
    tail->next = node;
    return node;
}

int nhash(string s) 
{
    int p = 50, pow = 1;
    int h = 0;
    for (char i : s) 
    {
        h += (i - 'a' + 1) * pow;
        pow *= p;
    }
    if (h >= 0)
        return h % 100000;
    else
        return (100000 - abs(h) % 100000) % 100000;
}

void put(string& key, string& value, vector<mapn*>& maaa)
{
    mapn* head = maaa[nhash(key)];
    if (head == NULL)
        maaa[nhash(key)] = MapCreateNode(key, value);
    else {
        mapn* point = maaa[nhash(key)];
        while (point->next != NULL)
        {
            if (point->key == key)
            {
                point->values.add(value);
                return;
            }
            point = point->next;
        }
        if (point->key != key)
            MapAddNode(point, key, value);
        else
            point->values.add(value);
    }
}

void del(string key, string value, vector<mapn*>& maaa)
{
    mapn* point = maaa[nhash(key)];
    while (point != NULL)
    {
        if (point->key == key)
        {
            point->values.remove(value);
            return;
        }
        point = point->next;
    }
}

void adelete(string key, vector<mapn*>& maaa)
{
    mapn* point = maaa[nhash(key)];
    if (point == NULL)
        return;
    if (point->key == key)
    {
        maaa[nhash(key)] = point->next;
        free(point);
        return;
    }
    while (point != NULL)
    {
        if (point->key == key)
        {
            if (point->prev != NULL)
                point->prev->next = point->next;
            if (point->next != NULL)
                point->next->prev = point->prev;
            free(point);
            return;
        }
        point = point->next;
    }

}

void get(string& key, vector<mapn*>& maaa)
{
    mapn* point = maaa[nhash(key)];
    while (point != NULL)
    {
        if (point->key == key)
        {
            point->values.print();
            return;
        }
        point = point->next;
    }
    cout << "0\n";
}


int main() 
{
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);

    vector<mapn*> maaa = vector<mapn*>(100000);
    string s, key, value;
    while (cin >> s)
    {
        cin >> key;
        if (s == "put") 
        {
            cin >> value;
            put(key, value, maaa);
        }

        if (s == "delete") 
        {
            cin >> value;
            del(key, value, maaa);
        }

        if (s == "deleteall")
            adelete(key, maaa);

        if (s == "get")
            get(key, maaa);
    }
    return 0;
}