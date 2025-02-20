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


long long Fac(int n)
{
	if (1 == n || 0 == n)
		return 1;
	else
		return n * Fac(n - 1);
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	int n = 0;
	cin >> n;

	cout << Fac(n) << "\n";


	return 0;
}


