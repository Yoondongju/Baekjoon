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


vector<int> Array,result;
bool visited[9];

void Solve(int depth)
{
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (size_t i = 0; i < N; i++)
    {
        if (false == visited[i])
        {
            visited[i] = true;

            result.push_back(Array[i]);
            Solve(depth + 1);

            visited[i] = false;
            result.pop_back();

        }

    }

}

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> M;

    for (size_t i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        Array.push_back(x);
    }

    sort(Array.begin(), Array.end());

    Solve(0);

    return 0;
}

