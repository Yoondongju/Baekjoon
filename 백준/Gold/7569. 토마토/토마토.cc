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

int r;
int c;

int Array[101][101][101];

int cnt = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dh[2] = { -1,1 };

struct Data
{
    int h;
    int y;
    int x;
};

queue<Data> q;
void BFS()
{
    while (!q.empty())
    {
        Data Data = q.front();
        q.pop();


        for (size_t i = 0; i < 4; i++)
        {
            int nx = dx[i] + Data.x;
            int ny = dy[i] + Data.y;

            if (nx >= 0 && nx <= M - 1 && ny >= 0 && ny <= N - 1 &&  0 == Array[Data.h][ny][nx])
            {
                // 갈수있는 상항이라면
                Array[Data.h][ny][nx] = Array[Data.h][Data.y][Data.x] + 1;
                q.push({ Data.h,ny,nx });
            }
        }


        for (int i = 0; i < 2; i++) {
            int nh = Data.h + dh[i];
            if (nh >= 0 && nh < H && Array[nh][Data.y][Data.x] == 0) 
            {
                Array[nh][Data.y][Data.x] = Array[Data.h][Data.y][Data.x] + 1;
                q.push({ nh, Data.y, Data.x });
            }
        }
    }

   

}



int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M;   // 상자 가로   
    cin >> N;   // 상자 세로
    cin >> H;   // 상자 수


    // 토마토가 첨부터 다익엇으면 0출력
    // 토마토가 모두 익지 못하는 상황이면 -1

    // 1 익은토마토, 0 익지 않은 토마토 -1 토마토 안들어잇음

    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> Array[h][i][j];

                if (Array[h][i][j] == 1) {
                    // 익은 토마토는 미리 큐에 넣기
                    q.push({ h, i, j });
                }
            }
        }
    }
   


    BFS();


    int maxDays = 0;
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) 
            {
                if (Array[h][i][j] == 0)          
                {
                    cout << -1 << '\n';
                    return 0;
                }
                maxDays = max(maxDays, Array[h][i][j]);
            }
        }
    }

    cout << maxDays - 1 << '\n';
    return 0;
}

