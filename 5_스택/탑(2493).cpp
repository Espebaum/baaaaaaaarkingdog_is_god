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

int N;
stack< pair<int,int> > s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        while (s.size() && s.top().first <= num)
            s.pop();
        if (s.empty()) {
            cout << '0' << ' ';
        } else {
            cout << s.top().second << ' ';
        }
        s.push(make_pair(num, i));
    }

    return 0;
}