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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 풍선 터트리고 안에가 양수면 오른쪽으로 음수면 왼쪽으로 이동 그 안에적인 수만큼

    deque<pair<int,int>> dq;

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int input = 0;
        cin >> input;

        dq.push_back(make_pair(input,i+1));
    }


    // 3 2 1 -3 -1 이면 얘네의 인덱스를 i+1한개 출력값이고  그 요소의 값대로 이동

    int iCurIndex = 0;

    while (!dq.empty())
    {
        int iCur = dq.front().first;  // num값
        cout << dq.front().second << " ";   // 인덱스값

        dq.pop_front();


        if (dq.empty())
            break;

        if (iCur > 0)
        {
            for (size_t i = 0; i < iCur-1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            for (size_t i = 0; i < iCur * (- 1); i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

    }

    return 0;
}

