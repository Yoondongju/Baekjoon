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

int N = 0;
int K = 0;
int M = 0;
vector<pair<int,int>> v1;


bool Compare(pair<int, int>& v1, pair<int, int>& v2)
{
    if (v1.second == v2.second)
        return v1.first < v2.first;

    return v1.second < v2.second;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> N;
 
    // 시작과 끝시간의 차이가 최소인걸 선택해야 최대 회의개수를 알수있지않나?
    // 또는 회의의 시간이 가장 오전시간일때 부터 선택해야 최대로 뽑아먹을수잇어


    for (size_t i = 0; i < N; i++)
    {
        int iStart = 0;
        int iEnd = 0;

        cin >> iStart;
        cin >> iEnd;

        v1.push_back(make_pair(iStart, iEnd));
    }

    sort(v1.begin(), v1.end(), Compare);

    int iLastTime = 0;
    int iCount = 0;

    for (size_t i = 0; i < v1.size(); i++)
    {
        if (v1[i].first >= iLastTime)
        {
            iLastTime = v1[i].second;
            iCount++;
        }
    }

    cout << iCount;


    return 0;
}

