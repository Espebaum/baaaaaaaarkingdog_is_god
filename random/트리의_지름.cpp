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
using namespace std;

int N;
vector<pair<int,int>> adj[10010];
int dist[10010];
vector<int> ans;

int find(int k, int mx)
{
    for (int i = 0; i <= N; i++) {
        if (vis[adj[k][i].first]) {
            mx += adj[k][i].second;
            dist
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int p, c, w; cin>>p>>c>>w;
        adj[p].push_back({c, w});
    }

    for (int i = 0; i < N; i++) {
        find(i);
    }
    cout << *max_element(ans.begin(), ans.end());

    return 0;
}