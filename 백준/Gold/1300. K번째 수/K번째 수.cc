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

long long N = 0;
long long K = 0;

bool    Solved(long long mid)     // num보다 작은수가 배열 A에 몇개들어있니 ?
{
    long long count = 0;
    for (int i = 1; i <= N; i++)
    {
        count += min(mid / i, N);
    }

    return count >= K;           // 7 보다 크니? 
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

  
    cin >> N >> K;
   

    long long L = 1;
    long long R = N * N;
  
    long long ans = 0;


    while (L <= R)
    {
        long long mid = (L + R) / 2;
        
        
        if (Solved(mid))
        {
            ans = mid;
            R = mid - 1;
        }
        else
            L = mid + 1;
    }
    
    cout << ans << '\n';



    return 0;
}

