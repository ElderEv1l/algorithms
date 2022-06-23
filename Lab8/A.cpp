#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
	int a, b;
	bool table[100][100]={0};
	
	cin >> n >> m; 
	
	for (int i = 0; i < m; i++) 
	{
		cin >> a >> b;
		table[a - 1][b - 1] = 1;
	}
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
			cout << table[i][j] << ' ';
		cout << endl;
	}
	return 0;
}