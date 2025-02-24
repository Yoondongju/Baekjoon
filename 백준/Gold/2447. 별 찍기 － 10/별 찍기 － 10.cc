#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#pragma warning(disable:4996)

typedef unsigned int uint;


void Recursive(int i, int j, int num)
{
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1)
	{
		cout << " ";
	}
	else
	{
		if (num / 3 == 0)
		{
			cout << "*";
		}
		else
			Recursive(i, j, num / 3);

	}
}



int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n = 0;
	cin >> n;


 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			Recursive(i, j, n);
		cout << '\n';
	}




	return 0;
}


