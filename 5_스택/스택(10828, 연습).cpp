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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)s
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos] = x;
    pos++;
}

void pop() {
    if (pos != 0)
        pos--;
}

int size() {
    return pos;
}

int top() 
{
    if (pos != 0)
    {
        int tmp = pos - 1;
        return (dat[tmp]);
    }
    return -1;
}

int empty() {
    if (pos != 0)
        return 0;
    return 1;
}

int main(void) {
    int tc;
    cin >> tc;

    while (tc--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num;
            cin >> num;
            push(num);
        }
        else if (s == "pop")
        {
            int t = top();
            pop();
            cout << t << '\n';
        }
        else if (s == "size")
        {
            cout << size() << '\n';
        }
        else if (s == "empty")
        {
            cout << empty() << '\n';
        }
        else if (s == "top") 
        {
            cout << top() << '\n';
        }
    }
}