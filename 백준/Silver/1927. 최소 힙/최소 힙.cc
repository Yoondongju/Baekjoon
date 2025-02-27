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

vector<int> v1;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    priority_queue<int, vector<int>, greater<int>> pq;
    

    cin >> N;
    int x = 0;

    for (size_t i = 0; i < N; i++)
    {
        cin >> x;

        if( 0 != x)
            pq.push(x);
        else
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << '0' << '\n';
          
        }       
    }
   


    return 0;
}

