#include <string>
#include <vector>

using namespace std;
int fatigueTable[3][3] = {
    {1, 1, 1},      // 다이아 곡괭이
    {5, 1, 1},      // 철 곡괭이
    {25, 5, 1}      // 돌 곡괭이
};

int minFatigue = 9999;

int getMineralIdx(const string& mineral) {
    if (mineral == "diamond") return 0;
    if (mineral == "iron") return 1;
    return 2; // "stone"
}

void dfs(vector<int> picks, const vector<string>& minerals, int index, int fatigue) {
    if (index >= minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)) {
        minFatigue = min(minFatigue, fatigue);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (picks[i] == 0) continue;

        vector<int> newPicks = picks;
        newPicks[i]--;

        int newFatigue = fatigue;

        for (int j = 0; j < 5 && (index + j) < minerals.size(); ++j) {
            int mineralIdx = getMineralIdx(minerals[index + j]);
            newFatigue += fatigueTable[i][mineralIdx];
        }

        dfs(newPicks, minerals, index + 5, newFatigue);
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    minFatigue = 9999;
    dfs(picks, minerals, 0, 0);
    return minFatigue;
}