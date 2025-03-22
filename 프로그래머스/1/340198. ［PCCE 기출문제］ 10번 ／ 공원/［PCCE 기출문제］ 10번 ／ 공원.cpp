#include <string>
#include <vector>
#include <algorithm>

using namespace std;





int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;

    sort(mats.begin(), mats.end(), greater<int>());

    for (size_t i = 0; i < mats.size(); i++)
    {
        int n = mats[i];       

        for (size_t j = 0; j < park.size(); j++)
        {
            for (size_t k = 0; k < park[j].size(); k++)
            {              
                bool bCheck = true;
                if (park[j][k] != "-1") 
                    continue;

                for (size_t y = 0; y < n; y++)
                {                
                    for (size_t x = 0; x < n; x++)
                    {
                        if (((j + y) >= park.size() || (k + x) >= park[0].size()) ||
                            "-1" != park[j + y][k + x])
                        {
                            bCheck = false;
                            break;
                        }  
                    }

                    if (false == bCheck)
                    {
                        break;
                    }
                }

                if (true == bCheck)
                {
                    return n;                    
                }
            }
        }
    }

    return answer;
}
