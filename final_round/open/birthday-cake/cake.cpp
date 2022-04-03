#include <bits/stdc++.h>
using namespace std;
double x, y, n;
double dfs(double x, double y, double d) {
    double ans = 1000000000;
    if (d == 1) {
        if (x < y) swap(x, y);
        return x / y;
    }
    double mx = x / d, my = y / d;
    double ans1, ans2;
    for (int i = 1; i <= d / 2; i++) {
        ans1 = max(dfs(mx * i, y, i), dfs(x - mx * i, y, d - i));
        // i/d area split into 1，（d-i)/d area split into d-i
        ans2 = max(dfs(x, my * i, i), dfs(x, y - my * i, d - i));
        ans = min(ans, min(ans1, ans2));
    }
    return ans;
}

int main() {
    scanf("%lf%lf%lf", &x, &y, &n);
    printf("%.6lf", dfs(x, y, n));
}