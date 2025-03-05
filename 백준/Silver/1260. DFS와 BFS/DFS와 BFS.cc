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
vector<int> v1;

vector<int>graph[1001];
bool visited[1001];




void DFS(int v) {
    cout << v << ' '; 
    visited[v] = true; 

    for (int next : graph[v]) {
        if (!visited[next]) { 
            DFS(next);
        }
    }
}

void BFS(int v) {
    queue<int> q;
    bool visitedBFS[1001] = { false }; 

    q.push(v);
    visitedBFS[v] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int next : graph[cur]) {
            if (!visitedBFS[next]) {
                q.push(next);
                visitedBFS[next] = true;
            }
        }
    }
}




int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> N;
    cin >> M;
    cin >> V;

    for (size_t i = 0; i < M; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    for (size_t i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);
    cout << '\n';

   
    BFS(V);
    cout << '\n';


    return 0;
}

