#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int arr1[] = {1, 52, 48};
int arr2[] = {50, 42};
int arr3[] = {4, 13, 63, 87};


int func2(int arr[], int n)
{
    int a[101];
    fill(a, a+101, 0);
    for (int i = 0; i < n; i++) {
        if (a[100 - arr[i]])
            return 1;
        a[arr[i]] = 1;
    }
    return 0;
}

int main()
{
    cout << func2(arr1, 3) << endl;
    return (0);
}