#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if (sum < 0)
            ans -= sum;
        else
            ans += sum;
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 0;
    cin >> t;
    while (t--) solve();
}