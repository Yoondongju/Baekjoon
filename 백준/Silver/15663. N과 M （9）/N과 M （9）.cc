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

void DFS(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++) {
            cout << Result[i] << " ";
        }
        cout << "\n";

        return;
    }


    
    int prev = -1;

    for (size_t i = 0; i < Array.size(); i++)
    {
        if (false == visited[i] && prev != Array[i])
        {
            visited[i] = true;
            Result[depth] = Array[i];

            prev = Array[i];

            DFS(depth + 1);

            visited[i] = false;
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
    Result.resize(N, 0);

    for (size_t i = 0; i < N; i++)
    {
        cin >> Array[i];
    }

    sort(Array.begin(), Array.end());

    Result.resize(M);  // M개 선택하기 때문에 M 크기로 변경

    DFS(0);

    return 0;
}

