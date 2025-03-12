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

int score[301];
int stair[301];

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    
    for (size_t i = 1; i <= N; i++)
    {
        cin >> stair[i];
    }

    score[1] = stair[1];
    score[2] = score[1] + stair[2];
    score[3] = max(stair[1] + stair[3] , stair[2] + stair[3]);


    for (size_t i = 4; i <= N; i++)
    {
        score[i] = max(stair[i] + stair[i - 1] + score[i - 3], score[i - 2] + stair[i]);
    }


    cout << score[N];

    return 0;
}

