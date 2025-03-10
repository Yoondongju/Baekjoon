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

int N;

int Paper[128][128];

int White = 0;
int Blue = 0;



bool Check(int x, int y, int Size)
{
    int Color = Paper[x][y];    // 일단 색종이 한장의 색깔ㅇ

    for (size_t i = x; i < x + Size; i++)
    {
        for (size_t j = y; j < y + Size; j++)
        {
            if (Color != Paper[i][j])
                return false;
        }
    }

    return true;
}



void Divide(int x, int y, int Size)
{
    if (Check(x,y,Size))
    {
        if (0 == Paper[x][y])
        {
            White++;
        }
        else
        {
            Blue++;
        }

        return;
    }

    int newSize = Size / 2;

    Divide(x, y, newSize);
    Divide(x + newSize, y, newSize);
    Divide(x, y + newSize, newSize);
    Divide(x + newSize, y + newSize , newSize);
}




int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;


    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> Paper[i][j];
        }
    }

    Divide(0, 0, N);

    cout << White << '\n';
    cout << Blue << '\n';
  

    return 0;
}

