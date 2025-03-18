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

int Map[10][10];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


vector<int> Array;


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        Array.push_back(x);
    }

    vector<int> dp(N, 1);

    for (size_t i = 1; i < N; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (Array[i] > Array[j])  // 증가하는 부분 수열 조건
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}

