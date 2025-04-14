#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int n = sequence.size();
    int start =0;
    int end= 0;
    int sum = sequence[0];
    int minLen = n + 1;
    
   answer = {0, n-1};  

    while(start < n && end < n)
    {
        if(sum < k)
        {
            ++end;
            sum += sequence[end];
        }
        else if (sum > k)
        {
            sum -= sequence[start];
            start++;
        }
        else if (sum == k)
        {
            if ((end - start + 1) < minLen) {
                minLen = end - start + 1;
                answer = {start, end};
            }
            // sum == k일 때도 start를 옮겨서 더 짧거나 앞선 구간을 탐색
            sum -= sequence[start];
            start++;

        }
        
    }
    
    
    
    return answer;
}