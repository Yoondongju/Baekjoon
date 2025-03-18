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
int H;
int T;

int r;
int c;

int Array[101][101][101];

int cnt = 0;

string s[601];  // N의크기
bool visible[601][601];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


// 커마 함수 만들때  a < b 라면 큰게 더 앞쪽에 가는거니까 내림차순
// 커마 함수 만들때  a > b 라면 작은게 더 앞쪽에 가는거니까 오름차순

struct compare {
    bool operator()(int a, int b) {
        // 절댓값이 작은 것이 우선
        if (abs(a) == abs(b)) {
            return a > b;  // 절댓값이 같으면 더 작은 값이 우선
        }
        return abs(a) > abs(b);  // 절댓값이 작은 것이 우선
    }
};

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> N;

    int factorial = 1; 

    for (int i = 1; i <= N; i++) {
        factorial *= i;  // i를 곱하여 누적
    }

    cout << factorial << endl;  // 결과 출력


    
    return 0;
}

