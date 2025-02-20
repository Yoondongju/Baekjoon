
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

using namespace std;

#pragma warning(disable:4996)

typedef unsigned int uint;


int Pibo(int n)
{
	if (n <= 2)
	{
		if (n == 0)
			return 0;
		else
			return 1;
	}	
	else
		return Pibo(n-1) + Pibo(n - 2);
	
	
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0;
	cin >> n;



	cout << Pibo(n) << endl; 


	return 0;
}


