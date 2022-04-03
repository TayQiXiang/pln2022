#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;
vector<bool> prime(10000005, true);
void solve() {
    ll n;
    cin >> n;
    int c = 2;
    ll sum = 0;
    ll largest_fac = -1;
    while (n > 1) {
        if (n % c == 0) {
            n /= c;
            sum += c;
            largest_fac = c;
        } else {
            c++;
        }
    }
    // cout<<sum<<" "<<largest_fac<<endl;
    string ans = (prime[sum % largest_fac]) ? "YES" : "NO";
    cout << ans << endl;
}

// prime sieve
void sieve() {
    int n = 10000000;
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    sieve();
    int t = 0;
    cin >> t;
    while (t--) solve();
}