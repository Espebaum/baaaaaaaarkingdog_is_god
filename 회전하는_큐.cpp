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

int N, M, sum;
deque<int>  d;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N; cin >> M;

    for (int i = 1; i <= N; i++)
    {
        d.push_back(i);
        v.push_back(i);
    }

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        int to_find = v[num - 1];

        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] == to_find)
                break;
            sum1++;
        }
        for (int i = d.size(); i >= 0; i--)
        {
            if (d[i] == to_find)
                break;
            sum2++;
        }

        if (sum1 < sum2) 
        {
            while (d.front() != to_find)
            {
                int front = d.front();
                d.pop_front();
                d.push_back(front);
                sum++;
            }
        }
        else
        {
            while (d.front() != to_find)
            {
                int back = d.back();
                d.pop_back();
                d.push_front(back);
                sum++;
            }
        }
        d.pop_front();
    }
    cout << sum;
    return 0;
}