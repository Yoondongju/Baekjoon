
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





int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//  1
	//  2
	//  3
	// .. 
	//  n

	queue<int> QueueTest;


	int n;
	cin >> n;


	for (size_t i = 0; i < n; i++)
	{
		QueueTest.push(i + 1);
	}

	int i = 0;

	while(1 < QueueTest.size())
	{	
		if (0 == i % 2)  // 걍 버린다
		{
			QueueTest.pop();
		}
		else
		{
			QueueTest.push(QueueTest.front());
			QueueTest.pop();
		}

		i++;
	}

	cout << QueueTest.back();


	return 0;
}


