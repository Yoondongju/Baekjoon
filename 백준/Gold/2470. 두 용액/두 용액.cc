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


vector<int> Array;
int ans = 2e9;
int leftValue, rightValue;  

void BinarySearch(int L, int R)
{
    while (L < R)
    {
        int sum = Array[L] + Array[R];

     
        if (abs(sum) < abs(ans)) 
        {
            ans = sum;  // 최소갱신
     
            leftValue = Array[L];   // 두 용액의 값을 저장
            rightValue = Array[R];  // 두 용액의 값을 저장
        }


        if (sum < 0) {
            L++;  
        }
        else {
            R--;  
        }
    }
 

   
}

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> N;
   
    Array.resize(N, 0);

    for (size_t i = 0; i < N; i++)
    {
        cin >> Array[i];
    }

    sort(Array.begin(), Array.end());


    BinarySearch(0, N-1);

    cout << leftValue << " " << rightValue << '\n';  

    return 0;
}

