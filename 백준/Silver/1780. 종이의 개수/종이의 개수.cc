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

int Paper[2200][2200];

int mi = 0;
int zero = 0;
int one = 0;

bool Check(int y, int x, int Size)
{
    int Cur = Paper[y][x];

    for (size_t i = y; i < y + Size; i++)
    {
        for (size_t j = x; j < x + Size; j++)
        {
            if (Cur != Paper[i][j])
                return false;
        }
    }

    return true;
}


void Divide(int y, int x, int Size)
{

    if (Check(y, x, Size))
    {
        if (-1 == Paper[y][x])
            mi++;
        else if (0 == Paper[y][x])
            zero++;
        else if (1 == Paper[y][x])
            one++;

        return;
    }

    int newSize = Size / 3;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            Divide(y + i * newSize, x + j * newSize, newSize);
        }
    }
   
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

    cout << mi << '\n';
    cout << zero << '\n';
    cout << one << '\n';


    return 0;
}

