#include <bits/stdc++.h>
using namespace std;

double dfs(double x, double y, int n) {        // recursive search
    if (n == 1) return max(x, y) / min(x, y);  // base case, return the ratio of long side to short side
    double ans = 9999999999, mx = x / n, my = y / n;
    for (int i = 1; i < n; i++) {
        double horizontal_cut = max(dfs(mx * i, y, i), dfs(x - mx * i, y, n - i));
        double vertical_cut = max(dfs(x, my * i, i), dfs(x, y - my * i, n - i));
        ans = min(ans, min(horizontal_cut, vertical_cut));  // check horizontal and vertical cut which one is better
    }
    return ans;
}
int main() {
    int x, y, n;
    cin >> x >> y >> n;
    printf("%.6lf", dfs(x, y, n));
}
