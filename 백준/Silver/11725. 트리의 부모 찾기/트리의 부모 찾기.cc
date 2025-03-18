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


vector<int> Array[100001];
int parent[100001];

void DFS(int Start)
{

    for (size_t i = 0; i < Array[Start].size(); i++)
    {
        int next = Array[Start][i];

        if (parent[next] == 0)
        {
            parent[next] = Start;   // 6번의 부모는 2에요
            DFS(next);
        }
    }
  
}



int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

  
    for (size_t i = 0; i < N-1; i++)
    {
        int x, y;
        cin >> x >> y;

        Array[x].push_back(y);
        Array[y].push_back(x);
    }

    parent[1] = 1;
    DFS(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}

