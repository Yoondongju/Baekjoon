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

int Array[101][101][101];

int cnt = 0;

string s[601];  // N의크기
bool visible[601][601];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void DFS(int y, int x, int depth)
{
    visible[y][x] = true;
    if ('P' == s[y][x])
        ++cnt;

    for (size_t i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < M && ny < N && false == visible[ny][nx] && 'X' != s[ny][nx])
        {    
            visible[ny][nx] = true;
            DFS(ny, nx, depth + 1);
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

    int startX;
    int startY;
    bool check = false;

    for (size_t i = 0; i < N; i++)
    {
        cin >> s[i];

        if (false == check)
        {
            for (size_t j = 0; j < M; j++)
            {
                if ('I' == s[i][j])
                {
                    startX = j;
                    startY = i;
                    check = true;
                }
            }
        } 
    }

    DFS(startY, startX, 0);

    if (0 == cnt)
        cout << "TT" << '\n';
    else
        cout << cnt << '\n';


    return 0;
}

