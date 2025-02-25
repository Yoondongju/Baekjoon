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
int MAX = -1000000000;
int MIN = 1000000000;

int Operator[4];	// 연산자 갯수
int num[11];		
int iAns = 0;


void Solved(int plus, int minus, int multiple, int divide, int x ,int sum)
{	
	if (x == n - 1)
	{
		if (sum < MIN) 
			MIN = sum;
		if (sum > MAX) 
			MAX = sum;
	}

	if (plus > 0) 
		Solved(plus - 1, minus, multiple, divide, x + 1, sum + num[x + 1]);
	if (minus > 0) 
		Solved(plus, minus - 1, multiple, divide, x + 1, sum - num[x + 1]);
	if (multiple > 0) 
		Solved(plus, minus, multiple - 1, divide, x + 1, sum * num[x + 1]);
	if (divide > 0) 
		Solved(plus, minus, multiple, divide - 1, x + 1, sum / num[x + 1]);
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
	for (size_t i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (size_t i = 0; i < 4; i++)
	{
		cin >> Operator[i];
	}


	Solved(Operator[0], Operator[1], Operator[2], Operator[3], 0, num[0]);
	cout << MAX << '\n';
	cout << MIN << '\n';


	return 0;
}


