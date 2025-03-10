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

int Paper[64][64];

int White = 0;
int Blue = 0;


bool Check(int x, int y, int Size)
{
    int Cur = Paper[x][y];

    for (size_t i = x; i < x + Size; i++)
    {
        for (size_t j = y; j < y + Size; j++)
        {
            if (Cur != Paper[i][j])
                return false;
        }

    }

    return true;
}


void Divide(int x, int y, int Size)
{  
    if (Check(x, y, Size))
    {
        cout << Paper[x][y];
        return;
    }


    int newSize = Size / 2;

    cout << "(";


    Divide(x, y, newSize);                  // 왼쪽 상단
    Divide(x, y + newSize, newSize);        // 왼쪽 하단
    Divide(x + newSize, y, newSize);        // 오른쪽 상단
    Divide(x + newSize, y + newSize, newSize);  // 오른쪽 하단

    //Divide(x, y, newSize);
    //Divide(x + newSize, y, newSize);
    //Divide(x, y + newSize, newSize );
    //Divide(x + newSize, y + newSize, newSize );

    cout << ")";
}




int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (size_t j = 0; j < N; j++)
        {
            Paper[i][j] = s[j] - '0';
        }
    }


    Divide(0, 0, N);



    return 0;
}

