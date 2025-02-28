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

int N = 0;
int K = 0;
int M = 0;
vector<int> v1;



bool BSearch(int mid)
{

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

  
    cin >> N;


    for (size_t i = 0; i < N; i++)
    {
        int x; 
        cin >> x;

        v1.push_back(x);
    }



    vector<int> LIS;    // LIS란 가장 긴 부분수열을 구할때 사용할 새로운 벡터

    for (size_t i = 0; i < N; i++)
    {
        int num = v1[i];

        auto iter = lower_bound(LIS.begin(), LIS.end(), num);     // num이 들어갈 자리를 나타낸다

        // 만약 num이 모든 LIS요소보다 크다면 맨뒤 삽입  젤 크다는건
        // iter가 end가 나오고 
        // 그게아니라면 작거나 같은 그 위치의 iter가 나온다 만약 10이라면 10자리의 위치가 나오고
        // 11이라면 10보다 크고 LIS의 10 다음의 요소보다 작은 위치로 나온다

        if (iter == LIS.end())
        {
            LIS.push_back(num);
        }
        else
        {
            *iter = num;
        }
    }


    cout << LIS.size() << '\n';



    return 0;
}

