#include <string>
#include <vector>

using namespace std;


int dh[4] = { 0,0,1,-1 };
int dw[4] = { 1,-1,0,0 };



int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    int n = board.size();
    int count =0;  // 같은 색으로 색칠된 칸의 개수


  

   

    for (size_t i = 0; i < 4; i++)
    {
        string s = board[h][w];

        int nh = h + dh[i];
        int nw = w + dw[i];

        if (nh >= 0 && nh < n  && nw >= 0 &&  nw < n)
        {
            if (s == board[nh][nw])
                count++;
        }
    }




    return count;
}


