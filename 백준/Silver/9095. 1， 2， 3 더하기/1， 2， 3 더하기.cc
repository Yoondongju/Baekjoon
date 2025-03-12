#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

using namespace std;

#pragma warning(disable:4996)

typedef unsigned int uint;

int N;
int M;
int H;
int T;

int r;
int c;

int Array[101][101][101];

int cnt = 0;


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int dp[11];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;

    cin >> T;

    for (size_t i = 5; i < 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }


    for (size_t i = 0; i < T; i++)
    {
        int x; 
        cin >> x;

        cout << dp[x] << '\n';
    }


    return 0;
}

