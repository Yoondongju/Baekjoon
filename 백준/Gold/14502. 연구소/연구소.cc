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


int Map[9][9];
int Temp[9][9];
vector<pair<int, int>> empty_spaces, virus_positions;

bool visited[9][9] = {false};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Node
{
    int x;
    int y;
    int day;
};

queue<Node> q;


int max_safe_area = 0;

void spreadVirus()
{
    queue<pair<int, int>> q;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            Temp[i][j] = Map[i][j];
        }
    }


    for (auto v : virus_positions)
    {
        q.push(v);
    }


    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (Temp[nx][ny] == 0) { // 빈 칸이면 감염됨
                    Temp[nx][ny] = 2;
                    q.push({ nx, ny });
                }
            }
        }

    }


    // 안전 영역 크기 계산
    int safe_area = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (Temp[i][j] == 0)
                safe_area++;

    max_safe_area = max(max_safe_area, safe_area);

}

void DFS(int count, int start)
{
    if (count == 3)
    {
        spreadVirus();
        return;
    }
        

    for (size_t i = start; i < empty_spaces.size(); i++)
    {
        int x = empty_spaces[i].first;
        int y = empty_spaces[i].second;

        Map[x][y] = 1;
        DFS(count + 1, i + 1);
        Map[x][y] = 0;
    }

}



int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> N;
    cin >> M;


    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {            
            cin >> Map[i][j];

            if (Map[i][j] == 0)
                empty_spaces.push_back({ i, j }); // 빈 공간 저장
            else if (Map[i][j] == 2) 
                virus_positions.push_back({ i, j }); // 바이러스 위치 저장


        }
    }


    DFS(0, 0); // DFS로 벽 3개 배치 후 BFS 실행

    cout << max_safe_area << "\n";


  

    return 0;
}

