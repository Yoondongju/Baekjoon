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


int N;


void Kantoi(string& strTest, int iStart, int iLength)
{
	if (iLength == 1)
		return;


	int iThird = iLength / 3;		// 3등분 길이


	for (size_t i = iStart + iThird; i < iStart + 2 * iThird; i++)
	{
		strTest[i] = ' ';
	}


	Kantoi(strTest, iStart, iThird);
	Kantoi(strTest, iStart +  2 * iThird, iThird);
	
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	int N;
	while (cin >> N)  // 여러 개의 테스트 케이스를 처리할 수 있도록
	{
		int iValue = 1;
		for (int i = 0; i < N; i++)
		{
			iValue *= 3;
		}

		string strTest(iValue, '-'); // 처음에는 모든 문자가 '-'

		Kantoi(strTest, 0, iValue);  // 칸토어 집합 생성

		cout << strTest << "\n";
	}
	

	return 0;
}


