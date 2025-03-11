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

vector<long long> Array;


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> N;

    Array.resize(101,0);

    Array[0] = 1;
    Array[1] = 1;
    Array[2] = 1;

    vector<int>Index(N, 0);


    vector<int> tests(N);
    int maxTest = 0;

    for (int i = 0; i < N; i++) {
        cin >> tests[i];
        if (tests[i] > maxTest) {
            maxTest = tests[i]; 
        }
    }
    
    for (size_t j = 3; j <= maxTest; j++)
    {
        Array[j] = Array[j - 2] + Array[j - 3];
    }


    for (int i = 0; i < N; i++) {
        cout << Array[tests[i] - 1] << '\n';
    }


    return 0;
}

