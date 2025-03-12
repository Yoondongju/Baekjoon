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


bitset<21> S;

void add(int x) {
    S.set(x);
}

void remove(int x) {
    S.reset(x);
}

void check(int x) {
    printf("%d\n", S.test(x) ? 1 : 0);
}

void toggle(int x) {
    S.flip(x);
}

void all() {
    S.set();  // 모든 비트를 1로 설정
}

void empty() {
    S.reset();  // 모든 비트를 0으로 설정
}

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> M;


    for (size_t i = 0; i < M; i++)
    {
        string s;
        int x = 0;

        cin >> s;

        
        if (s == "add" || s == "check" || s == "remove" || s == "toggle")
            cin >> x;

        if ("add" == s) {
            add(x);
        }
        else if ("check" == s) {
            check(x);
        }
        else if ("remove" == s) {
            remove(x);
        }
        else if ("toggle" == s) {
            toggle(x);
        }
        else if ("all" == s) {
            all();
        }
        else if ("empty" == s) {
            empty();
        }
    }


   

    return 0;
}

