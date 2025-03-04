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
int M = 0;
vector<int> v1;

int Array[21][21];
vector<int>TeamA;

int ans = 999999;

bool Selected[21];

int calculateAbility(const vector<int>& team) {
    int ability = 0;
    int teamSize = team.size();

    for (int i = 0; i < teamSize; i++) {
        for (int j = i + 1; j < teamSize; j++) {
            ability += Array[team[i]][team[j]];
            ability += Array[team[j]][team[i]];
        }
    }
    return ability;
}

void Solve(int num, int iTeamNum)
{
    if (iTeamNum == N / 2)
    {
        vector<int>TeamB;

        for (size_t i = 0; i < N; i++)
        {
            if (true == Selected[i])
                continue;

            TeamB.push_back(i);     // TeamA에서 선택햇는지 안햇는지를 어떻게 구별해?
        }


        // 차이 계산하고 
        int TeamA_Ability = calculateAbility(TeamA);
        int TeamB_Ability = calculateAbility(TeamB);

        ans = min(ans, abs(TeamB_Ability- TeamA_Ability));
        return;
    }

    
    for (size_t i = num; i < N; i++)
    {
        if (false == Selected[i])
        {
            Selected[i] = true;
            TeamA.push_back(i);
            Solve(i + 1, iTeamNum + 1);
        }
       
        TeamA.pop_back();
        Selected[i] = false;
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; ++j) 
        {
            int iValue = 0;
            cin >> iValue;

            Array[i][j] = iValue;
        }
    }
  
    int iTeamNum = N / 2;       // N이 6이라면 팀원은 3명이니까
    Solve(0, 0);


    cout << ans << '\n';

    return 0;
}

