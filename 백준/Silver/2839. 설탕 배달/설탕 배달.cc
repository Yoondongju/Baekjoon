
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#pragma warning(disable:4996)

typedef unsigned int uint;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 3, 5 로 나눠야함

	int n;
	int iCount = 0;
	cin >> n; 


	while (1)
	{
		if (0 == n % 5)
		{
			iCount += (n / 5);
			cout << iCount;
			break;
		}
		else
		{
			n -= 3;
			if(n >= 0)
				iCount++;			
			else
			{
				cout << -1;
				break;
			}		
		}
	}

	




	return 0;
}


