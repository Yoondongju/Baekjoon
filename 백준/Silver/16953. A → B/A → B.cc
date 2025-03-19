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


vector<int> Array, Result;
bool visited[10001];



void BFS()
{
    queue<pair<long long int, int>> q;

    q.push(make_pair(N, 1));

    while (!q.empty())
    {
        auto pair = q.front();

        long long int value = pair.first;
        int n = pair.second;

        if (value == M)
        {
            cout << n;
            return;
        }

        q.pop();


        if (value * 2 <= M)
        {
            q.push(make_pair(value * 2, n + 1));
        }
        if (value * 10 + 1 <= M)
        {
            q.push(make_pair(value * 10 + 1 , n + 1));
        }
    }

    cout << "-1";
}


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

  
    cin >> N;       // A
    cin >> M;       // B 


    BFS();



    return 0;
}

