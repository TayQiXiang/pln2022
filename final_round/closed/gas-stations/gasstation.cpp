#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n], b[n];
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    int tank = 0, total = 0, start = 0;
    forn(i, n) {
        int current = a[i] - b[i];
        tank += current;
        total += current;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    total < 0 ? cout << -1 << endl : cout << start << endl;
}