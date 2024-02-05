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

int N, M;
vector<pair<int,int>>adj[1010];
int dist[1010];
int st, en;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int p,c,w;cin>>p>>c>>w;
        adj[p].push_back({w,c});
    }
    cin >> st >> en;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    fill(dist,dist+1010,INF);
    dist[st] = 0;
    pq.push({dist[st], st});
    while (!pq.empty())
    {
        pair<int,int>cur = pq.top();pq.pop();
        if (dist[cur.second] != cur.first)
            continue;
        for (int i = 0; i < adj[cur.second].size(); i++) {
            pair<int,int>nxt = adj[cur.second][i];
            if (dist[nxt.second] >= dist[cur.second] + nxt.first) {
                dist[nxt.second] = dist[cur.second] + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
    cout << dist[en];
    return 0;
}