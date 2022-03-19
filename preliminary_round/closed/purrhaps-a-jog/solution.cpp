#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t = 0;cin >> t;
    while (t--) {
        long n, m;
        cin >> n >> m;
        long sum = 0, k;
        k = n / m;
        long arr[10];

        for (int i = 0; i < 10; i++) {
            arr[i] = m * (i + 1) % 10;
            sum += arr[i];
        }

        long rem = k % 10;
        long ans = (k / 10) * sum;

        for (int i = 0; i < rem; i++) {
            ans += arr[i];
        }
        cout << ans << endl;
    }
}
