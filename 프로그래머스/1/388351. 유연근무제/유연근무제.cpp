#include <string>
#include <vector>

using namespace std;
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < schedules.size(); ++i) {
        bool match = true;
        int time = schedules[i] + 10;
        if (time % 100 > 59) time += 40;

        for (int j = 0; j < 7; ++j) {
            int day = (startday + j) % 7;

            if (day != 6 && day != 0 && timelogs[i][j] > time) {
                match = false;
                break;
            }
        }

        if (match) {
            ++answer;
        }
    }
    return answer;
}


