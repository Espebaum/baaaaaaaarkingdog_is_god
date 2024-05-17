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

int N;
vector<pair<int,int>>tri[5050];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            tri[i].push_back({j, 0});
        }
    }

    for (int i = 1; i <= N; i += 2) {
        for (int j = 0; j < tri[i].size(); j += 1) {
            if (tri[i][j].second != 1) {
                if (tri[i+1][j].second != 1 && tri[i+1][j+1].second != 1) 
                {
                    tri[i][j].second = 1;
                    tri[i+1][j].second = 1; 
                    tri[i+1][j+1].second = 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < tri[i].size(); j++) {
            if (tri[i][j].second != 1) {
                cout << 0; return 0;
            }
        }   
    }
    cout << 1;
    return 0;
}