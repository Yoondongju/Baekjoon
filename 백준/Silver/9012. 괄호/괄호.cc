
#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#pragma warning(disable:4996)

typedef unsigned int uint;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0;

	cin >> n;

	

	for (size_t i = 0; i < n; i++)
	{
		string strTest;
		cin >> strTest;

		// 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.

		if (2 <= strTest.length() && 50 >= strTest.length())
		{
			stack<char> strStack;
			bool bCheck = false;

			for (size_t i = 0; i < strTest.length(); i++)
			{
				if ('(' == strTest[i])
					strStack.push(strTest[i]);
				else
				{
					if (!strStack.empty())
					{
						if ('(' == strStack.top() && ')' == strTest[i])
							strStack.pop();
					}
					else
					{
						cout << "NO" << "\n";
						bCheck = true;
						break;
					}

				}
			}


			if (false == bCheck)
			{
				if (strStack.empty())
					cout << "YES" << "\n";
				else
					cout << "NO" << "\n";
			}
		}
	}



	return 0;
}


