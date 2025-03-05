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

int Array[101][101];
bool visited[101][101];

int dx[4] = { 1, -1, 0, 0 };  // 우, 좌, 하, 상 이동
int dy[4] = { 0, 0, 1, -1 };


struct Node
{
    int x, y, dist;
};

int BFS(int StartX, int StartY)
{
    queue<Node> q;
    q.push({ StartX,StartY, 1 });

    visited[StartX][StartY] = true;

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();


        if (node.x == N - 1 && node.y == M - 1)
        {
            return node.dist;
        }


        for (size_t i = 0; i < 4; i++)
        {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];


            if (nx >=0 && ny >= 0 && nx < N && ny < M && false == visited[nx][ny] && 0 != Array[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({ nx,ny,node.dist + 1 });
            }
        }
    }

    return -1;


}




int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> N;
    cin >> M;

    for (size_t i = 0; i < N; i++)
    {
        string row;
        cin >> row;

        for (size_t j = 0; j < M; j++)
        {
        
            Array[i][j] = row[j] - '0';
        }
    }

    cout << BFS(0, 0) << endl;

    return 0;
}

