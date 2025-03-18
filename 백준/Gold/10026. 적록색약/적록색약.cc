#include "iostream"
#include "queue"

#define R 1
#define G 2
#define B 3

using namespace std;

int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int solve(int paint[101][101]){
    bool visited[101][101] = {false, };
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!visited[i][j]){
                queue<pair<int, int>> Q;
                Q.push({i, j});
                visited[i][j] = true;
                while (!Q.empty()) {
                    pair<int, int> u = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = u.first+ dx[k];
                        int ny = u.second + dy[k];
                        if (nx < 1 || nx > n || ny < 1 || ny > n)
                            continue;
                        if (visited[nx][ny] || paint[nx][ny] != paint[u.first][u.second])
                            continue;
                        Q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int paint[101][101]; //일반인이 보는 그림
    int paint_n[101][101]; //적록색약자가 보는 그림
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char color;
            cin >> color;
            if(color == 'R') {
                paint[i][j] = R;
                paint_n[i][j] = R;
            }
            else if(color == 'G'){
                paint[i][j] = G;
                paint_n[i][j] = R;
            }
            else if(color == 'B'){
                paint[i][j] = B;
                paint_n[i][j] = B;
            }
        }
    }

    cout << solve(paint) << " " << solve(paint_n);
    return 0;
}