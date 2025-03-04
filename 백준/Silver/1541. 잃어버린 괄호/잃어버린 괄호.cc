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

string ans = "";

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> ans;
    
    string temp = "";
    bool isminus = false;

    int Result = 0;

    for (size_t i = 0; i <= ans.size(); i++)
    {
        if ('+' == ans[i] || '-' == ans[i] || '\0' == ans[i])
        {
            if (true == isminus)
            {
                Result -= stoi(temp);
            }
            else
                Result += stoi(temp);

            temp = "";

            if ('-' == ans[i])
                isminus = true;

        }
        else
        {
            temp += ans[i];
        }
    }


    cout << Result;


    return 0;
}

