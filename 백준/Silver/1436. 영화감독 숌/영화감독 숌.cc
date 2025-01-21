
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

	// 종말의 수란 어떤수에 6이 적어도 3개이상 연속으로 들어가는 수 
	// 제일 작은건 666 그다음은 1666 , 그다음은 2666... n번째 영화는 n번째로 작은거
	// 2번째면 1666일거고 666,1666이니 2번째로 작은거지

	int n, count = 0;

	cin >> n;

	for (int i = 666; ; i++)
	{
		int tmp = i;

		while (tmp >= 666)
		{
			if (tmp % 1000 == 666)
			{
				count++;
				break;
			}
			tmp /= 10;     
		}

		if (n == count)
		{
			cout << i;
			break;
		}
	}

	
	return 0;
}


