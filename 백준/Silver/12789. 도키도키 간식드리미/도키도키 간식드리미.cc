#include <iostream>
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


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	stack<int> stackCount;
	queue<int> queueCount;

	int iCurrent = 1;


	for (size_t i = 0; i < n; i++)
	{
		int iCount = 0;
		cin >> iCount;

		queueCount.push(iCount);
	}

	while (!queueCount.empty() || !stackCount.empty())
	{
		if (!queueCount.empty() && iCurrent == queueCount.front())
		{
			queueCount.pop();
			iCurrent++;
		}
		else if (!stackCount.empty() && iCurrent == stackCount.top())
		{
			stackCount.pop();
			iCurrent++;
		}
		else if (!queueCount.empty())
		{
			stackCount.push(queueCount.front());
			queueCount.pop();
		}
		else
			break;
	}




	if (stackCount.empty())
		cout << "Nice" << "\n";
	else
		cout << "Sad" << "\n";




	return 0;
}


