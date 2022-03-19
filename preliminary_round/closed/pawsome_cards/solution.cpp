#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 0;
    cin >> t;
    char c;
    ll a, b;
    ll max_a = INT_MIN, max_b = INT_MIN;
    while (t--) {
        cin >> c >> a >> b;

        if (c == '+') {
            max_a = max(min(a,b), max_a);
            max_b = max(max(a,b), max_b);
        } else {
            if ((max_a <= a && max_b <= b) || (max_a <= b && max_b <= a)) {
                cout << "1" << endl;
            } else
                cout << "0" << endl;
        }
    }
}
