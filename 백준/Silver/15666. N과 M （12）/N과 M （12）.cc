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


vector<int> Array,Result;
bool visited[10001];


void DFS(int depth, int start)
{
    if (depth == M)
    {
        for (size_t i = 0; i < M; i++)
        {
            cout << Result[i]<< " ";
        }
        cout << '\n';
        return;
    }


    int prev = -1;

    for (size_t i = start; i < N; i++)
    {
        if (Array[i] != prev)
        {
            prev = Array[i];
            
            Result[depth] = Array[i];

            DFS(depth + 1, i);
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

    Array.resize(N, 0);
    Result.resize(M, 0);

    for (size_t i = 0; i < N; i++)
    {
        cin >> Array[i];
    }

    sort(Array.begin(), Array.end());

    DFS(0,0);

    return 0;
}

