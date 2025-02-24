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


void Recursive(int n, int from, int to, int temp)
{
	if (n == 1)
	{
		cout << from << " " << to << '\n';
		return;
	}	
	else
	{
		Recursive(n - 1, from, temp, to);
		cout << from << " " << to << '\n';
		Recursive(n - 1, temp, to, from);
		
	}


}



int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n = 0;
	cin >> n;


	cout << (1 << n) - 1 << '\n';

	Recursive(n, 1, 3, 2);
	



	return 0;
}


