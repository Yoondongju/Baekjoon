#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;

    unordered_map<string ,int> yearning_map;

    for (size_t i = 0; i < name.size(); i++)
    {
        yearning_map.insert(make_pair(name[i], yearning[i]));
    }

    int sum = 0;

    for (size_t i = 0; i < photo.size(); i++)
    {
        sum = 0;
        for (auto& pho : photo[i])
        {
            if (yearning_map.count(pho))
            {
                sum += yearning_map[pho];
            }
        }
        answer.push_back(sum);
    }


    return answer;
}