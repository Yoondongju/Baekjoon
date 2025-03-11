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

int Paper[2200][2200];

int mi = 0;
int zero = 0;
int one = 0;



vector<int> Array;


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

   

    long long dp[1000001];

    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
    }
    cout << dp[N] % 15746;

    return 0;
}

