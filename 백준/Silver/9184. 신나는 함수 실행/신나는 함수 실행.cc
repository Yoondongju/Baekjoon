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

int memo[21][21][21] = {};

int Fun(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        return Fun(20, 20, 20);
    }


    if (memo[a][b][c] != 0)
        return  memo[a][b][c];

    if (a < b && b < c)
    {
        memo[a][b][c] = Fun(a, b, c - 1) + Fun(a, b - 1, c - 1) - Fun(a, b - 1, c);
        return memo[a][b][c];
    }


    memo[a][b][c] = Fun(a - 1, b, c) + Fun(a - 1, b - 1, c) + Fun(a - 1, b, c - 1) - Fun(a - 1, b - 1, c - 1);
    return memo[a][b][c];
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

   
    int a, b, c;
    while (true)
    {
        std::cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << Fun(a, b, c) << '\n';
    }

    return 0;
}

