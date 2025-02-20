
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

int N, M;				// N: 전체 숫자 범위,  M: 고를 숫자의 갯수
vector<int> perm;		// 고른 숫자를 저장할 벡터
vector<bool> visited;	// 이미 고른 숫자를 체크할 배열


void BackTracking(int Depth)
{
	if (Depth == M)
	{
		// 종료
		for (size_t i = 0; i < M; i++)
		{
			cout << perm[i] << " ";
		}

		cout << "\n";
		return;
	}


	for (size_t i = 1; i <= N; i++)
	{
		if (false == visited[i])
		{
			visited[i] = true;
			perm.push_back(i);

			BackTracking(Depth + 1);

			perm.pop_back();   // 2번째 재귀시점에서 2를 삭제
			visited[i] = false;
		}
		

	}

}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	cin >> N >> M;

	perm.reserve(M);  
	visited.resize(N + 1, false);  // visited 배열 크기 N+1로 설정



	BackTracking(0);  // 백트래킹 함수 호출 (초기 깊이는 0)



	return 0;
}


