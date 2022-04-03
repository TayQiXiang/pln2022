#include <bits/stdc++.h>
using namespace std;
int n, m;
double f[1005][1005];
int main() {
    cin >> n >> m;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        double s = 0.5, t = 1.0 / 6.0;
        for (int j = 2; j <= i; j++) {
            s = s / 2;
            t = t / 2 + f[i - 1][j - 1] / 3;
        }
        f[i][i] = t / (1 - s);
        f[i][1] = f[i][i] / 2 + 1.0 / 6.0;
        for (int j = 2; j < i; j++)
            f[i][j] = f[i][j - 1] / 2 + f[i - 1][j - 1] / 3;
    }
    printf("%.9lf", f[n][m]);
    return 0;
}