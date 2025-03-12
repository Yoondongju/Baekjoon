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


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> N;
    
    // 각 테스트 케이스마다 0이 출력되는 횟수랑 1이 출력되는 횟수를 공백 구분해서 출력

    vector<int> Array(41,0);
    vector<int> zero(41, 0);
    vector<int> one(41, 0);

    Array[0] = 0;
    Array[1] = 1;

    zero[0] = 1;
    zero[1] = 0;

    one[0] = 0;
    one[1] = 1;

    for (size_t i = 2; i <= 40; i++)
    {
        Array[i] = Array[i - 1] + Array[i - 2];
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }

    for (size_t i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        cout << zero[x] << " " << one[x] << '\n';
    }

    return 0;
}

