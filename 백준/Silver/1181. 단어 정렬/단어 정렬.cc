#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>
#include <cmath>

using namespace std;

#pragma warning(disable:4996)

typedef unsigned int uint;

int N;
int M;


bool compare(const string& a, const string& b)
{
    if (a.size() < b.size())        // 짧은게 먼저오도록하려면 왼쪽인자가 더 짧다면 true를해야댐
        return true;
    else if (a.size() == b.size())
    {
        // 사전순으로 
        if (a < b)
            return true;
        
        return false;
    }
    return false;
}


int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

   
    int n;
    cin >> n;
    
    vector<string> strBuffer;
    strBuffer.reserve(n);


    for (size_t i = 0; i < n; i++)
    {
        char word[51];
        cin >> word;

        strBuffer.push_back(word);
    }

    sort(strBuffer.begin(), strBuffer.end(), compare);

    strBuffer.erase(unique(strBuffer.begin(), strBuffer.end()), strBuffer.end());

    for (size_t i = 0; i < strBuffer.size(); i++)
    {
        cout << strBuffer[i] << "\n";
    }

  

    return 0;
}

