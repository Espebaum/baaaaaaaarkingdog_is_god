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

int tc;

void    solve(string s) 
{
    list<char>  l;
    list<char>::iterator    it = l.begin();

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '<') {
            if (it != l.begin())
                it--;
        }
        else if (s[i] == '>') {
            if (it != l.end())
                it++;
        }
        else if (s[i] == '-') {
            if (it != l.begin()) { // 예외처리 필요
                it--;
                it = l.erase(it);
            }
        }
        else {
            l.insert(it, s[i]);
        }
    }
    
    for (list<char>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it;
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;
    
    while (tc--) {   
        string  s;
        cin >> s;
        solve(s);
        cout << endl;
    }

    return 0;
}