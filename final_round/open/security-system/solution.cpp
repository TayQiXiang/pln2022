#include <iostream>
using namespace std;
int n, a, b;
unsigned long long P[502][502], ans;
long long mod = 1000000007;

void pascal(int n) {
    for (int i = 0; i <= n; ++i) P[i][0] = P[i][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            P[i][j] = (P[i - 1][j] + P[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> a >> b;
    pascal(n + max(a, b));

    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            ans += (P[n + i - 1][n - 1] * P[n + j - 1][n - 1]) % mod;
            ans %= mod;
        }
    }

    cout << ans % mod << endl;
    return 0;
}
