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


int iCountF1 = 0;
int iCountF2 = 0;

int Fib(int n)  // 피보나치 재귀함수
{

    if (1 == n || 2 == n)
    {
        return 1;
    }
    else
    {
        ++iCountF1;

        return Fib(n - 1) + Fib(n - 2);
    }
}

int dp[41] = {-1};


int FiboDP(int n)
{
    if (n <= 1 || n <= 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    ++iCountF2;

    return dp[n] = FiboDP(n - 1) + FiboDP(n - 2);

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    memset(dp, -1, sizeof(dp));
    dp[1] = dp[2] = 1;

    cin >> N;

    iCountF1 = 1;

    Fib(N);
    FiboDP(N);

    cout << iCountF1 << " " << iCountF2;

    return 0;
}

