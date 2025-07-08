#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];    // 5 4 3 2 1 
    }

    // 누적합 만들기
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + vec[i - 1];
    }
    int result = 0;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << "\n";
    }

    return 0; 
}