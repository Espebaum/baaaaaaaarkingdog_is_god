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

int V, E, K;
vector<pair<int,int>>adj[20006];
int dist[20006];

class compare
{
    public:
        bool operator() (pair<int,int>a, pair<int,int>b) {
            return a.second > b.second;
        } // 최소 힙
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pq;
    cin>>V>>E>>K;

    for(int i = 0; i < E; i++) {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    fill(dist, dist + V + 1, INF);

    dist[K] = 0;
    pq.push({K, dist[K]});
    // 정점, 거리
    while (!pq.empty())
    {
        pair<int,int>cur = pq.top(); pq.pop();
        // cur.first = node;
        // cur.second = dist;
        if (dist[cur.first] != cur.second)
            continue ;
        for (int i = 0; i < adj[cur.first].size(); i++) {
            pair<int,int>nxt = adj[cur.first][i];
            // nxt.first = newNode;
            // nxt.second = newDist;
            if (dist[nxt.first] <= dist[cur.first] + nxt.second)
                continue;
            dist[nxt.first] = dist[cur.first] + nxt.second;
            pq.push({nxt.first, dist[nxt.first]});
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}