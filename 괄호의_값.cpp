#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

string  s;
int sum;
stack<char> sc;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[')
            sc.push(s[i]);
        else
        {

        }
    }

    return 0;
}