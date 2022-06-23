#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
  
vector<vector <int>> graph; 

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
  
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     
    int n, m;
    int b, e;
    cin >> n >> m;
    graph.resize(n);
    
    for (int i = 0; i < m; i++) 
    {
        cin >> b >> e;
        graph[b - 1].push_back(e - 1);
        graph[e - 1].push_back(b - 1);
    }
    
    for (int i = 0; i < n; i++)
        cout << graph[i].size() << ' ';

    return 0;
}