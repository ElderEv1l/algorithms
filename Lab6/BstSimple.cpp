#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct Tree 
{
    int key;
    Tree* l;
    Tree* r;
};

Tree* insert(Tree*& t, int a) 
{
    if (t == NULL)
    {
        t = new Tree;
        t->key = a;
        t->l = t->r = NULL;
    }
    else
    {
        if (t->key > a)
            insert(t->l, a);
        if (t->key < a)
            insert(t->r, a);
    }
    return t;
}

Tree* min(Tree*& t)
{
    if (t->l == NULL)
        return t;
    return min(t->l);
}

Tree* max(Tree*& t)
{
    if (t->r == NULL)
        return t;
    return max(t->l);
}

Tree* del(Tree*& t, int x) 
{
    if (t == NULL)
        return 0;

    if (x < t->key)
        t->l = del(t->l, x);
    else if (x > t->key)
        t->r = del(t->r, x);
    else if (t->l != NULL && t->r != NULL) 
    {
        t->key = min(t->r)->key;
        t->r = del(t->r, t->key);
    }
    else 
    {
        if (t->l != NULL)
            t = t->l;
        else
            t = t->r;
    }
    return t;
}

bool exists(Tree* t, int x)
{
    if (t == NULL)
        return false;

    if (t->key == x)
        return true;

    if (x < t->key)
        return exists(t->l, x);
    if (x > t->key)
        return exists(t->r, x);
}

Tree* next(Tree*& t, int x)
{
    Tree* now = t;
    Tree* next = NULL;

    while (now != NULL)
    {
        if (now->key > x)
        {
            next = now;
            now = now->l;
        }
        else
            now = now->r;
    }
    return next;
}

Tree* prev(Tree*& t, int x)
{
    Tree* now = t;
    Tree* prev = NULL;
    while (now != NULL)
    {
        if (now->key < x)
        {
            prev = now;
            now = now->r;
        }
        else
            now = now->l;
    }
    return prev;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);

    Tree* tree = NULL;

    string c;
    while (cin >> c)
    {
        int x;
        cin >> x;

        if (c == "insert")
            insert(tree, x);

        if (c == "delete")
            del(tree, x);

        if (c == "exists")
        {
            if (exists(tree, x))
                cout << "true\n";
            else
                cout << "false\n";
        }

        if (c == "next") 
        {
            Tree* t = next(tree, x);

            if (t == NULL)
                cout << "none\n";
            else
                cout << t->key << "\n";
        }

        if (c == "prev")
        {
            Tree* temp = prev(tree, x);

            if (temp == NULL)
                cout << "none\n";
            else
                cout << temp->key << "\n";
        }
    }
}