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


bool Compare(const vector<int>& vecCables, uint mid, int iN)
{
	uint iResult(0);
	for (size_t cable : vecCables)
	{
		iResult += cable / mid;
	}

	return iResult >= iN;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int iK, iN;

	cin >> iK >> iN;
	vector<int>  vecCables(iK);


	for (size_t i = 0; i < iK; i++)
	{
		cin >> vecCables[i];
	}

	uint  left = 1, right = *max_element(vecCables.begin(), vecCables.end());

	int iResult(0);

	uint  mid = (left + right) / 2;
	while (left <= right)
	{
		mid = (left + right) / 2;
	
		if (Compare(vecCables, mid, iN))
		{
			iResult = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << iResult;
	

	return 0;
}