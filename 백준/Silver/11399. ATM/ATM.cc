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
vector<int> v1;




int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

   // 인덱스가 사람의 순서고
   // 밸류가 그사람이 인출하는데 걸리는 시간이야
   // 가장 최소는 인출하는데 걸리는 시간순대로 오름차순 정렬을 하는게 최소야

    cin >> N;


    for (size_t i = 0; i < N; i++)
    {
        int iTime = 0;
        cin >> iTime;

        v1.push_back(iTime);
    }

    sort(v1.begin(), v1.end());
 
    int result = 0;
   
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j <= i; ++j) 
        {
            result += v1[j];
        }
    }


    cout << result;

    return 0;
}

