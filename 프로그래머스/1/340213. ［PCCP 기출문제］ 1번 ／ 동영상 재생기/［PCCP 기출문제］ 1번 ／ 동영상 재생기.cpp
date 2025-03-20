#include <string>
#include <vector>

using namespace std;
/*
 동영상 길이를 나타내는 문자열 video_len
 기능이 수행되기 직전의 재생위치 pos
 오프닝 시작 시각 op_start
 오프닝 끝나는 시간 op_end
*/


string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
  
    int iMin = stoi(pos.substr(0,2)); 
    int iSec = stoi(pos.substr(3,2));
    
    int temp = (iMin * 60) + iSec; 
    
    
    int totalLen = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
    int opStart = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3, 2));
    int opEnd = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));
    
     if (opStart <= temp && opEnd >= temp)
        {
            temp = opEnd;
        }
    
 for (string com : commands)
    {
        if (com.compare("prev") == 0)
        {
            if (temp - 10 > 0)
                temp -= 10;
            else
                temp = 0;
        }
        else if (com.compare("next") == 0)
        {
            if (temp + 10 < totalLen)
                temp += 10;
            else
                temp = totalLen;
        }

        if (opStart <= temp && opEnd >= temp)
        {
            temp = opEnd;
        }
    }
    
     answer = (temp / 60 < 10 ? "0" + to_string(temp / 60) : to_string(temp / 60)) + ":" + (temp % 60 < 10 ? "0" + to_string(temp % 60) : to_string(temp % 60));
    
    return answer;
}