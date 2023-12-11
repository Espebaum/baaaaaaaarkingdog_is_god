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
stack<int>  s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;
    int cur = 1;
    vector<char> ans;

    for (int i = 0; i < tc; i++) {
        int num; cin >> num;
        for (int i = cur; i <= num; i++) {
            ans.push_back('+');
            s.push(cur);
            cur++;
        }
        if (s.top() != num) {
            cout << "NO";
            return 0 ;
        }
        else {
            ans.push_back('-');
            s.pop();        
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout <<ans[i] << '\n';
    } 

    return 0;
}