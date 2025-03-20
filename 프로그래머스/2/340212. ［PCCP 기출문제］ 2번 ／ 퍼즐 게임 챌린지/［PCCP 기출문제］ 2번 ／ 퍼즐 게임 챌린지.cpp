#include <string>
#include <vector>

using namespace std;

int diff;//현재 퍼즐의 난이도
int time_cur;// 현재 퍼즐의 소요 시간
int time_prev;// 이전 퍼즐의 소요 시간
int level;// 내 숙련도

int total_time = 0;


int solution(vector<int> diffs, vector<int> times, long long limit) 
{
    int answer = 0;

    
    int L = 1;
    int R = 100000;
    long long int totalTime=0;
    int mid = 0;
    
    
    while( L <= R)
    {
        mid = (L + R) / 2;  // 레벨
        totalTime = 0;
        
        for(int i =0; i< diffs.size(); ++i)
        { 
            totalTime += times[i];
            if(mid < diffs[i])
            {
                totalTime += (times[i-1] + times[i]) * (diffs[i] - mid);
            }
            
            if(totalTime > limit)
            {
                break;
            }
    
        }
        
        if(totalTime > limit)
        {
            L = mid + 1;     
        }
        else
            R =  mid - 1;    
    }
    
     answer = L;
    
    return answer;
}