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
int M = 0;
int V = 0;

vector<vector<int>> Map;
vector<vector<bool>> visited;

vector<int> HouseCount;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int cnt = 0;


void DFS(int x, int y) {
    visited[x][y] = true;
    cnt++; // 현재 단지 크기 증가

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N) { // 범위 체크
            if (Map[nx][ny] == 1 && !visited[nx][ny]) { // 집이 있고, 방문하지 않은 경우
                DFS(nx, ny);
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> N;

    Map.resize(N, vector<int>(N,0));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < N; j++) {
            Map[i][j] = row[j] - '0'; 
        }
    }

    int totalCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Map[i][j] == 1 && !visited[i][j]) 
            { 
                cnt = 0; 
                DFS(i, j);
                HouseCount.push_back(cnt);
                totalCount++; // 단지 개수 증가
            }
        }
    }


    sort(HouseCount.begin(), HouseCount.end());

    cout << totalCount << '\n';
    for (int count : HouseCount) {
        cout << count << '\n';
    }


    return 0;
}

