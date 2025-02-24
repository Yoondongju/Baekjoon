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


int n,m;
int arr[8];


void Recursive(int start, int depth)
{
	if (depth == m)
	{
		for (size_t i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}



	for (size_t i = start; i<= n; i++)
	{
		arr[depth] = i;
		Recursive(i + 1, depth + 1);
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



	cin >> n >> m;
	Recursive(1, 0);  // 1부터 시작해서 숫자를 고르기 시작






	return 0;
}


