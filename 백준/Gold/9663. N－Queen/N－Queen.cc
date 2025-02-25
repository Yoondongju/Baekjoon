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

int n;
bool v1[30];	// 같은 열이니
bool v2[30];	// 오른쪽 상단으로 향하는 대각선
bool v3[30];	// 왼쪽 상단으로 향하는 대각선

int iAns = 0;


void Solved(int depth)
{	
	if (depth == n)
	{
		iAns++;
		return;
	}
		

	for (size_t i = 0; i < n; i++) // 열에 대한 루프
	{
		if (true == v1[i] || true == v2[depth + i] || true == v3[depth - i + (n-1)])
		{
			// 이미 뭐가 놓여져잇엇다
			continue;
		}
		else
		{
			v1[i] = true;
			v2[depth + i] = true;
			v3[depth - i + (n - 1)] = true;

			Solved(depth + 1);	// 다음 행으로 이동	// 이 다음줄에 실행된다는 의미는 함수가 종료조건을 만나지못하고 끝남

			v1[i] = false;
			v2[depth + i] = false;
			v3[depth - i + (n - 1)] = false;
		}

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

	cin >> n;
	Solved(0);
	cout << iAns;


	return 0;
}


