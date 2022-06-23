#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
  
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     
    bool table[100][100]={false};
    int n, m;
    int a, b;
    cin >> n >> m;
 
    for (int i = 0; i < m; i++) 
    {
        cin >> a >> b;
         
        if (table[a-1][b-1] || table[a-1][b-1])
        {
            cout << "YES" << endl;
            return 0;
        }
        table[a-1][b-1]=true;
	table[b-1][a-1]=true;
    }
    cout << "NO" << endl;
    return 0;
}