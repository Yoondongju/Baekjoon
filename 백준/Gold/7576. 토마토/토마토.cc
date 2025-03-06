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

int M;     // 가로
int N;     // 세로

// 1은 익은토마토  0은 익지 않은 토매토   -1은 토마토가 없음
int Map[1001][1001];
bool visited[1001][1001] = {false};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Node
{
    int x;
    int y;
    int day;
};


queue<Node> q;

void BFS(int StartX, int StartY)
{
    int maxDay = 0;

    while (!q.empty())
    {
        Node Data = q.front();
        q.pop();

        maxDay = max(maxDay, Data.day);

        for (size_t i = 0; i < 4; i++)
        {
            int nx = Data.x + dx[i];
            int ny = Data.y + dy[i];

            if (nx >= 0 &&
                ny >= 0 &&
                nx < M &&
                ny < N &&      
                0 == Map[ny][nx])
            {
                q.push({ nx,ny , Data.day + 1 });
                Map[ny][nx] = 1;

            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Map[i][j] == 0) { 
                cout << -1 << '\n';
                return;
            }
        }
    }

    cout << maxDay << '\n';  

}


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> M;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tomato = 0;
            cin >> tomato;

            Map[i][j] = tomato;


            if (1 == tomato)
            {
                q.push({ j,i ,0});
            }

        }
    }
    

    // 토마토가 모두 익는 상황일때의 최소 날짜를 구해라
    // 토마토가 저장될때부터 모두 익엇으면 0  토마토가 모두 익지 못하면 -1 그외는 최소날짜 bfs

    BFS(0, 0);

  

    return 0;
}

