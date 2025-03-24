#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int, int>& v1, pair<int, int>& v2)
{
   return v1.second < v2.second;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;


    // x축으로 평행하는 폭격마시일은 s~e 범위를가짐
    // y축으로 수평하는 요격미사일은 s와 e에선 요격미사일로 요격 할수없다

    // 요격미사일의 최솟값은 ?


    vector <pair<int,int>> v1;

    for (size_t i = 0; i < targets.size(); i++)
    {
        int s = targets[i][0];
        int e = targets[i][1];
        v1.push_back(make_pair(s, e));
    }


    sort(v1.begin(), v1.end(), compare);

    int end = -1;  // 요격 미사일의 기준점

    for (const auto& missile : v1) {
        int s = missile.first;
        int e = missile.second;

        // 현재 요격 미사일로 못 막으면 새로운 요격 미사일 추가
        if (s >= end) {
            answer++;
            end = e;
        }
    }

    return answer;
}
