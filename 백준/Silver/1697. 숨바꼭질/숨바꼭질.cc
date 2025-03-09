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

int N;     // 가로
int M;     // 세로
int K;



int Map[9][9];
int Temp[9][9];
vector<pair<int, int>> empty_spaces, virus_positions;

int visited[1000001] = { 0 };



struct Node
{
    int x;
    int y;
    int day;
};

queue<Node> q;


int BFS(int n, int k)
{
    queue<int> q;

    q.push(n);
    visited[n] = 1;

    while (!q.empty())
    {
       int Index =  q.front();
       q.pop();

       if (Index == K)
           return visited[Index] - 1;   // 왜 ?


       int next;

       next = Index - 1;
       if (next >= 0 && next <= 100000 && !visited[next])
       {
           visited[next] = visited[Index] + 1;
           q.push(next);
       }


       next = Index + 1;
       if (next >= 0  && next <= 100000 && !visited[next]) {
           visited[next] = visited[Index] + 1;
           q.push(next);
       }

       
       next = Index * 2;
       if (next >= 0  && next <= 100000 && !visited[next]) {
           visited[next] = visited[Index] + 1;
           q.push(next);
       }

    }

    return -1;
    

}


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    // 걷기 x-1, x+1 , 순간이동은 2*X   각 1초가 걸리는거야 
    cin >> N;       // 수빈이 위치
    cin >> K;       // 동생 위치



    
    cout << BFS(N, K) << "\n";
    

  

    return 0;
}

