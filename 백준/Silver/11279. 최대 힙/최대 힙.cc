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
	// 자료구조 Heap이란 ?
	// 데이터에서 최댓값과 최솟값을 빠르게 찾기 위해 고안된 완전 이진 트리

	// 최솟값이나 최댓값을 찾기 위해 배열을 사용하면 Ο(n)만큼 시간이 걸린다.
	// 하지만 힙을 사용하면 O(logn)만큼 소요되므로, 배열을 사용할 때보다 빠르게 최솟값과 최댓값을 구할 수 있다.
	// 우선순위 큐와 같이 최댓값 또는 최솟값을 빠르게 찾아야하는 알고리즘 등에 활용된다.


	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	priority_queue<int>  Priority_Queue;
	int n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		int iInput = 0;
		cin >> iInput;

		if (0 == iInput)
		{
			if (Priority_Queue.empty())  // 큐가 비어 있으면
				cout << "0" << '\n';  // 0 출력
			else
			{
				cout << Priority_Queue.top() << '\n';  // 큐에서 가장 큰 값 출력
				Priority_Queue.pop();  // 가장 큰 값 pop
			}
		}
		else
		{
			Priority_Queue.push(iInput);
		}
	}





	return 0;
}


