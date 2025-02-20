#include <iostream>
#include <algorithm>
using namespace std;





int main()
{
	int n, m;
	int iMax(0);
	cin >> n >> m;

	int* iArr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> iArr[i];
	}

	for (int i = 0; i < n-2; ++i)
	{
		for (int j = i + 1; j < n-1; ++j)
		{
			for (int k = j+1; k < n; ++k)
			{
				if (m >= iArr[i] + iArr[j] + iArr[k] 
					&& iMax < iArr[i] + iArr[j] + iArr[k])
				{
					iMax = iArr[i] + iArr[j] + iArr[k];
				}
			}
		}
	}

	cout << iMax << endl;
    return 0;
}