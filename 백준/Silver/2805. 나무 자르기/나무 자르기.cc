
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
	
	int iN, iM;
	cin >> iN >>  iM;

	vector<int> iNumTree(iN);

	for (size_t i = 0; i < iN; i++)
	{
		cin >> iNumTree[i];
	}

	long long int iResult(0);
	uint iCountAcc(0);

	uint iLeft(0);
	uint iRight = *max_element(iNumTree.begin(), iNumTree.end());

	uint iMid(0);

	
	while (iLeft <= iRight)
	{
		iMid = (iLeft + iRight) / 2;
		iResult = 0;
	

		for (size_t i = 0; i < iNumTree.size(); i++)
		{
			if (iNumTree[i] < iMid)
				continue;
			else
			{
				iResult += iNumTree[i] - iMid;
			}
		}


		if (iResult < iM)    // 내가 가져갈 길이보다 더 작게나왔으면 Mid가 더 작아야해
		{
			iRight = iMid - 1;
		}
		else  // 내가 가져갈 길이보다 크게 나왓어 그럼 Mid가 더 커야대
		{
			iCountAcc = iMid;
			iLeft = iMid + 1;
		}

	}

	cout << iCountAcc;

	// ? 가 나무길이보다 클때만 두개의 차이
	// 누적시킨게 7 일때 최대값 찾기

	return 0;
}