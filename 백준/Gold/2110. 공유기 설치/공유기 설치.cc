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

int N, C;   // 집 개수,공유기 개수

vector<int> HomePos;



bool isValid(int Distance)
{
    int Count = 1;
    int LastInstall = HomePos[0];

    for (size_t i = 1; i < N; i++)
    {
        if (HomePos[i] - LastInstall >= Distance)
        {
            Count++;
            LastInstall = HomePos[i];
        }
    }

    return Count >= C;
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> N >> C;

    for (size_t i = 0; i < N; i++)
    {
        int iPosX;
        cin >> iPosX;
       
        HomePos.push_back(iPosX);
    }
    
    sort(HomePos.begin(), HomePos.end());

    int L = 0;
    int R = HomePos[N - 1] - HomePos[0];
    int Result = 0;

    while (L <= R)
    {
        int iMid = (L + R) / 2;

        if (isValid(iMid)) //  3개 이상이엿어?
        {
            Result = iMid;  // 결과가 중간값으로 갱신시켜
            L = iMid + 1;
        }    
        else
            R = iMid - 1;

    }

    cout << Result << '\n';

    

    




    return 0;
}

