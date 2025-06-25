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
#include <cmath>

using namespace std;

#pragma warning(disable:4996)

typedef unsigned int uint;

//int N;
int M;



int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

   
    int N;
    cin >> N;
    
    // 1번 집과 2번 집의 색은 달라야함
    // N번 집은 N-1 집이랑 색 달라야함 
    // i번 집은 i-1, i+1집과 색 달라야함 

    vector<vector<int>> cost(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    vector<vector<int>> dp(N, vector<int>(3));
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < N; ++i) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]); 
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    // 최소 비용 출력
    int answer = min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
    cout << answer << "\n";


    return 0;
}

