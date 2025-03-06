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


int T = 0;  // 테스트 케이스
int M = 0;  // 가로 길이
int N = 0;  // 세로 길이

int K = 0;  // 배추가 심어져 있는 위치의 개수

int Map[51][51] = {};
bool visited[51][51] = { false };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Node
{
    int x;
    int y;
};

void BFS(int StartX, int StartY)
{
    queue<Node> q;
    q.push({ StartX,StartY });
    visited[StartX][StartY] = true;


    while (!q.empty())
    {
        Node Data = q.front();
        q.pop();

      
        for (size_t i = 0; i < 4; i++)
        {
            int nx = Data.x + dx[i];
            int ny = Data.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < M && ny < N && false == visited[nx][ny] && 0 != Map[nx][ny])
            {
                // 이동가능해용~
                q.push({ nx,ny });
                visited[nx][ny] = true;
            }

        }
    }

}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        cin >> M;
        cin >> N;
        cin >> K;


        memset(Map, 0, sizeof(Map));
        memset(visited, false, sizeof(visited));


        for (size_t i = 0; i < K; i++)
        {
            int x, y;

            cin >> x;
            cin >> y;

            Map[x][y] = 1;
        }


        int ans = 0;
        for (size_t i = 0; i < M; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (1 == Map[i][j] && false == visited[i][j])
                {
                    BFS(i, j);
                    ++ans;
                }
                   
            }

        }


        cout << ans << '\n';
    }

    
    



    return 0;
}

