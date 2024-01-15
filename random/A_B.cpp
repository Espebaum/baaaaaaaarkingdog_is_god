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
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

long long A, B;
vector< pair<long long, long long> > vp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;

    queue<long long> q;
    q.push(A);
    vp.push_back(make_pair(A, 0));
    long long dist = 0;

    while (!q.empty())
    {
        long long cur = q.front(); q.pop();
        long long dist = vp.back().second;
        if (cur == B)
            break ;
        for (int dir = 0; dir < 2; dir++)
        {
            long long newcur;
            if (dir == 0)
                newcur = cur * 2;
            else
                newcur = 10 * cur + 1;
            if (newcur > B) {
                continue ;
            }
            vp.push_back(make_pair(newcur, dist + 1));
            q.push(newcur);
        }
    }    
    
    for (int i = 1; i < vp.size(); i++) {
        cout << "cur : " << vp[i].first << " dist : " << vp[i].second << '\n';
    }
    for (int i = 0; i < vp.size(); i++) {
        if (B == vp[i].first) {
            vp[i].second++;
            cout << vp[i].second; return 0;
        }
    }
    cout << -1;
    return 0;
}