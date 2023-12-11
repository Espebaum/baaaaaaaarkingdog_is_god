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

stack<int>  s;
int tc;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;

    while (tc--) 
    {
        string  str;
        cin >> str;
        if (str == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (str == "pop")
        {
            if (s.empty()) {
                cout << -1 << '\n';
            } else {
                int n = s.top();
                s.pop();
                cout << n << '\n';
            }
        }
        else if (str == "size")
        {
            cout << s.size() << '\n';
        }
        else if (str == "empty") 
        {
            if (s.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
        {
            if (s.empty())
                cout << -1 <<'\n';
            else
                cout << s.top() << '\n';
        }
    }
    return 0;
}