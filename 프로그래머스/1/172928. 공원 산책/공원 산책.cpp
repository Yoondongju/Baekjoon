#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;

    int H = park.size();
    int W = park[0].size();

    pair<int, int> S = {0,0};
    for (size_t i = 0; i < H; i++)
    {
        int W = park[i].size();

        for (size_t j = 0; j < W; j++)
        {
            if ('S' == park[i][j])
            {
                S.first = i;    // ㅅㄹ
                S.second = j;   // ㄱㄹ
            }
        }
    }


    for (size_t i = 0; i < routes.size(); i++)
    {
        char dir = routes[i][0];
        int dist = routes[i][2] - '0';

        int dy = 0, dx = 0;

        if (dir == 'E') dx = 1;
        else if (dir == 'W') dx = -1;
        else if (dir == 'S') dy = 1;
        else if (dir == 'N') dy = -1;

        int nx = S.second;

        int ny = S.first;

        bool blocked = false;

        for (size_t i = 0; i < dist; i++)
        {
            int tx = nx + dx * (i + 1);
            int ty = ny + dy * (i + 1);

            if (ty < 0 || ty >= H || tx < 0 || tx >= W || park[ty][tx] == 'X')
            {
                blocked = true;
                break;
            }

        }

        if (false == blocked)
        {
            S.first += dy * dist;
            S.second += dx * dist;
        }
    }

    answer.push_back(S.first);   // 세로 좌표
    answer.push_back(S.second);  // 가로 좌표

    return answer;
}
