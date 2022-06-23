#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
	bool table[100][100];
	cin >> n;
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
			cin >> table[i][j];
	}
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (table[i][j] != table[j][i]) 
			{
				cout << "NO" << endl;
				return 0;
			}
			
			if (i == j && table[i][j]) 
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	cout << "YES" << endl;
	return 0;
}