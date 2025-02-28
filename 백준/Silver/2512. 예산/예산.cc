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



bool BSearch(int mid)
{
    int sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        sum += min(v1[i],mid);
    }

    return sum <= M;        // 내가 정한 상한선보다 작다면 ?
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

  
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }

    cin >> M;

    sort(v1.begin(), v1.end()); // 이분탐색을 하기위한 정렬이고

    int L = 0;
    int R = v1.back();
    int result = 0;


    while (L <= R)  // 이분탐색조져
    {
        int mid = (L + R) / 2;
        if (BSearch(mid))   // 내가 상한선을 127로 둿는데 이거보다 크거나 같앗으면 mid를 더 앞으로 땡겨서 최대값인 아이를찾자
        {
            result = mid;
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }

    }

    
    cout << result;


    return 0;
}

