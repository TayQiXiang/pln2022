#include <bits/stdc++.h>
using namespace std;

int n, m;
struct edge {
    int next, to;
} e[1000];
int rt, head[1000], tot, val[1000], dp[1000][1000];
void add(int x, int y) {
    e[++tot].next = head[x];
    head[x] = tot;
    e[tot].to = y;
}
void dfs(int u, int t) {
    if (t <= 0) return;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        for (int k = 0; k < t; ++k)
            dp[v][k] = dp[u][k] + val[v];
        dfs(v, t - 1);
        for (int k = 1; k <= t; ++k)
            dp[u][k] = max(dp[u][k], dp[v][k - 1]);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d%d", &a, &val[i]);
        if (a)
            add(a, i);
        if (!a) add(0, i);
    }
    dfs(0, m);
    printf("%d", dp[0][m]);
}