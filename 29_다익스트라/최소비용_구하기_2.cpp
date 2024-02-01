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

int n, m;
int start, en;
vector<pair<int,int>> adj[1010];
int d[1010];
int pre[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    fill(d, d + n + 1, INF);

    for (int i = 0; i < m; i++) 
    {
        int p,c,w; cin>>p>>c>>w;
        adj[p].push_back({w, c});    
    }
    cin >> start >> en;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    // 거리, 정점;
    
    d[start] = 0;
    pq.push({d[start], start});

    while (!pq.empty())
    {
        pair<int,int>cur = pq.top(); pq.pop();
        // cur.first -> dist, cur.second => node;
        // d[cur.second] === cur.first
        if (d[cur.second] != cur.first)
            continue;
        for (int i = 0; i < adj[cur.second].size(); i++) {
            pair<int,int>nxt = adj[cur.second][i];
            // nxt.first -> dist, nxt.second => node;
            // d[nxt.second] === nxt.first
            if (d[nxt.second] <= cur.first + nxt.first)
                continue;
            d[nxt.second] = cur.first + nxt.first;
            pq.push({d[nxt.second], nxt.second});
            pre[nxt.second] = cur.second;
        }
    }
    cout << d[en] << '\n';

    vector<int> path;
    int cur = en;
    while (cur != start) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }
    return 0;
}