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
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int T;
stack<int>st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin>>T;
    while (T--)
    {
        int flag = -1;
        int value = -1;
        string s;cin>>s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '!') {
                if (flag == 1) {
                    st.pop();
                    st.push('1');
                } else if (flag == 0) {
                    st.pop();
                    st.push('1');
                } else
                    st.push(s[i]);
            } else if (s[i] == '0') {
                flag = 0;
                st.push(s[i]);
            } else { // s[i] == '1';
                flag = 1;
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            if (st.empty()) {
                cout << c; 
                break ;
            } else {
                if (c == '0') {
                    st.pop();
                    st.push('1');
                } else {
                    st.pop();
                    st.push('0');
                }
            }
        }
        cout << '\n';
    }
    return 0;
}