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
#include <sstream>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int tc;

void    reverse()

void    discard()

void    reverseDiscard(vector<int> v, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R')
        {
            revserse
        }
    }
}

void    solve()
{
    string  s; cin >> s;
    int size; cin >> size;

    string  tmp; cin >> tmp;
    string  arr(tmp.begin() + 1, tmp.end() - 1); // 헉!!
    deque<int> d;

    string n = "";
    for (int i = 0; i < arr.length(); i++) 
    {
        if (arr[i] == ',')
        {
            if (n != "")
            {
                int number = stoi(n);
                d.push_back(number);
            }
            n = "";
        }
        else
        {
            n.push_back(arr[i]);
            if (i == arr.size() - 1)
            {
                int number = stoi(n);
                d.push_back(number);
            }
        }
    }

    reverseDiscard(v, s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;

    while (tc--)
        solve();

    return 0;
}