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




int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

  
    cin >> N >> K;
   

    queue<int> Queue;


    for (size_t i = 0; i < N; i++)
    {
        Queue.push(i + 1);
    }



    cout << "<";

    while (!Queue.empty())
    {
        for (size_t i = 1; i < K; i++)
        {
            Queue.push(Queue.front());
            Queue.pop();
        }

        cout << Queue.front();

        if(1 < Queue.size())
            cout << ", ";

        Queue.pop();

    }
   
    cout << ">";


    return 0;
}

