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

using namespace std;

#pragma warning(disable:4996)

typedef unsigned int uint;

int N;
int M;

unordered_map<string, string> umap;

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin >> N;       // 저장된 사이트 주소 수
    cin >> M;       // 비밀번호 찾으려는 사이트 주소 수


    for (size_t i = 0; i < N; i++)
    {
        string site;
        string password;

        cin >> site;
        cin >> password;

        umap.insert(make_pair(site, password));
    }


    for (size_t i = 0; i < M; i++)
    {
        string site;
        cin >> site;


        auto pair = umap.find(site);
        cout << (*pair).second << '\n';
    }

   

    return 0;
}

