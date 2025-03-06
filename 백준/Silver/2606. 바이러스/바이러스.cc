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
int M = 0;
int V = 0;

vector<vector<int>> com;     // 내 컴터번호, 나랑 연결된 컴터의 번호
vector<bool> visited;

int ans = 0;

void DFS(int depth)
{
  
    visited[depth] = true;
    
    for (size_t i = 0; i < com[depth].size(); i++)
    {
        int Next = com[depth][i];

        if (false == visited[Next])
        {
            ++ans;
            DFS(Next);
           
        }       
    }

    
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> N;
    cin >> M;

    com.resize(N + 1);
    visited.resize(N + 1,false);

    for (size_t i = 0; i < M; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;

        com[a].push_back(b);
        com[b].push_back(a);
    }

    DFS(1);

    cout << ans << '\n';

    return 0;
}

