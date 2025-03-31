#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;


vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string,int> answer;

    for (int i = 0; i < players.size(); i++) {
        answer[players[i]] = i;
    }



    for (size_t i = 0; i < callings.size(); i++)
    {
        auto iter = answer.find(callings[i]);

        if (iter != answer.end())
        {
            swap(players[iter->second], players[iter->second - 1]);

            answer[players[iter->second]] = iter->second;

            answer[players[iter->second - 1]] = iter->second - 1;
        }

    }

    return players;
}
