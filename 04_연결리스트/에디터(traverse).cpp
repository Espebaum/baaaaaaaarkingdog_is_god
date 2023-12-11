#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << (char) dat[cur];
        cur = nxt[cur];
    }
}

int main(void)
{
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    string  s;
    cin >> s;

    int cursor = 0;
    for (int i = 0; i < s.length(); i++) {
        insert(cursor, s[i]);
        cursor++;
    }

    int num;
    cin >> num;

    while (num--) {
        char    c;
        cin >> c;
        if (c == 'P') {
            char    w;
            cin >> w;
            insert(cursor, w);
            cursor = nxt[cursor];
        }
        else if (c == 'L') {
            if (pre[cursor] != -1)
                cursor = pre[cursor];
        }
        else if (c == 'D') {
            if (nxt[cursor] != -1)
                cursor = nxt[cursor];
        }
        else if (c == 'B') {
            if (pre[cursor] != -1) {
                erase(cursor);
                cursor = pre[cursor];
            }
        }
    }
    traverse();
}