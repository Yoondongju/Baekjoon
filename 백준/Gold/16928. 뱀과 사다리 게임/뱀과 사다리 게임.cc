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




vector<int> Sadari(101,-1);
vector<int> Bam(101,-1);


int BFS()
{
    queue<int> q;
    vector<int> dist(101, -1);

    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int Cur = q.front();
        q.pop();

        for (size_t i = 1; i <= 6; i++)
        {
            int next = Cur + i;

            if (next > 100)
                continue;

            if (Sadari[next] != -1)
            {
                next = Sadari[next];
            }
            else if (Bam[next] != -1)
            {
                next = Bam[next];
            }

            if (dist[next] == -1)
            {
                // 방문 하지 않았을때만
                q.push(next);
                dist[next] = dist[Cur] + 1; // 다음에 가야하는 공간의 인덱스를 하나 증가시켜서 넘겨받아

                if (next == 100)
                {
                    cout << dist[next] << '\n';
                    return 0;
                }

            }

        }

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
        int x, y;
        cin >> x >> y;

        Sadari[x] = y;
    }

    for (size_t i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        Bam[x] = y;
    }

    // 1에서 100까지 도착하려면 주사위를 최소 몇번굴려야하나?

    BFS();
    
    return 0;
}

