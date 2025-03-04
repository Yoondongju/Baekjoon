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
vector<int> coin;




int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> N;
    cin >> K;

    for (size_t i = 0; i < N; i++)
    {
        int iValue = 0;
        cin >> iValue;

        coin.push_back(iValue);
    }


    int i = 0;
    int iCount = 0;

    while (1)
    {
        if (K <= 0)
            break;

        int iValue = coin[N - 1 - i];
        if (K >= iValue)
        {
            K = K - iValue;
            iCount++;
        }
        else
            i++; 
    }

    cout << iCount;
   
    return 0;
}

