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

  
    cin >> N;

    // x가 3의 배수면 3으로 나눈다
    // x가 2의 배수면 2로 나눈다
    // 1을 뺀다

    int Dp[1000000];

    for (size_t i = 2; i <= N; i++)
    {
        Dp[i] = Dp[i - 1] + 1;

        if (i % 2 == 0)
        {
            Dp[i] = min(Dp[i], Dp[i / 2] + 1);
        }

        if (i % 3 == 0)
        {
            Dp[i] = min(Dp[i], Dp[i / 3] + 1);
        }
    }

    cout << Dp[N];


    return 0;
}

