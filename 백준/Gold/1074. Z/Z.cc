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

int r;
int c;

vector<vector<int>> Array;

int cnt = 0;

void Divide(int y, int x ,int Size)
{
    if (1 == Size)
    {
        return;
    }


    int newSize = Size / 2;


    if (r < y + newSize && c < x + newSize)
    {
        Divide(y, x, newSize);
    }
   
    else  if (r < y+ newSize && c >= x + newSize)
    {
        cnt += newSize * newSize;
        Divide(y, x + newSize, newSize);      
    }
  
   else if (r >= y + newSize && c < x + newSize)
    {
        cnt += 2 * newSize * newSize;
        Divide(y + newSize, x, newSize); 
    }
    else
    {
        cnt += 3 * newSize * newSize;

        Divide(y + newSize, x + newSize, newSize);
     
    }


}


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> r;
    cin >> c;

    Divide(0, 0 , 1 << N); 
    cout << cnt << '\n'; 
 






    return 0;
}

